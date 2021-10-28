
/*��Ŀ̫���������ǣ�����һ����20�У�ÿ��30���������ı��ļ���������0-9֮�䣬�ÿո�ֿ���
���ļ���һ��ͼƬ�����ֱ�ʾ����0��9����Ҷȵ����ӡ������ļ����ݶ��뵽20*30��int���顣
һ�ֽ��������ֱ�ʾת��ΪͼƬ�Ĵ��Է��������ó���ʹ�������е���ֵ����ʼ��һ��20*31���ַ����С�
0��Ӧ�ո��ַ���1��Ӧ����ַ����������ƣ��ϴ��ֵ��Ӧռ�ÿռ�϶���ַ���
���磬����ʹ��#����9��ÿ�е����һ���ַ�����31����Ϊ���ַ����������齫����20���ַ�����
Ȼ�������ʾ�ṹͼƬ������ӡ��Щ�ַ������������������һ���ı��ļ��С�

�ҵ�������д600��int�����ı���ֻ᲻���ˡ����ԣ�ֱ���ó��򴴽�20*30�����鲢д���ļ���Ҳʡȥ���ٶ��������鷳��
		�����ĸ����ֶ�Ӧת��Ϊ�ĸ��ַ�����Ŀ����ȷҪ�󣬿����Զ��塣ŷ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FNAME "number.txt"
#define FDEST "graph.txt"
#define ROW 20
#define COL 30

char tochar(int num);

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

	//ת�����ַ�����
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			chlist[i][j] = tochar(num[i][j]);
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

char tochar(int num)
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