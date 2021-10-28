#include "../HeaderFile/database.h"
int connect_mysql(MYSQL** connect)
{
	const char *server = "localhost";
	const char *user = "root";
	const char *password = "Ph981030";
	const char *database = "MyNetdisk";

	*connect = mysql_init(NULL);
    if(!connect)
    {
        printf("MySQL init failed\n");
        return -1;
    }

	if(!mysql_real_connect(*connect, server, user, password, database, 0, NULL, 0))
	{
		printf("Error connecting to database: %s\n", mysql_error(*connect));
		return -1;
	}
	return 0;
}
