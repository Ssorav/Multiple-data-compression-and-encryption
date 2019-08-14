#include"header.h"
#include"prototype.h"

void* compression()
{
	int fd, cl;
	char* ma;
/*	fd = (int *)malloc(1);
	if(!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	cl = (int *)malloc(1);
	if(!cl)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	*/
	printf("%s: BEGINS \n",__func__);
        printf("%s : enter the filename you want to compress\n", __func__);
        fd = *((int*)(*func[4])("O_RDONLY"));
        ma = (*func[5])((void*)&fd);
        printf("%s: READS %s\n",__func__,ma);
        cl = *((int*)(*func[6])((void*)ma));
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
	
	printf("%s: END \n",__func__);
	close(fd);
	free(ma);
	return 0;
}
