
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 41

int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	char str3[SIZE] = "Change the world by programing!";
	//printf("%d", strlen(str3));							31

	system("color 0A");

	//1.�����ַ���
	strcpy_s(str1, SIZE, "MingCxx");				//Դ�ַ���������Ŀ��λ�ã��������ַ���				���뱣֤Ŀ��λ�����㹻�Ĵ洢�ռ�
	puts(str1);

	//2.�����ַ��������n���ַ���
	strncpy_s(str2, SIZE,"MingC " , 6);				/*��Դ�ַ���������Ŀ��λ�ã����n���ַ���
													���Դ�ַ�������С��n����Ŀ���ַ������Կ��ַ����ʣ��ռ䣻
													������ڵ���n�����ַ��������ơ�		��ʱ����ȫ�����Ŀ���ַ�����β��Ӧ����Ϊ���ַ�:
													dest[n] = '\0';		//n���ַ�����ӿ��ַ�������Ԫ����0��ʼ
													
													���������_s�Ľϰ�ȫ�汾���Զ������ַ������Խ����*/
	//str2[6] = '\0';								//���Խ��֪���þ���п��ޣ�������C���еı�׼strcpy()���������뱣֤�ַ������һ���ַ��ǿ��ַ�
	puts(str2);


	//3.�����ַ���
	strcat_s(str2, SIZE, str3);						//��Դ�ַ�������Ŀ���ַ�����β������׷�ӿ��ַ�
	puts(str2);
	//printf("%d", strlen(str2));							37

	//4.�����ַ��������n���ַ���
	strncat_s(str1, SIZE, str3, SIZE - 1);			//��Դ�ַ�������Ŀ���ַ�����β������׷�ӿ��ַ�
	puts(str1);

	//5.�Ƚ��ַ���
	printf("strcmp(\"ABC\",\"ABD\") is %d \n", strcmp("ABC", "ABD"));
													//�Ƚ����ַ���ÿһ���ַ� ANSCII֮�����0������ֵ��С��0���ظ�ֵ�����������������һ��(���ַ�Ҳ����Ƚ�)

	//6.�Ƚ��ַ��������n���ַ���
	printf("strncmp(\"ABC\",\"ABD\") is %d \n", strncmp("ABC", "ABD", 2));
													//�ȽϱȽ����ַ���ÿһ���ַ� ANSCII֮����Ƚ�ǰn���ַ����������ַ�Ϊֹ
	
	//7.���ҵ����ַ����ַ����е� ��λ��
	char *p = strchr("Fish.com", 'c');				//����Ŀ���ַ������״γ��ָ��ַ���λ�ã�����ָ���λ�õ�charָ�루���ָ�룩
	printf("The index of \'c\' in the \"Fish.com\" is %d <%p> \n", p - "Fish.com", p);		//��ӡ��Ԫ�����ַ������״γ���λ�õ�ƫ��


	//8.���ҿ����ַ����е���һ�ַ�
	char *p1 = strpbrk("Fish.com", "ABmn");			//����Ŀ���ַ������״γ���Դ�ַ�������һ�ַ���λ�ã�����ָ���λ�õ�charָ�루���ָ�룩
	printf("The index of someone character from \"ABmn\" in the \"Fish.com\" is %d <%p> \n", p1 - "Fish.com", p1);

	//9.���ҵ����ַ����ַ����е� ĩλ��
	char *p2 = strrchr("www.Fish.com", '.');		//����Ŀ���ַ������״γ��ָ��ַ���λ�ã����ش��ַ����е����λ����һֱ���ַ��������������ַ���Ҳ���Ǹ�λ�õ�ָ�루���ָ�룩��
	printf("The index of \'.\' in the \"www.Fish.com\" is %d <%p> \n", p2 - "www.Fish.com", p2);		//��ӡ��Ԫ�����ַ�����������λ�õ�ƫ��

	//10.�������ַ���
	char *p3 = strstr("www.Fish.com", "Fish");		//����Ŀ���ַ������״γ��ָ����ַ�����λ�ã�����ָ���λ�õ�charָ�루���ָ�룩
	printf("The index of \'Fish\' in the \"www.Fish.com\" is %d <%p> \n", p3 - "www.Fish.com", p3);		//��ӡ�����ַ������ַ������״γ���λ�õ�ƫ��
	p3 = strstr("www.Fish.com", "fish");
	printf("The index of \'fish\' in the \"www.Fish.com\" is %d <%p> \n", p3 - "www.Fish.com", p3);

	//11.�ַ�������
	printf("The length of \"MingC\" is %d\n", strlen("MingC"));		//�������ֽ�Ϊ��λ���ַ������ȣ����������ַ���


	//12.д���ʽ�����ݵ��ַ���
	sprintf_s(str1, SIZE, "%s come up! %d 123", p2, 23423432);
	puts(str1);

	getchar();
	return 0;
}
