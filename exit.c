#include"header.h"
#include"prototype.h"

void* Exit()
{
	printf("%s: BEGINS \n",__func__);
	exit(EXIT_SUCCESS);
	printf("%s: END \n",__func__);
	return 0;
}
