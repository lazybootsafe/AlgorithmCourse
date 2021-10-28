/*2.��дһ���ļ��������򣬸ó���ͨ�������л�ȡԭʼ�ļ����Ϳ�����
����������ʹ�ñ�׼I/O�Ͷ�����ģʽ�� */
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
int main(int argc,char * argv[])
{
    FILE *p_old,*p_new;
    char ch[256];
    size_t bytes;

    if (argc != 3)
    {    //�Զ�ģʽ��ԭʼ�ļ�
        fprintf(stderr,"Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((p_old = fopen(argv[1], "rb")) == NULL)
    {    //�Զ�дģʽ��Ŀ���ļ�
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((p_new = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
     //��������
    while((bytes = fread(ch,sizeof(char),256,p_old)) >0)
        fwrite(ch,sizeof(char),bytes,p_new);
    fclose(p_old);
    fclose(p_new);

    return 0;
}
