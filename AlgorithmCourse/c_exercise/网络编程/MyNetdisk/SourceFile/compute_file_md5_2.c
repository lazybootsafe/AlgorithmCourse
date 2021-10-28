#include "../HeaderFile/md5.h"
#include "../HeaderFile/unixhead.h"
#define READ_DATA_SIZE	4096
#define MD5_SIZE		16
#define MD5_STR_LEN		(MD5_SIZE * 2)

int compute_file_md5_2(int fd,char* md5_str,int size)
{
    int i;
	int ret;
	unsigned char data[READ_DATA_SIZE];
	unsigned char md5_value[MD5_SIZE];
	MD5_CTX md5;


	// init md5
	MD5Init(&md5);

    int total = 0;
    while(total < size)
	{
        if(size - total > 4096)
		    ret = read(fd, data, 4096);
        else
            ret = read(fd,data,size - total);
		if (-1 == ret)
		{
			perror("read");
			close(fd);
			return -1;
		}
		MD5Update(&md5, data, ret);
        total += ret;
	}


	MD5Final(&md5, md5_value);

	// convert md5 value to md5 string
	for(i = 0; i < MD5_SIZE; i++)
	{
		snprintf(md5_str + i*2, 2+1, "%02x", md5_value[i]);
	}

	return 0;

}
