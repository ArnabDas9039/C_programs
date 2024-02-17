#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(){
	printf("Data Type \t\tSize \tMinimum \t\tMaximum \t\tFormat Specifier\n");
	printf("Short Int \t\t%d \t%hd \t\t\t%hd \t\t\thd\n",sizeof(short int),SHRT_MIN,SHRT_MAX);
	printf("Unsigned Short Int \t%d \t0 \t\t\t%hu \t\t\thu\n",sizeof(unsigned short int),USHRT_MAX);
	printf("Int \t\t\t%d \t%d \t\t%d \t\td\n",sizeof(int),INT_MIN,INT_MAX);
	printf("Unsigned Int \t\t%d \t0 \t\t\t%u \t\tu\n",sizeof(unsigned int),UINT_MAX);
	printf("Long Int \t\t%d \t%ld \t\t%ld \t\tld\n",sizeof(long int),LONG_MIN,LONG_MAX);
	printf("Unsigned Long Int \t%d \t0 \t\t\t%lu \t\tlu\n",sizeof(unsigned long int),ULONG_MAX);
	printf("Long Long Int \t\t%d \t%lld \t%lld \tlld\n",sizeof(long long int),LLONG_MIN,LLONG_MAX);
	printf("Unsigned Long Long Int \t%d \t0 \t\t\t%llu \tllu\n",sizeof(unsigned long long int),ULLONG_MAX);
	printf("Character \t\t%d \t%d \t\t\t%d \t\t\tc\n",sizeof(char),CHAR_MIN,CHAR_MAX);
	printf("Unsigned Character \t%d \t0 \t\t\t%d \t\t\tc\n",sizeof(unsigned char),UCHAR_MAX);
	printf("Float \t\t\t%d \t%.16e %.16e f\n",sizeof(float),FLT_MIN,FLT_MAX);
	printf("Double \t\t\t%d \t%.16e %.16e lf\n",sizeof(double),DBL_MIN,DBL_MAX);
	return 0;
}