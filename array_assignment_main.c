#include <stdio.h>
#include "array_lib.h"
#define MAX 45
int main()
{
	// create(4,5);
	// resize(create(5,6),7);
	ArrayUtil a = create(4,6);
	ArrayUtil b = create(4,4);

	int num = 2; 
	int *elem = &num;
	int *ar = a.base;
	ar[0] = 12;
	ar[1] = 1;
	ar[2] = 2;
	ar[3] = 1;
	ar[4] = 4;
	ar[5] = 6;
	void *point = &num;
	// int array_length = 10;
	// int findResult = count(a,isEven,NULL);
	// int *result = findFirst(a,isEven,NULL);
	// int *getResult = findLast(a,isEven,NULL);
	// int filterResult = filter(a,isEven,NULL,b.base,array_length);
	int *arr = b.base;
	// printf("result %d\n",filterResult);
	map(a,b,multiply_numbers,point);
	printf("result 0 %d\n",arr[0]);
	printf("result 1 %d\n",arr[1]);
	printf("result 2 %d\n",arr[2]);
	printf("result 3 %d\n",arr[3]);
	printf("result 4 %d\n",arr[4]);

	return 0;
}