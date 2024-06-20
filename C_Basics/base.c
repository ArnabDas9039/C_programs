#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int main(){
//     int a0 = 1;
//     int a1[] = {1,1,1};
//     int a2[][] = {{1,1,1},{1,1,1},{1,1,1}};
//     int a3[][][] = {{{1,1,1},{1,1,1},{1,1,1}},{{1,1,1},{1,1,1},{1,1,1}},{{1,1,1},{1,1,1},{1,1,1}}};
//     for(int i = 0; i < 3; i++){
//         printf("%d ",a1[i]);
//     }
// }
int main(){
    // int a = sizeof(char);
    // int b = 2;
    // int d = 1;
    char *a = "Arnab";
    char *b = "Ankit";
    printf("%d", strcmp(b, a));
    // char *maze = "In mathematics, a tensor is an algebraic object that describes a multilinear relationship between sets of algebraic objects related to a vector space. Tensors may map between different objects such as vectors, scalars, and even other tensors. There are many types of tensors, including scalars and vectors (which are the simplest tensors), dual vectors, multilinear maps between vector spaces, and even some operations such as the dot product. Tensors are defined independent of any basis, although they are often referred to by their components in a basis related to a particular coordinate system; those components form an array, which can be thought of as a high-dimensional matrix. Tensors have become important in physics because they provide a concise mathematical framework for formulating and solving physics problems in areas such as mechanics stress, elasticity, quantum mechanics, fluid mechanics, moment of inertia, electrodynamics electromagnetic tensor, Maxwell tensor, permittivity, magnetic susceptibility, general relativity stress energy tensor, curvature tensor, and others. In applications, it is common to study situations in which a different tensor can occur at each point of an object; for example the stress within an object may vary from one location to another. This leads to the concept of a tensor field. In some areas, tensor fields are so ubiquitous that they are often simply called tensors. Tullio Levi-Civita and Gregorio Ricci-Curbastro popularised tensors in 1900 continuing the earlier work of Bernhard Riemann, Elwin Bruno Christoffel, and others as part of the absolute differential calculus. The concept enabled an alternative formulation of the intrinsic differential geometry of a manifold in the form of the Riemann curvature tensor.";
    // printf("sizeof maze is %d and %d\n",sizeof(maze),strlen(maze));
    // puts(maze);
    // printf("\n");
    // for(int i = 0; i < 4096; i++){
    //     printf("%c",maze[i]);
    // }
    // char* maze = malloc(sizeof(char));
    // int c;
    // int c = d / b;
    // char *c /*= "whiteredblueyellow"*/;
    //char c = 'a';
    //printf("Player 1: ");
    // scanf("%c",c);
    // printf("Player 2: ");
    // printf("%d",sizeof(c));
    // scanf("%s",c);
    // fgets(c, 10, stdin);
    // printf("%s\n",c);
    // for(int i=0; i<strlen(c); i++){
    //     printf("%c",c{i});
    //     printf("%c",c);
    // }
    // return 0;
    // char *c = "India";
    // int n = strlen(c);
    // *c = c{n};
    // printf("%c\n",c);
    // c++;
    // printf("%d\n",c);
    // printf("\n");
    // for(int i=0; i<sizeof(d); i++){
    //     printf("%c",d{i});
    // }
    //int a{4} = {0,1,2,3};
    // char b = '0';
    // int c = 4, b=2;
    // b = b/c;
    // int *d = malloc(2 * sizeof(int));
    // *d = 1;
    // *(d+1) = 3;
    // if(c == 4){
    //     //printf("%d\n",c);
    // }
    // if(4){
    //     printf("4\n");
    // }
    // int j;
    // int t = (scanf("%d",&j)+1,printf("%d\n",j));
    // int t = (3,4,5,6);
    // printf("%d\n",t);
    // return 0;
}
// int main()
// {
//     int n = 11;
//     for(int i = 0, j = n; i <= n, j > 0; i++, j--){
//         printf("%d %d\n",i,j);
//     }
// }
// int main()
// {
//     int a, b;
//     char c;
//     printf("Enter the values of a, b, c:");
//     scanf("%2d%d%c", &a, &b, &c);
//     printf("a = %d\n b = %d\n c = %c\n", a, b, c);
//     // scanf("%2d%3d%c%c", &a, &b, &c, &c);
//     // printf("a = %d\n b = %d\n c = %c\n", a, b, c);
//     return 0;
// }
// int foo(int x, int y, int z, int w){
//     printf("%d, %d, %d, %d\n",x,y,z,w);
//     return x+y+z+w;
// }
// int main(){
//     int a=0;
//     printf("%d\n",foo(++a, a++, a++, a));
//     return 0;
// }
// #define square(x) x*x
// int main() {
//     printf("%d\n",square(3+1));
// }
// int r(){
//     static int n = 7;
//     return n--;
// }
// int main(){
//     for(r(); r(); r()){
//         printf("%d\n",r());
//     }
// }
// int main(){
//     int A{16} = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2 };
//     // int *A = malloc(16*sizeof(int));
//     A{0} = 1;
//     A{1} = 2;
//     A{3} = 8;
//     int *p;
//     printf("A = %p\n", A);
//     printf("A + 1 = %p\n", A + 1);
//     printf("&A = %p\n", &A);
//     printf("&A + 1 = %p\n\n", &A + 1);
//     p = A;
//     printf("p = %p\n", p);
//     printf("p + 1 = %p\n", p + 1);
//     printf("&p = %p\n", &p);
//     printf("&p + 1 = %p\n", &p + 1);
    
//     printf("%d %d %d\n",*A, *(A+1), **&A);
//     printf("%d %d %d\n",*p, *(p+1), *(p+2));
//     return 0;
// }