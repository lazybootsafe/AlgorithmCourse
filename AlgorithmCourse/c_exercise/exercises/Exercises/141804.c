#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct user
//{
//	char fname[15];
//	char mname[15];
//	char lname[15];
//};
struct user_id
{
	char sid[30];
	//struct user name;
	
	struct user
	{
		char fname[15];
		char mname[15];
		char lname[15];
	};
};
const struct user_id user_list[5] = {
	{ "302039823", { "Flossie", "Mike", "Dribble" }}
};

//void print_user_id(struct user_id list[], int num);
void print_user_id(struct user_id user);

int main(void)
{
	puts("Test to print struct contents:");
	//print_user_id(user_list, 5);
	print_user_id(user_list[0]);

	return 0;
}

//void print_user_id(struct user_id list[], int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		if (strlen(list[i].sid) < 9)
//			break;
//		printf("No.%d: %s, ", i + 1, list[i].name.lname);
//		printf("%s ", list[i].name.fname);
//		if (strlen(list[i].name.mname) > 0)
//			printf("%c. ", list[i].name.mname[0]);
//		printf("-- %s\n", list[i].sid);		
//	}
//}

void print_user_id(struct user_id user)
{
	if (strlen(user.sid) < 9)
		return;
	printf("USERID: %s, ", user.lname);
	printf("%s ", user.fname);
	if (strlen(user.mname) > 0)
		printf("%c. ", user.mname[0]);
	printf("-- %s\n", user.sid);
}

#endif // 1