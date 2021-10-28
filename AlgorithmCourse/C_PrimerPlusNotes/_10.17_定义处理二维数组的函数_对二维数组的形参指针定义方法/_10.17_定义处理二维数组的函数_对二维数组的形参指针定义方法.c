#include<stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);		//����ʡ������
int sum2d(int (*pt)[COLS], int rows);	//��һ���﷨��ʽ

int main(void)
{
	int junk[ROWS][COLS] = {
		{ 2, 4, 6, 8 },
		{ 3, 5, 7, 9 },
		{ 12, 10, 8, 6}
	};

	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

	getchar();
	return 0;
}

//����ÿ�еĺ�
void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;

	for (r = 0; r < rows; r++)
	{
		tot = 0;
		for (c = 0; c < COLS; c++)  //����һ�е������еĺ�
			tot += ar[r][c];
		printf("row %d: sum = %d\n", r, tot);

	}
}

//����ÿ�еĺ�
void sum_cols(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;

	for (c = 0; c < COLS; c++)
	{
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
		printf("col %d: sum = %d\n", c, tot);
	}
}

//�����ά����Ԫ�غ�
int sum2d(int ar[][COLS], int rows)	/*����������������ת����ָ����ţ���int ar[][4]����ʾar��ָ�����4��int�������ָ�룬
										Ҳ��������һ�Է���������д��С������int ar[3][4]������������������֮
										
									һ��أ�����Nά�����ָ��ʱ����������ߵķ����ſ���ʡ���⣬��������Ҫ��д��ֵ

									int sum4d(int ar[][12][20][30], int rows);
									�׷����ű�ʾ����һ��ָ�룬����������������������ָ�������������ͣ���Ч�������£�
									int sum4d(int (*ar)[12][20][30],int rows);		//ar��һ��ָ��
									arָ��һ��12 x 20 x 30��int����

									���⣬�����ά�������ǳ����������ñ�������COLS*/
{
	int r;
	int c;
	int tot = 0;

	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	}
	
	return tot;
}

//typedef int arr4[4];				//�������ͣ�arr4��4��int������
//typedef arr4 arr3x4[3];			//����������arr3x4��3��arr4������

//int sum2(arr3x4 ar, int rows);	//ͬ��
//int sum2(int ar[3][4], int rows);	//ͬ��
//int sum2(int ar[][4], int rows);	//��׼��ʽ
