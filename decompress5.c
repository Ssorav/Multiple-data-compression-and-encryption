#include"header.h"
#include"prototype.h"

int decompress5(int fd1,char *ma)
{
	int count, j = 0,  fd2, i, len;
	unsigned char byt, ch, ch1, ch2, ch3, ch4, c, c1, c2, c3, c4;
	printf("%s: BEGINS \n",__func__);
	printf("enter the file name in which you want to write decompressed code\n");
	fd2 = *((int*)(*func[4])("O_WRONLY|O_CREAT"));
	printf("fd2: %d\n",fd2);
	count = lseek(fd1,0,SEEK_END);
	i = count;
	count = (i/5);
	if(i%5 != 0)
		count++;
	lseek(fd1,0,SEEK_SET);
	while(count>0)
	{
		read(fd1,&ch,1);
		read(fd1,&ch1,1);
		read(fd1,&ch2,1);
		read(fd1,&ch3,1);
		read(fd1,&ch4,1);
		while(j<8)
		{
			c = ch;
			c1 = ch1;
			c2 = ch2;
			c3 = ch3;
			c4 = ch4;
			switch(j)
			{
				case 0:
					c = c >> 3;
					printf("c : %d\n",c);
					break;
				case 1:
					c = c << 5;
					c = c >> 3;
					c1 = c1 >> 6;
					c = c|c1;
					printf("c1 : %d\n",c);
					break;
				case 2:
					c = c^c;
					c1 = c1 << 2;
					c1 = c1 >> 3;
					c = c|c1;
					printf("c2 : %d\n",c);
					break;
				case 3:
					c = c^c;
					c1 = c1 << 7;
					c1 = c1 >> 3;
					c2 = c2 >> 4;
					c = c1|c2;
					printf("c3 : %d\n",c);
					break;
				case 4:
					c = c^c;
					c2 = c2 << 4;
					c2 = c2 >> 3;
					c3 = c3 >> 7;
					c = c2|c3;
					printf("c4 : %d\n",c);
					break;
				case 5:
					c = c^c;
					c3 = c3 << 1;
					c3 = c3 >> 3;
					c = c|c3;
					printf("c5 : %d\n",c);
					break;
				case 6:
					c = c^c;
					c3 = c3 << 6;
					c3 = c3 >> 3;
					c4 = c4 >> 5;
					c = c3|c4;
					printf("c6 : %d\n",c);
					break;
				case 7:
					c = c^c;
					c4 = c4 << 3;
					c4 = c4 >> 3;
					c = c|c4;
					printf("c7 : %d\n",c);
			}
			printf("count = %d\n",count);
			if(c == 31)
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
