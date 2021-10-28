/*11.��дһ������������10���ַ������߶���EOFʱֹͣ���ó���Ϊ��
���ṩһ����5��ѡ��Ĳ˵�����ӡԴ�ַ����б���ASCII�е�˳���ӡ��
�����������ȵ���˳���ӡ�ַ��������ַ����е�1�����ʵĳ��ȴ�ӡ�ַ�
�����˳����˵�����ѭ����ʾ�������û�ѡ���˳�ѡ���Ȼ���ó���Ҫ��
������ɲ˵��и�ѡ��Ĺ���*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 80
char * s_gets(char * st, int n);			//��ȡ�ַ�������
char get_choice(void);						//��ȡѡ��
void print_sour(char * st[], int n);		//��ӡԴ�ַ���
void print_ascii(char * st[], int n);		//��ASCII��˳���ӡ
void print_length(char * st[], int n);		//������˳���ӡ
void print_first_word(char * st[], int n);	//����һ�����ʵĳ���˳���ӡ
int first_word(char * st);					//�����һ��������
void get_choice_main(void);                 //��ȡ�ַ�������ѡ��
int main(void)
{
    get_choice_main();

    getchar();
    return 0;
}

//��ȡ�ַ�������ѡ��
void get_choice_main(void)
{
    char str[LIM][SIZE];
    char * ptr[LIM];
    int row = 0;							//������ַ�������
    char choice;							//�û������ѡ���ַ�

    puts("����һЩ�ַ�����������10����:");
    while( row<LIM && s_gets(str[row],SIZE) != NULL )//ͳ�������ַ����ĸ���
    {
        ptr[row]=str[row];
        row++;
    }
    while((choice=get_choice()) != 'q')
        {
            printf("\n");
            switch(choice)
            {
                case 'a':print_sour(ptr,row);
                        break;
                case 'b':print_ascii(ptr,row);
                        break;
                case 'c':print_length(ptr,row);
                        break;
                case 'd':print_first_word(ptr,row);
                        break;
                default: puts("Error!");
                         break;

            }
            printf("\n");
        }
    puts("�ټ���");
}

//�Զ�����ַ������뺯��
char * s_gets(char * st, int n)
{
    int i = 0;

    if (fgets(st, n, stdin) != NULL)
    {	//������ֵst������NULL
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        return st;
    }
    else
        return NULL;

}

//��ȡѡ��
char get_choice(void)
{
    char choice;

    printf("a:��ӡԴ�ַ����б�\t b:��ASCII�е�˳���ӡ�ַ���\n"
           "c:�����ȵ���˳���ӡ�ַ���\t d:���ַ����е�1�����ʵĳ��ȴ�ӡ�ַ���\n"
           "q:�˳�\n");
    puts("���������ѡ��:");
    choice=getchar();
    while(getchar() != '\n')
        continue;
    while(choice<'a'||choice>'d'&&choice!='q')
    {//���벻��a-d,�Ҳ���q������ʾ��������
        puts("��������ȷ��ѡ��:");
        choice=getchar();
        while(getchar() != '\n')
            continue;
    }

    return choice;
}

//��ӡԴ�ַ���
void print_sour(char * st[], int n)
{
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//��ASCII��˳���ӡ
void print_ascii(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(strcmp(st[i],st[j]) >0)
            {//ð���㷨����
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//������˳���ӡ
void print_length(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(strlen(st[i]) > strlen(st[j]) )
            {//ð���㷨����
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//����һ�����ʵĳ���˳���ӡ
void print_first_word(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if( first_word(st[i]) > first_word(st[j]) )
            {//ð���㷨����
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//�����һ��������
int first_word(char * st)
{
    int i=0,n=0;
    while(!isalpha(st[i])) //������ĸ�Ļ�������
        i++;
    while(isalpha(st[i]))
    {//����ĸ��n+1
        i++;
        n++;
    }

    return n;
}

