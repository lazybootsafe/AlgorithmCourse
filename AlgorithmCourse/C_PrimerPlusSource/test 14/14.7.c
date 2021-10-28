/*7.�޸ĳ����嵥 14.14�����ļ��ж�ȡÿ����¼����ʾ�����������û�
ɾ����¼���޸ļ�¼�����ݡ����ɾ����¼���ѿճ����Ŀռ�������һ��Ҫ
����ļ�¼��Ҫ�޸����е��ļ����ݣ�������"r+b"ģʽ��������"a+b"ģ
ʽ�����ң��������ע�ⶨλ�ļ�ָ�룬��ֹ�¼���ļ�¼�������м�¼��
��򵥵ķ����ǸĶ��������ڴ��е��������ݣ�Ȼ���ٰ�������Ϣд����
�������ٵ�һ����������book�ṹ�����һ����Ա��ʾ�Ƿ���ɾ����*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBOOKS 10     // ����鼮����
int count = 0;      //�ⲿ�����������Ŀ
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);		//�����ַ����ĺ���
char get_choice(void);					//��ȡ�û�ѡ��
void add(struct book li[]);				//������ɱ���
void change(struct book *li);				//�滻һ����
void del(struct book *li);				//ɾ��һ����
void print(struct book *li);				//��ӡ�鵥
void write_file(struct book *li, char *name);	//������д���ļ�

int main(void)
{
    struct book library[MAXBOOKS];
    char ch,name[LEN];
    FILE * fp;

    puts("������Ҫ�򿪵��ļ�����");
    s_gets(name,LEN);
    if ((fp = fopen(name, "r+b")) == NULL)
    {
        fprintf(stderr,"���ܴ�%s�ļ�",name);
        exit(EXIT_FAILURE);
    }
    rewind(fp);     // ��λ���ļ���ʼ
    while (count < MAXBOOKS && fread(&library[count],
            sizeof(struct book), 1, fp) == 1)
    {
        count++;//ͳ�Ƶ�ǰ�鱾��Ŀ
    }
    fclose(fp);

    print(library);//��ӡ�����鼮�б�
    printf("�����鼮%d��.\n",count);

    //ѡ���嵥
    while( (ch=get_choice()) != 'q')
    {
        switch(ch)
        {
        case 'a':add(library);
                break;
        case 'b':change(library);
                break;
        case 'c':del(library);
                break;
        case 'd':print(library);
                break;
        default:puts("�������.");
            break;
        }
    }

    //����д���ļ�
    write_file(library,name);
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

char get_choice(void)   //��ȡ�û�ѡ��
{
    char ch;

    puts("\n���������ѡ��");
    printf("a:��\t\tb:��\n"
           "c:ɾ\t\td:��\n"
           "q:������뿪\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'q') //תСд��ĸ
    {
        while(getchar() !='\n') continue;//����������
        puts("��������ȷ����ĸ.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void add(struct book li[])
{
    if(count == MAXBOOKS)
        puts("����,���ʵ��װ������.\n");
    else
    {
        puts("����������(��[enter]�뿪).");
        while (count < MAXBOOKS && s_gets(li[count].title, MAXTITL) != NULL
                && li[count].title[0] != '\0')
        {
            puts("����������.");
            s_gets(li[count].author, MAXAUTL);
            puts("������۸�.");
            scanf("%f", &li[count++].value);
            while (getchar() != '\n')
                continue;    // ����������
            if (count < MAXBOOKS)
                puts("������һ������(��[enter]�ص�ѡ�����).");
        }
    }
}

void change(struct book *li)
{
    int i;
    char title[MAXTITL];

    puts("����������Ҫ�滻��Ϣ���鼮����");
    s_gets(title,MAXTITL);
    for(i=0;i<count;i++)
    {
        if( strcmp(title,li[i].title) == 0)//��������������ļ��������Ƿ�һ��
        {
            puts("�������鼮�����ǣ�");
            s_gets(li[i].title, MAXTITL);
            puts("����������.");
            s_gets(li[i].author, MAXAUTL);
            puts("������۸�.");
            scanf("%f", &li[i].value);
            while (getchar() != '\n')
                continue;    // ����������
            break;
        }
    }
    if(i==count)
        puts("�Ҳ�����Ҫ���ĵ��鼮!\n");
}

void del(struct book *li)
{
    int i,j;
    int flag=0;//����Ƿ��ҵ�
    char title[MAXTITL];

    if(count == 0)
        puts("���ϣ��������û����!\n");
    puts("����������Ҫɾ�����鼮����");
    s_gets(title,MAXTITL);
    for(i=0;i<count;i++)
    {
        if( ! strcmp(title,li[i].title) )
        {//��������������ļ��������Ƿ�һ��
            flag=1;
            for(j=i;j<count;j++)//һ�����������ݱ䶯
                li[j]=li[j+1];//����������ᵽǰ��
            count--;
            //���һ����������
            li[count]=(struct book){"","",0};
            /*strcpy(li[count].title, "");
            strcpy(li[count].author, "");
            li[count].value = 0;*/ //�������ͬ���滻
            break;
        }
    }
    if(!flag)
        puts("�Ҳ�����Ҫɾ�����鼮!\n");
}

void print(struct book *li)
{
    int index;
    if (count > 0)
    {
        puts("\n�鼮�嵥����:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", li[index].title,
                    li[index].author, li[index].value);
        printf("\n");
    }
    else
        puts("û���ҵ���,���ź�!\n");

}

void write_file(struct book *li, char *name)  //������д���ļ�
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(li, sizeof(struct book), count,p);
    fclose(p);
}
