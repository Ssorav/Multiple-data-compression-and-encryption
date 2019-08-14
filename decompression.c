#include"header.h"
#include"prototype.h"

void* decompression(void* ms)
{
	int fd1, cl ,fd3, count, i=0;
	char *ma, ch;
	
	printf("%s: BEGINS \n",__func__);
	ma = NULL;
	printf("enter the file name you want to decompress\n");
	fd1 = *((int*)(*func[4])("O_RDONLY"));
	printf("enter the key name of decompressed code\n");
	fd3 = *((int*)(*func[4])("O_RDONLY"));
	count = lseek(fd3,0,SEEK_END);
	lseek(fd3,0,SEEK_SET);
	while(1)
	{
		if(count!=0)
		{
			read(fd3,&ch,1);
			ma = realloc(ma,i+1);
			*(ma+i) = ch;
			count--;
			i++;
		}
		else
			break;
	}
        printf("%s: READS %s\n",__func__,ma);
        cl = *((int*)(*func[6])((void*)ma));
	printf("%s: %d\n",__func__,cl);
		
	switch(cl)
	{
		case 2:
			(*dcom2)(fd1,ma);
			break;
		case 3:
			(*dcom3)(fd1,ma);
			break;
		case 4:
			(*dcom4)(fd1,ma);
			break;
		case 5:
			(*dcom5)(fd1,ma);
			break;
		case 6:
			(*dcom6)(fd1,ma);
			break;
		case 7:
			(*dcom7)(fd1,ma);
			break;
	}
	


	printf("%s: END \n",__func__);
	close(fd1);
	close(fd3);
//	free(ma);
	return 0;
}
