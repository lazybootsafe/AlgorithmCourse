//names_st�ṹ��ͷ�ļ�

//����
#define SLEN 32

//�ṹ����
struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

//���Ͷ���
typedef struct names_st names;

//����ԭ��
void get_names(names *);
void show_names(const names *);

/*ע�⣺ͷ�ļ������ݲ��ǿ�ִ�д��룬���Ǳ��������ڲ�����ִ�д������Ϣ��*/