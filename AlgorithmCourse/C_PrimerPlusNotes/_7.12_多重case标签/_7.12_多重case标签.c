#include <stdio.h>

int main(void)
{
	//ͳ�������ַ�����Ԫ����ĸ��Ŀ

	//char ch;
	//int a_ct, e_ct, i_ct, o_ct, u_ct;

	//a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	//printf("Enter some text(# to quit):\n");
	//while((ch = getchar())!= '#')
	//{
	//	switch (ch)
	//	{
	//	case 'a':
	//	case 'A':
	//		a_ct++;
	//		break;
	//	case 'e':
	//	case 'E':
	//		e_ct++;
	//		break;
	//	case 'i': //���chs��i��switch��λ��case 'i'��ǩ����Ϊû��break��ñ�ǩ���������Գ������̼���ǰ������һ����䣬��i_ct++;���ch��I����������ֱ�Ӷ�λ��������䡣�����ϣ�������ǩ��ָ����ͬ�����
	//	case 'I':
	//		i_ct++;
	//		break;
	//	case 'o':
	//	case 'O':
	//		o_ct++;
	//		break;
	//	case 'u':
	//	case 'U':
	//		u_ct++;
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//printf("number of vowels; A E I O U\n");
	//printf("                  %d %d %d %d %d\n",
		//a_ct, e_ct, i_ct, o_ct, u_ct);

	//���ߣ�������ctype.h��toupper()ת������д��ĸ��������ر�ǩ
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("Enter some text(# to quit):\n");
	while ((ch = getchar()) != '#')
	{
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			a_ct++;
			break;
		case 'E':
			e_ct++;
			break;
		case 'I':
			i_ct++;
			break;
		case 'O':
			o_ct++;
			break;
		case 'U':
			u_ct++;
			break;
		default:
			break;
		}
	}
	printf("number of vowels; A E I O U\n");
	printf("                  %d %d %d %d %d\n",
		a_ct, e_ct, i_ct, o_ct, u_ct);

	getchar();
	getchar();
	return 0;
}