#include"header.h"
#include"prototype.h"

int compress2(int fd,char *ma)
{
	int i, j = 0, fd1, k, count, flag;
	unsigned char byt, ch ,c ;
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
				i = 3;
				
				sprintf(&c,"%c",i);
				switch(j)
				{
					case 0:
						c = c << 6;
						break;
					case 1:
						c = c << 6;
						c = c >> 2;
						break;
					case 2:			
						c = c << 6;
						c = c >> 4;
						break;
					case 3:
						c = c << 6;
						c = c >> 6;
						break;
				}
				byt = byt|c;
				break;
			//	c = (char)i;			
			}
			
			sprintf(&c,"%c",i);
			switch(j)
			{
				case 0:
					c = c << 6;
					break;
				case 1:
					c = c << 6;
					c = c >> 2;
					break;
				case 2:			
					c = c << 6;
					c = c >> 4;
					break;
				case 3:
					c = c << 6;
					c = c >> 6;
					break;
			}
			byt = byt|c;
			j++;
		}
		printf("%d\n",byt);
		j = 0;
		write(fd1,&byt,1);
		if(count == 0)
			break;
/*
		if(((k%4) == 1))
		{
			 i = 15;
		//	c = (char)i;
			sprintf(&c,"%c",i);
			for(i = 0 ; i < 3 ; i++)
			{
				c = c << 2;
				i++;
			}
			
			byt = byt|c;
			write(fd1,&byt,1);
		}*/
	}
	printf("%s: END \n",__func__);
	close(fd1);
	return 0;
}
