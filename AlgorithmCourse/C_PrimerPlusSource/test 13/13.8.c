/*8.��дһ��������һ���ַ��������ļ�����Ϊ�����в���������ַ�
����û�в������ó����ȡ��׼���룻���򣬳������δ�ÿ���ļ�������
ÿ���ļ��и��ַ����ֵĴ������ļ������ַ�����ҲҪһͬ���档����Ӧ��
�������飬��ȷ�����������Ƿ���ȷ���Ƿ��ܴ��ļ�������޷�����
��������Ӧ������һ�����Ȼ�����������һ���ļ���*/
#include <stdio.h>
#include <stdlib.h>  // �ṩ exit()��ԭ��
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *p;
    char ch;
    int i,count=0;

    if (argc < 2)
    {
        fprintf(stderr, "�����в�����������\n.");
        exit(EXIT_FAILURE);
    }

    if(argc==2)
    {
        puts("����һЩ����:");
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0])
                count++;
        }
        printf("���������%s������%d��.\n",argv[1], count);

    }
    else
    {
        for(i=2;i<argc;i++)
            {
                count=0;
                if ((p = fopen(argv[i], "r")) == NULL)
                {
                    fprintf(stderr,"Can't open %s\n", argv[i]);
                        continue;
                }

                while( (ch=getc(p)) != EOF)
                {//����Ƿ��ļ���β
                    if(ch == argv[1][0])
                        count++;
                }
                printf("%s��%d��%s�ַ�.\n",argv[i],count,argv[1]);
            }
    }

    return 0;
}
