/*8.���˺��չ�˾�Ļ�Ⱥ�� 12 ����λ�ķɻ���ɡ���ÿ�����һ����
�ࡣ���������Ҫ�󣬱�дһ����λԤ������
a.�ó���ʹ��һ���ں� 12 ���ṹ�����顣ÿ���ṹ�а�����һ����Ա
��ʾ��λ��š�һ����Ա��ʾ��λ�Ƿ��ѱ�Ԥ����һ����Ա��ʾԤ���˵�
����һ����Ա��ʾԤ���˵��ա�
b.�ó�����ʾ����Ĳ˵���
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
f) Quit
c.�ó����ܳɹ�ִ����������Ĳ˵���ѡ��d)��e)Ҫ��ʾ�û����ж���
���룬ÿ��ѡ������û���ֹ���롣
d.ִ���ض�����󣬸ó����ٴ���ʾ�˵��������û�ѡ��f)��*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAX 12     //�����λ��
struct plane{
    int num;
    int flag;//0����û�ˣ�1��������
    char fname[LEN];
    char lname[LEN];
};

char * s_gets(char * st, int n);	    //�����ַ����ĺ���
char get_choice(void);					//�û�����ѡ��
void show_number(struct plane *se);		//��λ�õĸ���
void show_empty(struct plane *se);		//��ӡ���п�λ��
void show_list(struct plane *se);		//��ӡ����λ����Ϣ
void assign_seat(struct plane *se);		//Ԥ��һ��λ��
void delete_seat(struct plane *se);		//ɾ��һ��λ��
void write_file(struct plane *se,char *name);//����д���ļ�

int main(void)
{
    struct plane seat[MAX];
    char ch;
    char name[LEN];
    FILE *fp;

    for(int i=0;i<MAX;i++)//��ʼ���ṹ
        seat[i]=(struct plane){(i+1),0,"",""};

    //���ļ���ȡ
    puts("������Ҫ�򿪵��ļ�����");
    s_gets(name,LEN);
    if ((fp = fopen(name, "a+b")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    fread(seat,sizeof(struct plane),MAX,fp);
    //ѡ���嵥
    while( (ch=get_choice()) != 'f')
    {
        switch(ch)
        {
        case 'a':show_number(seat);
                break;
        case 'b':show_empty(seat);
                break;
        case 'c':show_list(seat);
                break;
        case 'd':assign_seat(seat);
                break;
        case 'e':delete_seat(seat);
                break;
        default:puts("�������.");
            break;
        }
    }

    write_file(seat,name);//����д���ļ�
    puts("�ټ�.");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // ���һ��з�
        if (find)       // �����ַ���� NULL��
            *find = '\0';    // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;   // ����������
    }
    return ret_val;
}

char get_choice(void)
{
    char ch;

    puts("\nTo choose a function, enter its letter label(��ѡ��):");
    printf("a) Show number of empty seats(��ʾ��������)\n"
           "b) Show list of empty seats(��ʾ��������)\n"
           "c) Show alphabetical list of seats(��˳����ʾ��λ����)\n"
           "d) Assign a customer to a seat assignment(Ԥ����λ)\n"
           "e) Delete a seat assignment(ɾ����λ)\n"
           "f) Quit(�뿪)\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f') //תСд��ĸ
    {
        while(getchar() !='\n') continue;//����������
        puts("��������ȷ����ĸ.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void show_number(struct plane *se)//��λ�õĸ���
{
    int i,count=0;

    for(i=0;i<MAX;i++)
    {
        if(se[i].flag == 0)
            count++;
    }
    printf("��λ�õ�������%d.\n",count);
}

void show_empty(struct plane *se)//��ӡ���п�λ��
{
    int i;

    puts("��λ�õĺ�������:\n");
    for(i=0;i<MAX;i++)
    {
        if(se[i].flag==0)
            printf("%d ",se[i].num);
    }
    printf("\n");
}

void show_list(struct plane *se)//��ӡ����λ����Ϣ
{
    int i;

    puts("����λ�õ��嵥���£�\n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\t%s\t%s\n",se[i].num,se[i].fname,se[i].lname);
    }
}

void assign_seat(struct plane *se)//Ԥ��һ��λ��
{
    int nu;
    int temp;

    puts("�������ҪԤ������λ��(1-MAX).");
    while(!((temp=scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[nu-1].flag == 0))
    {
        while(getchar() != '\n') continue;
        if(temp !=1 || nu<1 || nu>MAX)
            printf("��λ�Ŵ���,������1-MAX!\n");
        else
            printf("�Բ���,�����λ�Ѿ���Ԥ����!������������λ��.\n");
    }
    while(getchar() != '\n') continue;
    se[nu-1].flag=1; //Ԥ����λ
    puts("����������գ�");
    s_gets(se[nu-1].fname,LEN);
    puts("�������������");
    s_gets(se[nu-1].lname,LEN);
    printf("Ԥ���ɹ�.\n");
}

void delete_seat(struct plane *se)//ɾ��һ����λ
{
    int nu;

    puts("�������Ҫɾ������λ��(1-MAX).");
    while(!((scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[nu-1].flag == 1))
    {
        while(getchar() != '\n') continue;
        if(se[nu-1].flag == 0)//����λ����ɾ��
            printf("�Բ���,����λû��!������������λ��.\n");
        else
            printf("��λ�Ŵ���,������1-MAX!\n");
    }
    while(getchar() != '\n') continue;
    se[nu-1]=(struct plane){nu,0,"",""};//ֱ�Ӹ�����Ϣ
    printf("ɾ���ɹ���\n");
}

void write_file(struct plane *se,char *name)//����д���ļ�
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(se, sizeof(struct plane),MAX,p);
    fclose(p);
}
