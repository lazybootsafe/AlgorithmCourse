#include <stdio.h>
#include <stdlib.h>

#define CTRL_Z '\32'			//DOS�ı��ļ��е��ļ���β���
#define SLEN 51

int main(void)
{
	/*������ʾһ���ļ�

	���������ļ�����fseek()��λ���ļ���β,��ftell()��ȡ��ǰ��д���ֽ�λ�ã�
	������ǰȡһ���ַ������ԣ�ֱ��ȡ�����ַ�ΪMOS-DOS�ı��ļ����ļ���β��LINUX�ı��ļ�����β\rʱ����������
	
	�º�����
	fseek()�������ļ����Ķ�дλ��,ʧ�ܷ��ط�0�����루�ƶ������ļ���Χ������-1����������Ϣ�����MSDN��
	ftell()����ȡ��ǰ��д���ֽ�λ�ã�...��*/

	char file[SLEN];
	char ch;
	FILE * fp;
	long count, last;

	system("color 5A");
	puts("Enter the name of the file to be processed:");
	gets_s(file, SLEN);
	if (fopen_s(&fp, file, "rb"))
	{				//ֻ���Ͷ�����ģʽ
		printf("reverse can't open %s \n", file);		//��ʧ���쳣�˳�
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);							//��λ���ļ���β
					//�����꣬�ļ���β��ʶ
	last = ftell(fp);									//��ǵ�ǰλ�ã����ļ�β
					//ftell()�����ļ���ָ�룬�����ļ��ĵ�ǰλ��
	for (count = 0L; count < last; count++)
	{
		fseek(fp, count, SEEK_SET);					//����
		ch = getc(fp);

		/*����Ƿ��ļ�β�ַ��������Ƿ�س���
		��1.�������ļ�����β��\r\n��ʶ�������ʱ�޳��س�����Ӱ�죩
		2.�ı��ļ�����βC�ǿ���ʶ��ģ��Ὣ\r\n����\n�ַ���
		�����ı���ͼ��DOS�ļ�ֻ�����Ƿ��ļ�β�ַ������Ƿ������ӡ��
		���������ļ���ֻ����Ƿ��ļ�β�ַ���ҲҪ�޳���β�Ļس�����Ȼ������Ƿ��ӡ��*/
		//���DOS����Unix��Ҳ�ɹ���
		if (ch != CTRL_Z && ch != '\r')						/*1.���ı���ͼ�£�C�����ϳ���β�ַ��Ǳ�ʶ�ļ���β���ַ�
															  2.������ģʽ�򿪵�MS_DOS�ļ���Windows NT��DOS���ݣ���
																��1�������ļ���β��C�����ļ��е�һ���ַ���CTRL_Z������'\32'��
																��2�������ƴ򿪵��ļ���β��\r\n��ʶ������Ϊ�˷�ֹ��ӡ�س����������ڴ�ӡǰ�����޳����س���

															  3.֮����ѡ������ƴ��ļ�������Ϊftell()�������ؾ��ļ���ʼ�����ֽ���Ŀ��ȷ���ļ�λ�ã�
																��ASCI C�£����ֶ���ֻ�������Զ�����ģʽ�򿪵��ļ�*/
		{
			putchar(ch);
		}
		//���Macintosh
		/*if (ch == '\r'){putchar(ch);}else{putchar(ch);}*/
	}
	
	putchar('\n');
	fclose(fp);
	

	system("pause");
	return 0;
}