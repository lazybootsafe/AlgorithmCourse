#include <stdio.h>
#include <stdlib.h>

void why_me(void);

int main(void)
{																	
	system("color 0A");

//#pragma c9x on

#ifdef __STDC__
#if __STDC__ == 1												//__STDC__:			����Ϊ1ʱ����ʾ��ʵ����ѭC��׼��
	printf("STDC.\n");	
#else
	printf("not STDC.\n");
#endif // __STDC__
#else
#line 666 "program.c"											//#line:			������Ԥ�����__LINE__������кţ���һ�У���__FILE__������ļ���
//#error Not C99																	//#errorָ�������������һ��������Ϣ����Ϣ�а���ָ�����ı������ܵĻ����������Ӧ���жϡ������޷���ָ���������ע�ͣ������ı�������Ϊ������Ϣ��
	printf("__STDC__ is not exist.\n");
#endif // __STDC__

#ifdef __FILE__
	printf("This file is %s.\n", __FILE__);						//__FILE__:			��ǰԴ�ļ����ļ������ַ�������
#endif // !__FILE__

#ifdef __DATE__
	printf("This date is %s.\n", __DATE__);						//__DATE__:			����Ԥ��������ڣ�"Mmm dd yyyy"��ʽ���ַ������֣�
#endif // __DATE__

#ifdef __TIME__
	printf("This time is %s.\n", __TIME__);						//__TIME__��			Դ�ļ��ı���ʱ�䣨"hh: mm: ss"��ʽ���ַ������֣�
#endif // __TIME__

#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ == 199901L 
	printf("C99: %d.\n", __STDC_VERSION__);						//__STDC_VERSION__:	ΪC99ʱ����Ϊ199901L
#else
	printf("Not C99: %d\n", __STDC_VERSION__);
#endif // __STDC_VERSION__ == 199901L 
#else
	printf("Not C99.\n");
#endif // defined(__STDC_VERSION__)

#ifdef __STDC_HOSTED__
#if __STDC_HOSTED__ == 1
	printf("Local environment.\n", __STDC_HOSTED__);			//__STDC_HOSTED__:	Ϊ������������Ϊ1��������0
#else
	printf("IS not local environment.\n");
#endif // __STDC_HOSTED__ == 1
#endif // __STDC_HOSTED__

#ifdef __LINE__
	printf("This is line %d.\n", __LINE__);						//__LINE__:			Դ�ļ��е�ǰ����е��к�
#endif // __LINE__

#ifdef __func__
	printf("This function is %s.\n", __func__);					//__func__:			C99�ṩ��һ��Ԥ�����ʶ������չ��Ϊһ�����������ַ�����
																					//�ñ�ʶ�����к��������򣬶��걾���Ͼ����ļ�����������__func__��C���Ե�Ԥ�����ʶ��������Ԥ����ꡣ*/
#endif // __func__		

#ifdef __FUNCTION__												//__FUNCTION__:		��GCC��MS�ı������У�__FUNCTION__��__func__�ı�����ǰ����������ʵ�֣���������֮�£����ɱ��뿪��disable֮��������������C���Ա�׼��
	printf(":This function is %s().\n", __FUNCTION__);
#endif //__FUNCTION__
	why_me();
	 
	getchar();
	return 0;
}

void why_me(void)
{
#ifdef __func__
	printf(".This function is %s.\n", __func__);
#endif // __LINE__
#ifdef __FUNCTION__
	printf(":This function is %s().\n", __FUNCTION__);
#endif //__FUNCTION__

#ifdef __LINE__
	printf("This is line %d.\n", __LINE__);
#endif // __LINE__
}