#include <stdio.h>
#include "linkeLlist.h"
 
int main()
{
	LinkedList list = createList();
	int d = 4;
	printf("%d\n",add_to_list(&list,&d));
	return 0;
}