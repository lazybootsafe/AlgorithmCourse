
/*�����ϰ12_�ĸİ���Ŀ��ԭ��̫���������ǣ�����һ����20�У�ÿ��30���������ı��ļ���������0-9֮�䣬�ÿո�ֿ���
���ļ���һ��ͼƬ�����ֱ�ʾ����0��9����Ҷȵ����ӡ������ļ����ݶ��뵽20*30��int���顣
һ�ֽ��������ֱ�ʾת��ΪͼƬ�Ĵ��Է��������ó���ʹ�������е���ֵ����ʼ��һ��20*31���ַ����С�
0��Ӧ�ո��ַ���1��Ӧ����ַ����������ƣ��ϴ��ֵ��Ӧռ�ÿռ�϶���ַ���
���磬����ʹ��#����9��ÿ�е����һ���ַ�����31����Ϊ���ַ����������齫����20���ַ�����
Ȼ�������ʾ�ṹͼƬ������ӡ��Щ�ַ������������������һ���ı��ļ��С�

�İ�Ҫ������ͼ������������ɴ����ص�����ͼ����ܰ���������塣Ϊ��12�������ϰ�⣨���������������������������ĺ�����
			�ú���Ӧ�ö�ÿһ��ֵ�����������ҵ�����ֵ�Ƚϣ������ֵ������Χÿ��ֵ�Ĳ����1����ʹ����������ֵ��ƽ��ֵ��ȡ
			������ӽ���������ȡ�����ֵ��ע�⵽�߽��ϵĵ�����ڵ㶼����4��������������Ҫ���⴦��

�ҵĳ���������������д600��int�����ı���ֻ᲻���ˡ����ԣ�ֱ���ó��򴴽�20*30�����鲢д���ļ���Ҳʡȥ���ٶ��������鷳��
�����ĸ����ֶ�Ӧת��Ϊ�ĸ��ַ�����Ŀ����ȷҪ�󣬿����Զ��塣ŷ��
	���������Ǳ�д������ν�������ĺ����ˡ�

	ע�⣺����˵�ıߵ�ָ��ά�������ܵĵ�(�������ǵ�)���ǵ�ָ�ĸ����ϵĵ㡣�ҳ���Ҫ�������±ơ�*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FNAME "number.txt"
#define FDEST "graph.txt"
#define ROW 20
#define COL 30

char toChar(int num);
void alterNum(int num[][COL], int rows);										//�޸Ķ�ά���飬�����������

int main(void)
{
	FILE * fp;
	int num[ROW][COL];
	char chlist[ROW][COL + 1];							//�ַ����У��������е��ַ���

	system("color 0A");
	if (fopen_s(&fp, FNAME, "w") != 0)
	{
		fprintf(stderr, "Error in opening file %s.\n", FNAME);
		exit(EXIT_FAILURE);
	}

	//д��20x30��int����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			num[i][j] = rand() % 10;
			fprintf(fp, "%d", num[i][j]);
			if (j != COL - 1)
			{
				putc(' ', fp);
			}
		}
		putc('\n', fp);
	}
	fclose(fp);

	//�����������
	alterNum(num, ROW);

	//ת�����ַ�����
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			chlist[i][j] = toChar(num[i][j]);
		}
		chlist[i][COL] = '\0';						//ÿ�����ַ���
	}

	//��ӡ�ַ�����
	for (int i = 0; i < ROW; i++)
	{
		printf("%s", chlist[i]);
		putchar('\n');
	}

	//д���ַ����е��ļ�
	if (fopen_s(&fp, FDEST, "w") != 0)
	{
		fprintf(stderr, "Error in opening file %s.\n", FDEST);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < ROW; i++)
	{
		fprintf(fp, "%s", chlist[i]);
		putc('\n', fp);
	}
	fclose(fp);

	system("pause");
	return 0;
}

char toChar(int num)
{
	char ch;

	switch (num)
	{
	case 0:
		ch = ' ';
		break;
	case 1:
		ch = '.';
		break;
	case 2:
		ch = '*';
		break;
	case 3:
		ch = '/';
		break;
	case 4:
		ch = '?';
		break;
	case 5:
		ch = '&';
		break;
	case 6:
		ch = '%';
		break;
	case 7:
		ch = '$';
		break;
	case 8:
		ch = '@';
		break;
	case 9:
		ch = '#';
		break;
	}

	return ch;
}

//�޸Ķ�ά���飬�����������
void alterNum(int num[][COL], int rows)
{
	//�����ĸ���

	if (num[0][0] - num[0][1] > 1 && num[0][0] - num[1][0] > 1)																//���Ͻ�
	{
		num[0][0] = (num[0][1] + num[1][0]) / 2;
	}
	if (num[0][COL - 1] - num[0][COL - 2]>1 && num[0][COL - 1] - num[1][COL - 1] > 2)										//���Ͻ�
	{
		num[0][COL - 1] = (num[0][COL - 2] + num[1][COL - 1]) / 2;
	}
	if (num[rows - 1][0] - num[rows - 2][0] > 1 && num[rows - 1][0] - num[rows - 1][1] > 2)									//���½�
	{
		num[rows - 1][0] = (num[rows - 2][0] + num[rows - 1][1]) / 2;
	}
	if (num[rows - 1][COL - 1] - num[rows - 2][COL - 1] > 1 && num[rows - 1][COL - 1] - num[rows - 2][COL - 1 ] > 2)		//���½�
	{
		num[rows - 1][COL - 1] = (num[rows - 2][COL - 1] + num[rows - 2][COL - 1]) / 2;
	}

	//�����ı�
	for (int i = 1; i < COL - 1; i++)																						//��һ��
	{
		if (num[0][i] - num[0][i - 1]>1 && num[0][i] - num[0][i + 1] > 1 && num[0][i] - num[1][i] > 1)
		{
			num[0][i] = (num[0][i - 1] + num[0][i + 1] + num[1][i]) / 3;
		}
	}
	for (int i = 1; i < COL - 1; i++)																						//���һ��
	{
		if (num[rows - 1][i] - num[rows - 1][i - 1] > 1 && num[rows - 1][i] - num[rows - 1][i + 1] > 1 && num[rows - 1][i] - num[rows - 2][i] > 1)
		{
			num[rows - 1][i] = (num[rows - 1][i - 1] + num[rows - 1][i + 1] + num[rows - 2][i]) / 3;
		}
	}
	for (int i = 1; i < rows - 1; i++)																						//��һ��
	{
		if (num[i][0] - num[i - 1][0] > 1 && num[i][0] - num[i + 1][0] > 1 && num[i][0] - num[i][1] > 1)
		{
			num[i][0] = (num[i - 1][0] + num[i + 1][0] + num[i][1]) / 3;
		}
	}
	for (int i = 1; i < rows - 1; i++)																						//���һ��
	{
		if (num[i][COL - 1] - num[i - 1][COL - 1] > 0 && num[i][COL - 1] - num[i + 1][COL - 1] > 1 && num[i][COL - 1] - num[i][COL - 2] > 1)
		{
			num[i][COL - 1] = (num[i - 1][COL - 1] + num[i + 1][COL - 1] + num[i][COL - 2]) / 3;
		}
	}
	
	//�����м�ĵ�
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			if (num[i][j] - num[i - 1][j] > 1 && num[i][j] - num[i + 1][j] > 1 && num[i][j] - num[i][j - 1] > 1 && num[i][j] - num[i][j + 1] > 1)
			{
				num[i][j] = (num[i - 1][j] + num[i + 1][j] + num[i][j - 1] + num[i][j + 1]) / 4;
			}
		}
	}

}