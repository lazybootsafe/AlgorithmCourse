#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

void Initialize(int array[], int n);
int comp(const void * p1, const void * p2);
int isExist(int array[], int n, int num);		//�������ĿҪ��ĺ���

int main(void)
{
	int arr[MAXSIZE];
	int num;

	Initialize(arr, MAXSIZE);
	puts("Plesse input a integer to find (q to quit):");
	while (scanf_s("%d", &num) == 1)
	{
		if (isExist(arr, MAXSIZE, num))
		{
			printf("%d is a member.\n", num);
		}
		else
		{
			printf("%d is not a member.\n", num);
		}
		puts("Plesse input a integer to find (q to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//�����ʼ��Ϊ��������
void Initialize(int array[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 1000;
	}
	qsort(array, n, sizeof(int), comp);
	for (int i = 0; i < n; i++)
	{
		printf("%-3d ", array[i]);
	}
	putchar('\n');
}


//���մ�С�����˳������
int comp(const void * p1, const void * p2)
{
	//ת���ɺ��ʵ�ָ������
	const int * a1 = (const int *)p1;
	const int * a2 = (const int *)p2;

	if (*a1 > *a2)
	{
		return 1;
	}
	else if (*a1 == *a2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


//���Ŀ�������������У�����true�����򷵻�false
//��Ҫ�㷨���۰�������
int isExist(int array[], int n, int num)
{
	int minIndex = 0, maxIndex = n - 1;				//�۰�����ʱ��������ʾ��������Χ��minIndex ---> maxIndex
	int middleIndex = (minIndex + maxIndex) / 2;	//�м�������
	int prev = -1;									//ǰһ�β���ʱ���м�������

	while (prev != middleIndex)
	{
		if (num == array[middleIndex])
		{
			return 1;
		}
		else if (num > array[middleIndex])
		{
			minIndex = middleIndex;
		}
		else
		{
			maxIndex = middleIndex;
		}
		prev = middleIndex;
		middleIndex = (minIndex + maxIndex) / 2;
	}
	return 0;
}