/*
	һ���ı��ļ��д����һ������ӵ���Ϣ��ÿһ�е����ݶ����������еģ�
	4 Jessie Joybat 5 2 1 1
	��һ������Ա���룬Ϊ�˷��㣬��Χ��0��18���ڶ�������Ա���������������ա��պ������ǵ����ĵ��ʡ�
	��һ���ǹٷ�ͳ�Ƶ���Ա�ϳ��������������ǻ������������������ܵ�����RBI�����ļ����ܰ�������
	һ�����������ݣ����ͬһ����Ա���ܻ��ж���һ�е����ݣ������ڲ�ͬ����֮���п����б����Ա�����ݡ�
	дһ�����򣬰���Щ���ݴ洢��һ���ṹ�����С��ṹ�б��뺬���ա������ϳ�������������������������
	�������Լ�����ƽ���ɹ��ʣ��Ժ���㣩������ʹ����Ա������Ϊ��������������Ӧ�ö����ļ�ĩβ������
	Ӧ�ñ���ÿ����Ա���ۼ��ܺ͡�

	��������˶��е�ͳ�Ʒ���ʱ��صġ����磬һ�����ݺʹ����е�ʧ�󲢲�������ϳ���������������ܲ�
	��һ��RBI�����ǣ��ó�����Ҫ����ֻ�Ǵ��������ļ��������ع������ݵ�ʵ�ʺ��塣

	Ҫʵ����Щ���ܣ���򵥵ķ����ǰѽṹ�����ݳ�ʼ��Ϊ0ֵ�����ļ����ݶ�����ʱ�����У�Ȼ������Ǽӵ�
	��Ӧ�ṹ�������С���������ļ���Ӧ�ü���ÿ����Ա�Ļ���ƽ���ɹ��ʣ����������浽��Ӧ�Ľṹ��Ա�
	�������ƽ���ɹ����Ƕ���Ա���ۼƻ����������ϳ��ۼƴ��������Ǹ����������㡣Ȼ�����Ҫ��ʾÿ����Ա
	���ۼ����ݣ����Ҷ�����ʱ����ʾһ���ۺ�ͳ�����ݡ�
	
	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define NAMESIZE	21
#define MAXSIZE	100
#define FILENAME "info.txt"
#define TEMPSIZE 41

struct _name
{
	char fname[NAMESIZE];
	char lname[NAMESIZE];
};

struct member
{
	int number;				//��Ա��
	struct _name name;		//��Ա
	int participate;		//�ϳ�����
	int success;			//������
	int leakout;			//������
	int RBI;				//�ܵ���
	float percent;			//����ɹ���
};

int getinfo(struct member members[], int n, FILE * fp);									//��ȡ����
void makeinfo(struct member members[], int n);											//�������ƽ����
void showinfo(const struct member members[], int n);									//��ӡ��Ϣ
bool is_num_repeat(const struct member members[], int n,const struct member temp);		//����ظ����
void update(struct member members[], int n, const struct member temp);					//�ϲ�����ظ��ļ�¼
void saveinfo(const struct member members[], int n, FILE * fp);							//��������

int main(void)
{
	struct member members[MAXSIZE] = { 0 };
	FILE * fp;
	int count;

	system("color 5A");

	if (fopen_s(&fp, FILENAME, "r") != 0)
	{
		fprintf(stderr, "Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	//������
	count = getinfo(members, MAXSIZE, fp);
	if (count > 0)
	{
		makeinfo(members, count);
		showinfo(members, count);

		//��д���ݣ��ϲ��ظ���¼��
		fclose(fp);
		if (fopen_s(&fp, FILENAME, "w") != 0)
		{
			fprintf(stderr, "Can't open file.\n");
			exit(EXIT_FAILURE);
		}
		rewind(fp);
		saveinfo(members, count, fp);
	}
	else
	{
		printf("No record? Too bad.\n");
	}
	fclose(fp);

	system("pause");
	return 0;
}

int getinfo(struct member members[], int n, FILE * fp)
{
	
	int count = 0, result;
	struct member temp;

	//����һ����¼
	result = fscanf_s(fp, "%d %s %s %d %d %d %d", &temp.number, temp.name.fname, NAMESIZE, temp.name.lname, NAMESIZE,
		&temp.participate, &temp.success, &temp.leakout, &temp.RBI);

	while (result == 7 && count < n)
	{
		if (is_num_repeat(members, count, temp))
		{
			update(members, count, temp);
		}
		else
		{
			members[count] = temp;
			count++;
		}

		//����һ��
		result = fscanf_s(fp, "%d %s %s %d %d %d %d", &temp.number, temp.name.fname, NAMESIZE, temp.name.lname, NAMESIZE,
			&temp.participate, &temp.success, &temp.leakout, &temp.RBI);
	}

	return count;
}

bool is_num_repeat(const struct member members[], int n, const struct member temp)
{
	for (int i = 0; i < n; i++)
	{
		if (members[i].number == temp.number)
		{
			return true;
		}
	}

	return false;
}

void update(struct member members[], int n,const struct member temp)
{
	for (int i = 0; i < n; i++)
	{
		if (members[i].number == temp.number)
		{
			members[i].participate += temp.participate;
			members[i].success += temp.success;
			members[i].leakout += temp.leakout;
			members[i].RBI += temp.RBI;
		}
	}
}

void makeinfo(struct member members[], int n)
{
	for (int i = 0; i < n; i++)
	{
		members[i].percent = (float)members[i].success / (float)members[i].participate;
	}
}

void showinfo(const struct member members[], int n)
{
	int participate_avge = 0, success_avge = 0, leakout_avge = 0, RBI_avge = 0;
	float percent_avge = 0;

	//puts("Here is the list of every member's accumulative data:");
	printf("%5s%12s%20s%10s%10s%10s%10s\n", 
		"Number", "Name", "Participate", "Success", "Leakout", "RBI", "Percent"); 

	for (int i = 0; i < n; i++)
	{
		printf("%5d%10s %-15s%7d%8d%9d%12d%11.1f\n", members[i].number, members[i].name.fname, members[i].name.lname,
			members[i].participate, members[i].success, members[i].leakout, members[i].RBI, members[i].percent);
		//ͳ�ƺ�
		participate_avge += members[i].participate;
		success_avge += members[i].success;
		leakout_avge += members[i].leakout;
		RBI_avge += members[i].RBI;
		percent_avge += members[i].percent;
	}
	//��ʾ�ۺ�����
	printf("%-30s %7d%8d%9d%12d%11.1f\n", "Average data of above: ",
		participate_avge / n, success_avge / n, leakout_avge / n, RBI_avge / n, percent_avge / n);
}

void saveinfo(const struct member members[], int n, FILE * fp)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d %s %s %d %d %d %d\n", members[i].number, members[i].name.fname, members[i].name.lname,
			members[i].participate, members[i].success, members[i].leakout, members[i].RBI);
	}
}