#include"header.h"
#include"prototype.h"

int decompress4(int fd1,char *ma)
{
	int count, j = 0,  fd2, i, len;
	unsigned char byt, ch, c;
	printf("%s: BEGINS \n",__func__);
/*	fd2 = (int*)malloc(1);
	if(!fd2)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
*/	printf("enter the file name in which you want to write decompressed code\n");
	fd2 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	printf("fd2: %d\n",fd2);
	count = lseek(fd1,0,SEEK_END);
	lseek(fd1,0,SEEK_SET);
//	len = strlen(ma);
	while(count>0)
	{
	//	if(count!=0)
	//	{
				read(fd1,&ch,1);
		//		byt = byt^byt;
		 	while(j<2)
			{
				c = ch;
				if(j == 0)
				{
					c = c >> 4;
					printf("c : %d\n",c);
				}
				if(j == 1)
				{
					c = c << 4;
					c = c >> 4;
					printf("c : %d\n",c);
				}
				if(c == 0X0F)
				{
					printf("successfully decompressed\n");
				}	
				for(i = 0 ; i < strlen(ma) ; i++)
				{
					if(i == c)
						break;
				}
				byt = *(ma + i);
				printf("decompressed character at j = %d is : %c\n",j ,byt);
				j++;
				write(fd2,&byt,1);
			}
				count--;
			j=0;
	//	}
	//	else

	//		break;
	}
	printf("ch : %d",ch);
	printf("%s: END \n",__func__);
	close(fd2);
	return 0;
}
