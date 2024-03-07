#include<stdio.h>
int main(){
    float n;
    char c;
    scanf("%f%c", &n, &c);
    printf("n_is_%f\n", n);
    printf("c_is_%c\n", c);
    // char str[] = "abcdefghijklmnopqrstuvwxyz";
    // printf("%40s\n", str);
    // printf("%-40s\n", str);
    // printf("%20.5s\n", str);
    // printf("%-20.5s\n", str);
}
// function to check even or not 
// void checkEvenOrNot(int num) 
// {
//     if (num % 2 == 0) 
//         // jump to even 
//         goto even; 
//     else
//         // jump to odd 
//         goto odd; 

// even: 
//     printf("%d is even", num); 
//     // return if even 
//     return; 
// odd: 
//     printf("%d is odd", num); 
// } 

// int main() 
// { 
//     int num = 26; 
//     checkEvenOrNot(num); 
//     return 0; 
// }