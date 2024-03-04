#include <stdio.h>
void towerOfHanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", a, b);
		return;
	}
	towerOfHanoi(n-1, a, c, b);
	printf("\n Move disk %d from rod %c to rod %c", n, a, b);
	towerOfHanoi(n-1, c, b, a);
}
int main()
{
	int n = 3;
	towerOfHanoi(n, 'A', 'B', 'C');
	return 0;
}
