#include"header.h"
#include"prototype.h"

void* createmasterarray(void* ffd)
{
	int i, count, flag, l, fd, fd3;
	char ch;
	char *ma;
/*	fd = (int *)malloc(1);
	if(!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
*/
	fd = *((int*)ffd);
	printf("%s: BEGINS \n",__func__);
	ma = NULL;

	printf("%s: enter name of the master array \n",__func__);
	fd3 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	i = 0;
	count = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	while(1)
	{
		read(fd, &ch, 1);
		count--;
		if(count == 0)
			break;
		
		if((*uniq)(ma,ch))
		{
			ma = realloc(ma,i+1);
			*(ma + i++) = ch ;
			write(fd3,&ch,1);
		}
	}
	printf("%s: END \n",__func__);
	close(fd3);
	return (void*)ma;
}
