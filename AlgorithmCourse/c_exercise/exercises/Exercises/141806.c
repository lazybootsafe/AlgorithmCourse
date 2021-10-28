#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int   id;
	char  fname[20];
	char  lname[20];
	int   start_num;
	int   hit_num;
	int   base_num;
	int   RBI;
	float BABIP;
}PLAYER;

PLAYER player_list[19];

void read_data(PLAYER list[], FILE *pFile);
void set_babip(PLAYER list[]);
void get_info14a(PLAYER list[]);

int main(void)
{
	FILE *pFile;
	if ((fopen_s(&pFile, "data.txt", "r")) != 0)
	{
		printf("Can't open %s\n", "data.txt");
		exit(EXIT_FAILURE);
	}
	read_data(player_list, pFile);
	set_babip(player_list);
	get_info14a(player_list);
	fclose(pFile);

	return 0;
}

void read_data(PLAYER list[], FILE *pFile)
{
	if (pFile == NULL)
	{
		puts("Can't open the file.");
		exit(EXIT_FAILURE);
	}
	int id, start_num, hit_num, base_num, RBI;
	//float BABIP;
	char fname[20], lname[20];
	int read_count = 1;
	while (1)
	{
		read_count = fscanf_s(pFile, "%d %s %s %d %d %d %d",
			&id, fname, _countof(fname), lname, _countof(lname),
			&start_num, &hit_num, &base_num, &RBI);
		if (read_count < 7)
			break;
		//strcpy(list[id].fname, fname);
		strcpy_s(list[id].fname, sizeof list[id].fname, fname);
		//strcpy(list[id].lname, lname);
		strcpy_s(list[id].lname, sizeof list[id].lname, lname);
		list[id].id = id;
		list[id].start_num += start_num;
		list[id].hit_num += hit_num;
		list[id].base_num += base_num;
		list[id].RBI += RBI;
	}
}

void set_babip(PLAYER list[])
{
	for (int i = 0; i < 19; i++)
		list[i].BABIP = (float)list[i].hit_num / (float)list[i].start_num;
}

void get_info14a(PLAYER list[])
{
	puts("ID: FIRST_NAME.LAST_NAME START HIT_NUM BASE_NUM RBI BABIP");
	for (int i = 0; i < 19; i++)
	{
		printf("%2d %10s.%-10s %5d %5d %7d %6d %.2f\n",
			list[i].id, list[i].fname,
			list[i].lname, list[i].start_num,
			list[i].hit_num, list[i].base_num,
			list[i].RBI, list[i].BABIP);
	}
}

#endif // 1