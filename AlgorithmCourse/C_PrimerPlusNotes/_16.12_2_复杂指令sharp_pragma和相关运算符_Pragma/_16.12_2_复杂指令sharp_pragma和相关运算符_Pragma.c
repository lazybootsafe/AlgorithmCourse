#include <stdio.h>

#define TEST "��Ϣ�ı�"

/*
�����е�Ԥ����ָ���У�#pragma ָ���������ӵ��ˣ������������趨��������״̬������ָʾ���������һЩ�ض��Ķ�����
���ĳ��ò�����*/

//1.message���� -- �ڱ�����Ϣ��������������Ӧ����Ϣ
#if defined(TEST)
#pragma message(TEST)				//message����Ϣ�ı�������չ��ΪC�ַ����ĺ곣��

#endif

//2.#pragma once(�Ƚϳ��ã�-- ��ͷ�ļ�ֻ����һ��
#pragma once

//3.���α��뾯��
#pragma warning(disable: 4996)		//���Ա��Ϊ4996�ľ�����Ϣ
//_Pragma("warning(disable: 4996)")
//���ߣ��ڰ���stdio.h�ļ�֮ǰ��Ӷ���#define _CRT_SECURE_NO_WARNINGS

//��������ʱ��˵�ˣ���ⲻ��

/*
���䣺Ԥ�������������
1.�ַ����������#
2.���Է������ӷ�##
3.�Ƿ��������defined
4.����ָ������_Pragma -- �����������ַ�����������Ҳ����˵��������ַ����е�ת������ת��������������ַ���
*/

//_Pragma("nonstandrdtreatmenttypeB on")
//�ȼ���
//#pragma nonstandrdtreatmenttypeB on

//��Ϊ�������û��ʹ��#���ţ����Կ�����Ϊ��չ����һ���֣�
//#define PRAGMA(X) _Pragma(#X)
//#define LIMRG(X) PRAGMA(STDC CX_LIMITED_RANGE X)

//���ſ���ʹ��
//LIMRG(ON)
#define PRINT(X) printf(#X "\n")

int main(void)
{
	PRINT(ming);

	scanf("123");
	return 0;
}