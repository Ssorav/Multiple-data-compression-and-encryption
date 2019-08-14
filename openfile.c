#include"header.h"
#include"prototype.h"

void* openfile(void* mode)
{
	int *fd,count;
	char ch;
	char *filename;
	fd = (int*)malloc(1);
	if(!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	filename = (char*)malloc(20);
	if(!filename)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("%s: BEGINS \n",__func__);

	scanf(" %s", filename);
	if(strncmp((char*)mode,"O_WRONLY|O_CREAT",16) == 0)
		*fd = open(filename,O_WRONLY|O_CREAT);
	else if(strncmp((char*)mode,"O_WRONLY",8) == 0)
		*fd = open(filename,O_WRONLY);
	else if(strncmp((char*)mode,"O_RDONLY",8) == 0)
		*fd = open(filename,O_RDONLY);
	if(*fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("file discriptor no %d is opened\n",*fd);	
	printf("%s: END \n",__func__);
	return (void*)fd;
}
