#include<stdio.h>
#include<stdlib.h>

typedef struct map{
    int key;
    int value;
}map;

void display(map* a){
    printf("Key:\t\tValue\n");
    for(int i = 0; i < 10; i++){
        printf("%d:\t%d\n", a[i].key, a[i].value);
    }
    return;
}

int linear_search(map* a, int key){
    for(int i = 0; i < 10; i++){
        if(a[i].key == key){
            return i;
        }
    }
    return -1;
}

void set_key_value(map* a){
    int key;
    int value, index;
    while(1){
        printf("\nEnter the key: ");
        scanf("%d", &key);
        fflush(stdin);
        if(linear_search(a, key) != -1){
            printf("Key already exists.\n");
        }
        else{
            for(int i = 0; i < 10; i++){
                if(a[i].key == __INT32_MAX__){
                    a[i].key = key;
                    index = i;
                    break;
                }
            }
            printf("\nEnter the value: ");
            scanf("%d", &a[index].value);
            return;
        }
    }
    return;
}
void get_value(map* a){
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    if(linear_search(a, key) != -1){
        printf("The value is: %d\n", a[linear_search(a, key)].value);
    }
    else{
        printf("Key not Found\n");
    }
    return;
}
void delete_key(map* a){
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    if(linear_search(a, key) != -1){
        a[linear_search(a, key)].key = __INT32_MAX__;
        a[linear_search(a, key)].value = __INT32_MAX__;
        printf("Key removed\n");
    }
    else{
        printf("Key not Found\n");
    }
}
void clear(map* a){
    for(int i = 0; i < 10; i++){
        a[i].key = __INT32_MAX__;
        a[i].value = __INT32_MAX__;
    }
}
int main(){
    map a[10];
    int choice;
    int key;
    clear(a);
    while(1){
        printf("\n\nHASHMAP MENU\n");
        printf("\n Enter 0 to display ");
        printf("\n Enter 1 to set pair");
        printf("\n Enter 2 to get value");
        printf("\n Enter 3 to search for key ");
        printf("\n Enter 4 to remove ");
        printf("\n Enter 5 to clear the map ");
        printf("\n Enter 10 to exit\n ");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice){
        case 0:
            display(a);
            break;
        case 1:
            set_key_value(a);
            break;
        case 2:
            get_value(a);
            break;
        case 3:
            printf("Enter the key: ");
            scanf("%d", &key);
            fflush(stdin);
            if(linear_search(a, key) != -1){
                printf("Key exists\n");
            }
            else{
                printf("Key doesn't exist\n");
            }
            break;
        case 4:
            delete_key(a);
            break;
        case 5:
            clear(a);
            break;
        case 6:
            exit(1);
        default:
            printf("\nPlease enter a valid choice.");
        }
    }
    return 0;
}