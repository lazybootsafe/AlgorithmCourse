/*9.��дһ���������������ĺ��������ȣ�ѯ���û���Ҫ������ٸ���
�ʡ�Ȼ�󣬽����û�����ĵ��ʣ�����ʾ������ʹ��malloc()���ش��1����
�⣨��Ҫ������ٸ����ʣ�������һ����̬���飬�������ں���Ӧ��ָ��
char��ָ�루ע�⣬���������ÿ��Ԫ�ض���ָ��char��ָ�룬�������ڴ�
��malloc()����ֵ��ָ��Ӧ����һ��ָ��ָ���ָ�룬������ָ���ָ��ָ
��char�����ڶ�ȡ�ַ���ʱ���ó���Ӧ�ðѵ��ʶ���һ����ʱ��char���飬
ʹ��malloc()�����㹻�Ĵ洢�ռ������浥�ʣ����ѵ�ַ�����ָ������
����������ÿ��Ԫ�ض���ָ�� char ��ָ�룩��Ȼ�󣬴���ʱ�����аѵ���
��������̬����Ĵ洢�ռ��С���ˣ���һ���ַ�ָ�����飬ÿ��ָ�붼ָ
��һ�����󣬸ö���Ĵ�С���������ɱ�������ض����ʡ������Ǹó����
һ������ʾ����
How many words do you wish to enter? 5
Enter 5 words now:
I enjoyed doing this exerise
Here are your words:
I
enjoyed
doing
this
exercise*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40
char * * mal_ar(int n);

int main(void)
{
    int words, i;
    char * * st;

    printf("�������뼸������? ");
    scanf("%d", &words);
    while((getchar()) != '\n')
        continue;       //�˵��س�
    printf("��������%d������:\n", words);
    st = mal_ar(words);
    printf("������ĵ�������:\n");
    for (i = 0; i < words; i++)
    {
        puts(st[i]);
        free(st[i]);	//�ͷ�ÿ��ָ��ָ����ڴ�
    }
    free(st);			//�ͷ�ָ������

    return 0;
}

char * * mal_ar(int n)
{
    char * * pt;
    int i, j;
    char ch;

    //��n��ָ����䶯̬�ڴ�ռ䣬����ָ���ָ��
    pt = (char * *)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {   //��ÿ��ָ��ָ��ĵ�ַ�����ڴ�ռ�
        pt[i] = (char *)malloc(SIZE * sizeof(char));
        //���Խ���scanf("%s", pt[i]);
        while (isspace(ch = getchar()))				//������֮ǰ�Ŀո��
            continue;
        pt[i][0] = ch;								//�������ַ�
        j = 1;
        while (!isspace(pt[i][j] = getchar()))
            j++;
        pt[i][j] = '\0';							//��ĩβ�Ŀո��滻Ϊ\0'
    }

    return pt;
}

