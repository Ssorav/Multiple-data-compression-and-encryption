#include"header.h"
#include"prototype.h"

int decompress7(int fd1,char *ma)
{
	int count, j = 0,  fd2, i, len;
	unsigned char byt, ch, ch1, ch2, ch3, ch4, ch5, ch6, c, c1, c2, c3, c4, c5, c6;
	printf("%s: BEGINS \n",__func__);
	printf("enter the file name in which you want to write decompressed code\n");
	fd2 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	printf("fd2: %d\n",fd2);
	count = lseek(fd1,0,SEEK_END);
	i = count;
	count = (i/7);
	if(i%7 != 0)
		count++;
	lseek(fd1,0,SEEK_SET);
	while(count>0)
	{
		read(fd1,&ch,1);
		read(fd1,&ch1,1);
		read(fd1,&ch2,1);
		read(fd1,&ch3,1);
		read(fd1,&ch4,1);
		read(fd1,&ch5,1);
		read(fd1,&ch6,1);
		while(j<8)
		{
			c = ch;
			c1 = ch1;
			c2 = ch2;
			c3 = ch3;
			c4 = ch4;
			c5 = ch5;
			c6 = ch6;
			switch(j)
			{
				case 0:
					c = c >> 1;
					printf("c : %d\n",c);
					break;
				case 1:
					c = c << 7;
					c = c >> 1;
					c1 = c1 >> 2;
					c = c|c1;
					printf("c1 : %d\n",c);
					break;
				case 2:
					c = c^c;
					c1 = c1 << 6;
					c1 = c1 >> 1;
					c2 = c2 >> 3;
					c = c1|c2;
					printf("c2 : %d\n",c);
					break;
				case 3:
					c = c^c;
					c2 = c2 << 5;
					c2 = c2 >> 1;
					c3 = c3 >> 4;
					c = c2|c3;
					printf("c3 : %d\n",c);
					break;
				case 4:
					c = c^c;
					c3 = c3 << 4;
					c3 = c3 >> 1;
					c4 = c4 >> 5;
					c = c3|c4;
					printf("c4 : %d\n",c);
					break;
				case 5:
					c = c^c;
					c4 = c4 << 3;
					c4 = c4 >> 1;
					c5 = c5 >> 6;
					c = c4|c5;
					printf("c5 : %d\n",c);
					break;
				case 6:
					c = c^c;
					c5 = c5 << 2;
					c5 = c5 >> 1;
					c6 = c6 >> 7;
					c = c5|c6;
					printf("c6 : %d\n",c);
					break;
				case 7:
					c = c^c;
					c6 = c6 << 1;
					c6 = c6 >> 1;
					c = c|c6;
					printf("c7 : %d\n",c);
			}
			printf("count = %d\n",count);
			if(c == 127)
			{
				printf("successfully decompressed\n");
				break;
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
			//printf("count = %d",count);
		j=0;
	}
	//	else

	//		break;
	
	//printf("ch : %d",ch);
	printf("%s: END \n",__func__);
	close(fd2);
	return 0;
}
