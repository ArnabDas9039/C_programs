// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     char* A;
//     A = (char*) malloc(sizeof(char));
//     int i = 0;
//     printf("Enter the sentence: ");
//     while(1){
//         char f;
//         scanf("%c", &f);
//         if(f == '\n'){
//             break;
//         }
//         A[i] = f;
//         i++;
//         A = (char*) realloc(A, i * sizeof(char));
//         printf("%d",sizeof(A));
//     }
//     printf("The sentence: ");
//     for(int j = 0; j < i; j++){
//         printf("%c", A[j]);
//     }
//     // printf("%d",i-1);
//     //hello hi this is cs50, ki hocche ami o jani naa dekhte hobe kon character taa problem korche Sunrit gandu
//     //Wave files are larger in size as compared to new audio file formats such as MP3 which uses lossy compression to reduce the file size while maintaining the same audio quality. However, WAV files can be compressed using Audio Compression Manager (ACM) codecs. There are several APIs and applications available that can convert WAV files to other popular audio file formats.
//     return 0;
// }
/***********************************
Section : 6
Machine No. : 59
Roll No. : 23AE30023
Name : Tridibesh Sarkar
Assignment No : 6
Description :
************************************/
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int string_order(char* s){
    int g = 0;
    for(int i = 0;i < strlen(s);i++){
        g = 0;
        if((int)s[i + 1] == (int)s[i] + 1)
            g = 1;
    }
    return g;
}
int sub_string_order(char* s, int k){
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if((strlen(s) - i) >= k){
            char* l;
            l = (char*)malloc((k + 1) * sizeof(char));
            for(int j = 0;j < k;j++){
                l[j] = s[j + i];
                printf("%c", l[j]);
            }
            printf("\n");
            l[k] = '\0';
            if(string_order(l)){
                count++;
            }
            free(l);
        }
    }
    return count;
}
int main(){
    char* A;
    int b, p;
    char ch;
    printf("Enter the size of string: ");
    scanf("%d", &b);
    A = (char*)malloc((b + 1) * sizeof(char));
    for(int i = 0;i < b;i++){
        scanf("%c", &ch);
        A[i] = ch;
    }
    A[b] = '\0';
    printf("Enter a no. less than size of string: ");
    scanf("%d", &p);
    printf("%d", sub_string_order(A, p));
    return 0;
}