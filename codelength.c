#include"header.h"
#include"prototype.h"

void* codelength(void *fma)
{
	int l, *cl;
	char *ma;
	printf("%s: BEGINS \n",__func__);
	cl = (int*)malloc(1);	
	if(!cl)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

/*	ma = (char*)malloc(sizeof(char)*128);
	if(!ma)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
*/	ma = (char*)fma;
	l = strlen(ma);
	if(l < 4)
		*cl = 2;
	else if(l < 8)
		*cl = 3;
	else if(l < 16)
		*cl = 4;
	else if(l < 32)
		*cl = 5;
	else if(l < 64)
		*cl = 6;
	else if(l < 128)
		*cl = 7;
	printf("%s: END \n",__func__);
	return (void*)cl;
}
