#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randnum(int arr[], int count);
void sort(int arr[], int count);

int main(void)
{
	int count = 0, i = 0;
	int * ptr;
	system("color 5A");

	srand((unsigned int)time(NULL));			//ϵͳʱ���ʼ������
	puts("How many random number?");
	scanf_s("%d", &count, 10);
	ptr = (int *)malloc(count * sizeof(int));
	if (ptr == NULL)
	{
		puts("Create array failed.");
		exit(EXIT_FAILURE);
	}
	randnum(ptr, count);						//������д�������
	sort(ptr, count);
	for (i = 0; i < count; i++)					//��ӡ���
	{
		printf("%3d", ptr[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');

	system("pause");
	return 0;

}

//��ӡ1-10֮��������count��
void randnum(int arr[], int count)
{
	for (int i = 0; i < count; i++)				//count����������浽���������
		arr[i] = rand() % 10 + 1;
}
//��������
void sort(int arr[], int count)
{
	int temp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}