//names_st.h -- ���ж�ΰ����������޶��汾

#ifndef NAMES_H_
#define NAMES_H_

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

#endif // !NAMES_H_