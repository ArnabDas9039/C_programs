#include<stdio.h>
int main(){
    float n;
    scanf("%6f",&n);
    printf("n_is_%0.2f",n);
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