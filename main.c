#include"header.h"
#include"prototype.h"

int main()
{
	int fd,	cl, fd1;
	char *ma, reply;
	printf("%s: BEGINS \n",__func__);
	
	init();
	while(1)
		(*func[1])(0);
/*	printf("%s : enter the filename you want to compress\n", __func__);	
	fd = (*opfi)("O_RDONLY");
	ma = (*crma)(fd);
	printf("%s: READS %s\n",__func__,ma);
	cl = (*clength)(ma);
	switch(cl)
	{
		case 2:
			(*com2)(fd,ma);
			break;
		case 3:
			(*com3)(fd,ma);
			break;
		case 4:
			(*com4)(fd,ma);
			break;
		case 5:
			(*com5)(fd,ma);
			break;
		case 6:
			(*com6)(fd,ma);
			break;
		case 7:
			(*com7)(fd,ma);
			break;
	}
	printf("do you want to perform decompress operation?(y/n)\n");
	scanf("%s", &reply);
	if(reply == 'y')
	{
		printf("enter the file name you want to decompress\n");
		fd1 = (*opfi)("O_RDONLY");
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
		close(fd1);
	
	}
	close(fd);
	free(ma);*/
	printf("%s: END \n",__func__);
	return 0;
}
