/*6.ʹ�������в����ĳ����������û����ڴ������ȷ��ʹ�����ǡ���д
�����嵥 13.2 �еĳ��򣬲�ʹ�������в�����������ʾ�û�����������
Ϣ��*/
// reducto.c �C���ļ�ѹ����ԭ����1/3��
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
#define LEN 40
int main(void)
{
    FILE *in, *out; // ��������ָ�� FILE ��ָ��
    int ch;
    char name_in[LEN],name_out[LEN]; // ��������ļ���
    int count = 0;

    printf("������Դ�ļ�����");
    fscanf(stdin,"%s",name_in);
    printf("������Ŀ���ļ�����");
    fscanf(stdin,"%s",name_out);
    // ��������
    if ((in = fopen(name_in, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name_in);
        exit(EXIT_FAILURE);
    }
    // �������

    if ((out = fopen(name_out, "w")) == NULL)
    {          // ��дģʽ���ļ�
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // ��������
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);// ��ӡ3���ַ��еĵ�1���ַ�
    // ��β����
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
