int compress2(int, char*);
int (*com2)(int, char*);
int compress3(int, char*);
int (*com3)(int, char*);
int compress4(int, char*);
int (*com4)(int, char*);
int compress5(int, char*);
int (*com5)(int, char*);
int compress6(int, char*);
int (*com6)(int, char*);
int compress7(int, char*);
int (*com7)(int, char*);
int init();
int unique(char*, char);
int (*uniq)(char*, char);
int decompress2(int, char*);
int (*dcom2)(int, char*);
int decompress3(int, char*);
int (*dcom3)(int, char*);
int decompress4(int, char*);
int (*dcom4)(int, char*);
int decompress5(int, char*);
int (*dcom5)(int, char*);
int decompress6(int, char*);
int (*dcom6)(int, char*);
int decompress7(int, char*);
int (*dcom7)(int, char*);


void* Exit();
void* mainmenu();
void* compression();
void* decompression(void *);
void* openfile(void*);
void* createmasterarray(void *);
void* codelength(void *);

void* (*func[7])(void*);
