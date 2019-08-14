#include"header.h"
#include"prototype.h"

void* mainmenu()
{
	int choice;
	printf("%s: BEGINS \n",__func__);
	printf("%s: enter 0 for exit \n",__func__);
	printf("%s: enter 2 for compression \n",__func__);
	printf("%s: enter 3 for decompression \n",__func__);
	scanf("%d", &choice);
	if((choice>=0 && choice<=3) && choice!=1 )
		(*func[choice])(0);
	else
		printf("INVALID CHOICE\n");
	printf("%s: END \n",__func__);
	return 0;
}
