#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* p,int n)
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
int gcd(int* p, int n)
{
	int i, j, a = 0, gcd = 1;
	for (i = 2; i <=*(p+0); i++)
	{
		a = 0;
		for (j = 0; j < n; j++)
		{
			if (*(p + j) % i == 0)
			{
				a+=1;
				if (a == n)
				{
					gcd = i;
				}
			}
		}
	}
	return gcd;
}
int main()
{
	int* p;
	int n, i;
	scanf("%d", &n);
	if (n < 2 || n>5)
	{
		printf("Error");
		return 0;
	}
	p = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (p + i));
		if (*(p + i) <= 1 || *(p + i) > 10000)
		{
			printf("Error");
			return 0;
		}
	}
	bubbleSort(p, n);
	int r = 0;
	int gcd1 = gcd(p, n);
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
	printf("\nGCD : %d\n", gcd1);
}