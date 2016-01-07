typedef struct {
	void *base;
	int typesize;
	int length;
} ArrayUtil;
 
typedef int(MatchFunc)(void*,void*); 

ArrayUtil create(int a ,int b);
ArrayUtil resize(ArrayUtil array,int length);
void *findFirst(ArrayUtil,MatchFunc* che,void * hint);
int areEqual(ArrayUtil a,ArrayUtil b);
void dispose(ArrayUtil array);
int findIndex(ArrayUtil util,void *element);
int isEven(void *hint,void *item);
void *findLast(ArrayUtil,MatchFunc* che,void * hint);
int count(ArrayUtil util,MatchFunc* match,void *hint);
int filter(ArrayUtil util,MatchFunc* match,void* hint,void** dest,int max);

