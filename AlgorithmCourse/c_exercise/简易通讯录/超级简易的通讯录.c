#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void save(char *area,int n); 
void show(char *area,int n); 
struct s_list
{
	char name[20];
	char tel[15];
	char adr[50]; 
}list[200];
int main()
{
	char *area,areas[30];
	int n; 
	FILE *f;
	if(fopen("D:\\list_xl","r")==NULL)
	{
		printf("��ӭ��һ��ʹ�ñ�ͨѶ¼\n������ͨѶ¼����ľ��Ե�ַ\n");
		scanf("%s",&areas);
		f=fopen("D:\\list_xl","w");
		fwrite(areas,strlen(areas),1,f); 
		fclose(f); 
	} 
	else
	{
		
		f=fopen("D:\\list_xl","r");
		fseek( f , 0 , SEEK_END );
        int file_size;
        file_size = ftell( f);
        fseek( f, 0 , SEEK_SET);
        area=  (char *)malloc( file_size * sizeof( char ) );
		fread(area,file_size,1,f); 
		fclose(f); 
		printf("�������һ�δ�����ͨѶ¼\n��Ҫ��������ͨѶ¼ɾ��d��Ŀ¼��list_xl�ļ����ɣ�\n"); 
	} 
label:
	printf("----�̹����ļ���ͨѶ¼xl----\n1-�洢\n2-��ʾ\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("\n����洢��ϵ����Ϣ������\n");
	scanf("%d",&n);
	save(area,n);
	goto label;
	}
	else if(choice==2) 
	{
		printf("\n������ʾ��ϵ����Ϣ������\n");
	scanf("%d",&n);
	show(area,n);
	goto label;}
	else
	{printf("\n������δ����\n");
	goto label;}
	return 0;	 
} 
void save(char *area,int n)
{
	int i,p;
	FILE *f; 
	if((f=fopen(area,"a"))==NULL)
	{
		if((f=fopen(area,"w"))==NULL)
		{ 
		printf("\n�ļ�����ʧ�ܣ�\n");
		exit(0);} 
	} 
	printf("--��������ϵ���������绰����ַ--"); 
	for(i=0;i<n;i++)
	{
		printf("\n��%d����ϵ��\n",i+1);
		scanf("%s%s%s",&list[i].name,&list[i].tel,&list[i].adr); 
		p=fwrite(&list[i],sizeof(struct s_list),1,f);
		if(p!=1)
		{
			printf("�ļ�д��ʧ��!");
			exit(0); 
		}
		else
		{
			printf("�ļ�д��ɹ���"); 
		} 
		 
	}
	fclose(f); 
	 
} 
void show(char *area,int n)
{
	FILE *f; 
	int i; 
	if((f=fopen(area,"r"))==NULL)
	{
		printf("\n�ļ���ȡʧ�ܣ�");
		exit(0); 
	} 
	
	for (i=0;i<n;i++)
	{ 
	fread(&list[i],sizeof(struct s_list),1,f);
	printf("\n������%s\n�绰��%s\n��ַ��%s\n-------\n",list[i].name,list[i].tel,list[i].adr);
	}
	fclose(f); 
	
}
 