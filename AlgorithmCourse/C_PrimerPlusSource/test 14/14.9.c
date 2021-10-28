/*9.���˺��չ�˾�������ϰ 8����Ҫ��һ�ܷɻ���������ͬ����ÿ���
4 �ࣨ���� 102��311��444 ��519�����ѳ�����չΪ���Դ���4�����ࡣ��һ
������˵��ṩ����ѡ����˳���ѡ��һ���ض����࣬�ͻ���ֺͱ����ϰ
8���ƵĲ˵������Ǹò˵�Ҫ���һ����ѡ�ȷ����λ���䡣���ң��˵�
�е��˳��Ƿ��ض���˵���ÿ����ʾ��Ҫָ����ǰ���ڴ���ĺ���š���
�⣬��λ������ʾҪָ��ȷ��״̬��*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAX 12      //�����λ��
#define FL 5        //������ַ�������
#define F_N 4       //ÿ��ɼ���

int status;//ȫ�ֱ��������ȷ�����

struct plane{
    int num;
    int flag;//0����û�ˣ�1��������
    char fname[LEN];
    char lname[LEN];
};
struct flights{//�������
    char flight_num[FL];//�����
    struct plane seats[MAX];
};

void read_file(struct flights *se,char *name);        //��ȡ�ļ�
char * s_gets(char * st, int n);	    //�����ַ����ĺ���
char get_choice(struct flights *se,int n);					//�û�����ѡ��
void show_number(struct flights *se,int n);		//��λ�õĸ���
void show_empty(struct flights *se,int n);		//��ӡ���п�λ��
void show_list(struct flights *se,int n);		//��ӡ����λ����Ϣ
void assign_seat(struct flights *se,int n);		//Ԥ��һ��λ��
void delete_seat(struct flights *se,int n);		//ɾ��һ��λ��
int get_flight(struct flights *se);                  //ѡ�񺽰�
void confirm_seat(void);                //ȷ����λ
void choose_seat_menu(struct flights *se,int n) ;          //��λ�˵�ѡ��
void choose_flight_menu(struct flights *se);        //����˵�ѡ��
void write_file(struct flights *se,char *name);       //����д���ļ�

int main(void)
{
    struct flights se[F_N];
    char name[LEN];

    read_file(se,name);//��ȡ

    choose_flight_menu(se);//����˵�

    if(status)//ȷ���˲Żᱣ��
        write_file(se,name);//����д���ļ�
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

void read_file(struct flights *se,char *name)
{
    FILE *fp;

    for(int i=0;i<F_N;i++)//��ʼ���ṹ
        for(int j=0;j<MAX;j++)
            se[i].seats[j]=(struct plane){(j+1),0,"",""};

    //���ļ���ȡ
    puts("������Ҫ�򿪵��ļ�����");
    s_gets(name,LEN);
    if ((fp = fopen(name, "a+b")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    fread(se,sizeof(struct flights),F_N,fp);
    fclose(fp);
}


int get_flight(struct flights *se)                  //ѡ�񺽰�
{
    int n;

    puts("\n��ѡ�񺽰�:");
    printf("1) 102 \t 2) 311\n"
           "3) 444 \t 4) 519\n"
           "88) �뿪\n");
    while( (scanf("%d",&n)) != 1 && n != 2 &&
          n != 3 && n != 4 && n != 88)
    {
        while(getchar() !='\n') continue;//����������
        puts("��������ȷ������.");
    }
    while(getchar() !='\n') continue;

    if(n ==1)
        strcpy(se[n-1].flight_num,"102");
    else if(n ==2)
        strcpy(se[n-1].flight_num,"311");
    else if(n ==3)
        strcpy(se[n-1].flight_num,"444");
    else if(n ==4)
        strcpy(se[n-1].flight_num,"519");
    else if(n ==88)
        ;
    else
        {
            puts("�������.\n");
            exit(EXIT_FAILURE);
        }

    return n;
}

void choose_flight_menu(struct flights *se)     //����˵�ѡ��
{
    int n;

    while((n=get_flight(se)) != 88)
    {
        status=0;
        choose_seat_menu(se,n);
    }
}

char get_choice(struct flights *se,int n)
{
    char ch;

    printf("\nThe number of the flight is %s. To choose a function,"
            "enter its letter label"
            "(��ǰ�������%s����ѡ��):\n",se[n-1].flight_num, se[n-1].flight_num);
    printf( "a) Show number of empty seats(��ʾ��������)\n"
            "b) Show list of empty seats(��ʾ��������)\n"
            "c) Show alphabetical list of seats(��˳����ʾ��λ����)\n"
            "d) Assign a customer to a seat assignment(Ԥ����λ)\n"
            "e) Delete a seat assignment(ɾ����λ)\n"
            "f) Confirm seat allocation(ȷ����λ����)\n"
            "q) please save it before quit(�뿪ǰ�뱣����λ����)\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f' &&
          ch != 'q') //תСд��ĸ
    {
        while(getchar() !='\n') continue;//����������
        puts("��������ȷ����ĸ.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void choose_seat_menu(struct flights *se,int n)            //��λ�˵�ѡ��
{
    char ch;

    while( (ch=get_choice(se,n)) != 'q')
    {
        switch(ch)
        {
        case 'a':show_number(se,n);
                break;
        case 'b':show_empty(se,n);
                break;
        case 'c':show_list(se,n);
                break;
        case 'd':assign_seat(se,n);
                break;
        case 'e':delete_seat(se,n);
                break;
        case 'f':confirm_seat();
                break;
        default:puts("�������.");
            break;
        }
    }
}

void show_number(struct flights *se,int n)//��λ�õĸ���
{
    int i,count=0;

    for(i=0;i<MAX;i++)
    {
        if(se[n-1].seats[i].flag == 0)
            count++;
    }
    printf("��λ�õ�������%d.\n",count);
}

void show_empty(struct flights *se,int n)//��ӡ���п�λ��
{
    int i;

    puts("��λ�õĺ�������:\n");
    for(i=0;i<MAX;i++)
    {
        if(se[n-1].seats[i].flag==0)
            printf("%d ",se[n-1].seats[i].num);
    }
    printf("\n");
}

void show_list(struct flights *se,int n)//��ӡ����λ����Ϣ
{
    int i;

    puts("����λ�õ��嵥���£�\n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\t%s\t%s\n",se[n-1].seats[i].num,se[n-1].seats[i].fname,se[n-1].seats[i].lname);
    }
}

void assign_seat(struct flights *se,int n)//Ԥ��һ��λ��
{
    int nu;
    int temp;

    puts("�������ҪԤ������λ��(1-MAX).");
    while(!((temp=scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[n-1].seats[nu-1].flag == 0))
    {
        while(getchar() != '\n') continue;
        if(temp !=1 || nu<1 || nu>MAX)
            printf("��λ�Ŵ���,������1-MAX!\n");
        else
            printf("�Բ���,�����λ�Ѿ���Ԥ����!������������λ��.\n");
    }
    while(getchar() != '\n') continue;
    se[n-1].seats[nu-1].flag=1; //Ԥ����λ
    puts("����������գ�");
    s_gets(se[n-1].seats[nu-1].fname,LEN);
    puts("�������������");
    s_gets(se[n-1].seats[nu-1].lname,LEN);
    printf("Ԥ���ɹ�.\n");
}

void delete_seat(struct flights *se,int n)//ɾ��һ����λ
{
    int nu;

    puts("�������Ҫɾ������λ��(1-MAX).");
    while(!((scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[n-1].seats[nu-1].flag == 1))
    {
        while(getchar() != '\n') continue;
        if(se[n-1].seats[nu-1].flag == 0)//����λ����ɾ��
            printf("�Բ���,����λû��!������������λ��.\n");
        else
            printf("��λ�Ŵ���,������1-MAX!\n");
    }
    while(getchar() != '\n') continue;
    se[n-1].seats[nu-1]=(struct plane){nu,0,"",""};//ֱ�Ӹ�����Ϣ
    printf("ɾ���ɹ���\n");
}

void confirm_seat(void)                //ȷ����λ
{
    status=1;
    printf("��λȷ����ɣ�\n");
}

void write_file(struct flights *se,char *name)//����д���ļ�
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(se, sizeof(struct flights),F_N,p);
    fclose(p);
}
