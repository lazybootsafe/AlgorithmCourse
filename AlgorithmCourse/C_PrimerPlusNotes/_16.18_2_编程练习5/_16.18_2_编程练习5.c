/*
��дһ���������ú����������в�����һ��int��������ƣ������С��һ������ѡȡ������ֵ��
Ȼ���������������ѡ��ָ��������Ԫ�ز���ӡ���ǡ�ÿ��Ԫ������ӡһ�Ρ���дһ���򵥵ĳ�����Ժ�����
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 500

void fillarray(int ar[], int n);
void printsome(int ar[], int n, int nwant);

int main(void)
{
	int ar[SIZE], nwant, count = 0;

	fillarray(ar, SIZE);
	system("color 5A");
	puts("Please enter the number of printing (q to quit):");
	while (scanf_s("%d", &nwant) == 1)
	{
		assert(nwant > 0);
		count = nwant < SIZE ? nwant : SIZE;
		printf("Here is the list of %d integer (no more than %d):\n", count, SIZE);
		printsome(ar, SIZE, nwant);
		puts("Next number:");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void fillarray(int ar[], int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		ar[i] = rand();
	}
}

void printsome(int ar[], int n, int count)
{
	int * par;
	int i, j;

	//�����ڴ�
	par = (int *)malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		//�����ȡһ��ar�����Ԫ��д��par������
		par[i] = ar[rand() % n];
		//ȷ��par�ڵĸ�Ԫ�ز��ظ�
		j = 0;
		while (j < i)
		{
			if (par[i] == par[j])
			{
				par[i] = ar[rand() % n];
			}
			else
			{
				j++;
			}
		}
	}
	//��ӡpar����Ԫ��
	for (i = 0; i < count; i++)
	{
		printf("%-6d ", par[i]);
		if (i % 10 == 9)
		{
			putchar('\n');
		}
	}
	if (i % 10)
	{
		putchar('\n');
	}
	//�ͷ��ڴ�
	free(par);
}