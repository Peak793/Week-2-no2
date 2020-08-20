#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int*p,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (*(p + j) > * (p + j + 1))
			{
				int temp;
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
}
int main()
{
	int* p;
	int n,i;
	int x[100];
	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (p + i));
	}
	bubbleSort(p, n);
	int r = 0;
	neww :
	printf("%d : ",*(p+r));
	repeat :
	for (i = 2; i <= *(p+r); i++)
	{
		if (*(p + r) % i==0)
		{
			printf("%d", i);
			break;
		}
	}
	*(p + r) /= i;
	if (*(p + r) != 1)
	{
		printf(" x ");
		goto repeat;
	}
	else
	{
		r++;
		if (r < n)
		{
			printf("\n");
			goto  neww;
		}
	}

}