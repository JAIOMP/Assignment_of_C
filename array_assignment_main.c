#include <stdio.h>
#include "array_lib.h"
int main()
{
	// create(4,5);
	// resize(create(5,6),7);
	ArrayUtil a = create(4,0);
	int num = 2; 
	int *elem = &num;
	int *ar = a.base;
	ar[0] = 12;
	ar[1] = 1;
	ar[2] = 2;
	ar[3] = 1;
	ar[4] = 4;
	ar[5] = 6;
	int ele = 8;
	int findResult = count(a,isEven,NULL);
	int *result = findFirst(a,isEven,NULL);
	int *getResult = findLast(a,isEven,NULL);
	printf("result %d\n",*result);
	return 0;
}