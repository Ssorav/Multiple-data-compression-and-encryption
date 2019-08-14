#include"header.h"
#include"prototype.h"

int compress5(int fd,char *ma)
{
	int i, j = 0, fd1, count;
	unsigned char byt, byt1, byt2, byt3, byt4, ch ,c;
	printf("%s: BEGINS \n",__func__);
	count = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("write the file name in which you want to store the compresssed code\n");
	fd1 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	while(count > 0)
	{	
		
		byt = byt^byt;
		byt1 = byt1^byt1;
		byt2 = byt2^byt2;
		byt3 = byt3^byt3;
		byt4 = byt4^byt4;
		while(j < 8)
		{
			read(fd,&ch,1);
			count--;
			for(i = 0 ; i < strlen(ma) ; i++)
			{
				if(ch == *(ma + i))
					break;
			}
			printf("ch%d = %c\n", j, ch);
			if((count == 0))
			{
				i = 31;
				switch(j)
				{
					case 0:
						sprintf(&c,"%c",i);
						c = c << 3;
						byt = byt|c;
						goto RET;
					case 1:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 5;
						byt = byt|c;
						sprintf(&c,"%c",i);
						c = c << 6;
						byt1 = byt1|c;
						goto RET;
					case 2:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 2;
						byt1 = byt1|c;
						goto RET;
					case 3:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 7;
						byt1 = byt1|c;
						sprintf(&c,"%c",i);
						c = c << 4;
						byt2 = byt2|c;	
						goto RET;
					case 4:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 4;
						byt2 = byt2|c;
						sprintf(&c,"%c",i);
						c = c << 7;
						byt3 = byt3|c;
						goto RET;
					case 5:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 1;
						byt3 = byt3|c;
						goto RET;
					case 6:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 6;
						byt3 = byt3|c;
						sprintf(&c,"%c",i);
						c = c << 5;
						byt4 = byt4|c;
						goto RET;
					case 7:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 3;
						byt4 = byt4|c;
						goto RET;
				}
			}
			else
			{
				switch(j)
				{
					case 0:
						sprintf(&c,"%c",i);
						c = c << 3;
						byt = byt|c;
						break;
					case 1:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 5;
						byt = byt|c;
						sprintf(&c,"%c",i);
						c = c << 6;
						byt1 = byt1|c;
						break;
					case 2:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 2;
						byt1 = byt1|c;
						break;
					case 3:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 7;
						byt1 = byt1|c;
						sprintf(&c,"%c",i);
						c = c << 4;
						byt2 = byt2|c;	
						break;
					case 4:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 4;
						byt2 = byt2|c;
						sprintf(&c,"%c",i);
						c = c << 7;
						byt3 = byt3|c;
						break;
					case 5:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 1;
						byt3 = byt3|c;
						break;
					case 6:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 6;
						byt3 = byt3|c;
						sprintf(&c,"%c",i);
						c = c << 5;
						byt4 = byt4|c;
						break;
					case 7:
						sprintf(&c,"%c",i);
						c = c << 3;
						c = c >> 3;
						byt4 = byt4|c;
						break;
				}
			}
			j++;
		}
RET:
		printf("byt: %d\n",byt);
		printf("byt1: %d\n",byt1);
		printf("byt2: %d\n",byt2);
		printf("byt3: %d\n",byt3);
		printf("byt4: %d\n",byt4);
		switch(j)
		{
			case 0:
				write(fd1,&byt,1);
				break;
			case 1:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				break;
			case 2:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				break;
			case 3:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				write(fd1,&byt2,1);
				break;
			case 4:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				write(fd1,&byt2,1);
				write(fd1,&byt3,1);
				break;
			case 5:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				write(fd1,&byt2,1);
				write(fd1,&byt3,1);
				break;
			default:
				write(fd1,&byt,1);
				write(fd1,&byt1,1);
				write(fd1,&byt2,1);
				write(fd1,&byt3,1);
				write(fd1,&byt4,1);
				break;
		}
		j = 0;
		if(count == 0)
			break;
	}
	printf("%s: END \n",__func__);
	close(fd1);
	return 0;
}
