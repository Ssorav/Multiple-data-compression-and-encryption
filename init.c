#include"header.h"
#include"prototype.h"

int init()
{
	printf("%s: BEGINS \n",__func__);

	(func[0]) = Exit;
	(func[1]) = mainmenu;
	(func[2]) = compression;
	(func[3]) = decompression;
	(func[4]) = openfile;
	(func[5]) = createmasterarray;
	(func[6]) = codelength;


	com2 = compress2;
	com3 = compress3;
	com4 = compress4;
	com5 = compress5;
	com6 = compress6;
	com7 = compress7;
	dcom2 = decompress2;
	dcom3 = decompress3;
	dcom4 = decompress4;
	dcom5 = decompress5;
	dcom6 = decompress6;
	dcom7 = decompress7;
	uniq = unique;

	printf("%s: END \n",__func__);
	return 0;
}
