#include <stdarg.h>

int main(void)
{
	int age;		//����
	float assets;	//����
	char pet[30];	//char����

	/*scanf("%d %f", &age, &assets)ʹ�ÿ��ַ����ո��Ʊ�������з�����������������ֳɼ����ֶΣ�
	����ת��˵�����������ֶ�ƥ�䣬�ֶ�֮��Ŀ��ַ��Զ�����
	Ҳ���ǣ�����������ֶ�ʱ��ÿ���ֶ�֮���ÿ��ַ�������
	scanf���Զ��ָ�ƥ����ת��˵������Ӧ���ֶ����ݣ��洢��ָ���ı�����ַ*/
	printf("Enter your age, assets, and favourte pet.\n");
	scanf("%d %f", &age, &assets);//�Ա���ʹ��&
	scanf("%s", pet);			  //��char���鲻ʹ��&
	printf("%d $%.2f %s", age, assets, pet);
	
	getchar();
	getchar();
	return 0;
}