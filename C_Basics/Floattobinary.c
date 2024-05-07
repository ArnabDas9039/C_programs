#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
void floatToBinaryArray(float number, uint32_t* binaryArray){
    uint32_t* floatPtr = (uint32_t*)&number;
    uint32_t floatBits = *floatPtr;

    for(int i = 31; i >= 0; i--){
        binaryArray[i] = floatBits & 1;
        floatBits >>= 1;
    }
}

int main(){
    //float number=1.175494210692441075487029444849287348827052428745893333857174530571588870475618904265502351336181163787841796875E-38;
    // float number = 1.17549421069e-38;
    float number = 0.75;
    uint32_t binaryArray[32];
    floatToBinaryArray(number, binaryArray);
    printf("Binary representation of %.20e:\n", number);
    printf("%u", binaryArray[0]);
    printf("\t");
    for(int i = 1; i < 9; i++){
        printf("%u", binaryArray[i]);
    }
    printf("\t");
    for(int i = 9; i < 32; i++){
        printf("%u", binaryArray[i]);
    }
    long double a = 1;
    /*for(int i=1; i<=112; i++){
        a=a+pow(2,-i);
        printf("\n%.20e",a);
    }
    a=a*pow(2,16383);*/
    printf("\n%Lf", a);
    return 0;
}
