#include"header.h"
#include"prototype.h"

int compress6(int fd,char *ma)
{
	int i, j = 0, fd1, k, count;
	unsigned char byt, byt1, byt2, ch ,c ,c1 ,c2 ;
	printf("%s: BEGINS \n",__func__);
	count = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("write the file name in which you want to store the compresssed code\n");
/*	fd1 = (int*)malloc(1);
	if(!fd1)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
*/
	k = count;
	fd1 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	while(count > 0)
	{	
		
		byt = byt^byt;
		byt1 = byt1^byt1;
		byt2 = byt2^byt2;
		while(j < 4)
		{
			read(fd,&ch,1);
			count--;
			for(i = 0 ; i < strlen(ma) ; i++)
			{
				if(ch == *(ma + i))
					break;
			}
			printf("ch%d = %c\n", j, ch);
			if(((j == 0)||(j == 1)||(j == 2)||(j == 3)) && (count == 0))
			{
				i = 63;
				switch(j)
				{
					case 0:
						sprintf(&c,"%c",i);
						c = c << 2;
						byt = byt|c;
						break;
					case 1:
						sprintf(&c,"%c",i);
						c = c << 2;
						c = c >> 6;
						byt = byt|c;
						sprintf(&c1,"%c",i);
						c1 = c1 << 4;
						byt1 = byt1|c1;
						break;
					case 2:
						sprintf(&c1,"%c",i);
						c1 = c1 << 2;
						c1 = c1 >> 4;
						byt1 = byt1|c1;
						sprintf(&c2,"%c",i);
						c2 = c2 << 6;
						byt2 = byt2|c2;
						break;
					case 3:
						sprintf(&c2,"%c",i);
						c2 = c2 << 2;
						c2 = c2 >> 2;
						byt2 = byt2|c2;
						//break;
				}
			}
			else
			{
				switch(j)
				{
					case 0:
						sprintf(&c,"%c",i);
						c = c << 2;
						byt = byt|c;
						break;
					case 1:
						sprintf(&c,"%c",i);
						c = c << 2;
						c = c >> 6;
						byt = byt|c;
						sprintf(&c1,"%c",i);
						c1 = c1 << 4;
						byt1 = byt1|c1;
						break;
					case 2:
						sprintf(&c1,"%c",i);
						c1 = c1 << 2;
						c1 = c1 >> 4;
						byt1 = byt1|c1;
						sprintf(&c2,"%c",i);
						c2 = c2 << 6;
						byt2 = byt2|c2;
						break;
					case 3:
						sprintf(&c2,"%c",i);
						c2 = c2 << 2;
						c2 = c2 >> 2;
						byt2 = byt2|c2;
						//break;
				}
			}
			j++;
		}
		printf("byt: %d\n",byt);
		printf("byt1: %d\n",byt1);
		printf("byt2: %d\n",byt2);
		j = 0;
		write(fd1,&byt,1);
		write(fd1,&byt1,1);
		write(fd1,&byt2,1);
		if(count == 0)
			break;

	/*	if((k%2) != 0)
		{
			 i = 15;
		//	c = (char)i;
			sprintf(&c,"%c",i);
			c = c << 4;
			byt = byt|c;
			write(fd1,&byt,1);
		}*/
	}
	printf("%s: END \n",__func__);
	close(fd1);
	return 0;
}
