#include"header.h"
#include"prototype.h"

int decompress3(int fd1,char *ma)
{
	int count, j = 0,  fd2, i, len;
	unsigned char byt, ch, ch1, ch2, c, c1, c2;
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
	i = count;
	count = (i/3);
	if(i%3 != 0)
		count++;
	lseek(fd1,0,SEEK_SET);
//	len = strlen(ma);
	while(count>0)
	{
		read(fd1,&ch,1);
		read(fd1,&ch1,1);
		read(fd1,&ch2,1);
		while(j<8)
		{
			c = ch;
			c1 = ch1;
			c2 = ch2;
			switch(j)
			{
				case 0:
					c = c >> 5;
					printf("c : %d\n",c);
					break;
				case 1:
					c = c << 3;
					c = c >> 5;
					printf("c1 : %d\n",c);
					break;
				case 2:
					c = c << 6;
					c = c >> 5;
					c1 = c1 >> 7;
					c = c|c1;
					printf("c2 : %d\n",c);
					break;
				case 3:
					c = c^c;
					c1 = c1 << 1;
					c1 = c1 >> 5;
					c = c|c1;
					printf("c3 : %d\n",c);
					break;
				case 4:
					c = c^c;
					c1 = c1 << 4;
					c1 = c1 >> 5;
					c = c|c1;
					printf("c4 : %d\n",c);
					break;
				case 5:
					c = c^c;
					c1 = c1 << 7;
					c1 = c1 >> 5;
					c2 = c2 >> 6;
					c = c1|c2;
					printf("c5 : %d\n",c);
					break;
				case 6:
					c = c^c;
					c2 = c2 << 2;
					c2 = c2 >> 5;
					c = c|c2;
					printf("c6 : %d\n",c);
					break;
				case 7:
					c = c^c;
					c2 = c2 << 5;
					c2 = c2 >> 5;
					c = c|c2;
					printf("c7 : %d\n",c);
			}
			printf("count = %d\n",count);
			if(c == 7)
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
