#include"header.h"
#include"prototype.h"

int unique(char *ma,char ch)
{
	int l;
	printf("%s: BEGINS \n",__func__);

	if(!ma )
		return 1 ;
	else
	{      	
		for(l = 0 ; l < strlen(ma) ; l++)
		{
			if(ch == *(ma + l))
			{
				return 0;
			}
		}
		return 1;
	}
	printf("%s: END \n",__func__);
	
}
