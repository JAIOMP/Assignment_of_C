#include <stdio.h>
#include "linkeLlist.h"
void increament(void *element){
	int *value = element;
	*value = *value+1;
}
 
int main()
{
	LinkedList list = createList();
	int d = 4;
	int f = 23;
	int g = 45;
	int h = 14;
	int i = 276;
	int j = 44;
	int k = 2;
	add_to_list(&list,&d);
	add_to_list(&list,&f);
	add_to_list(&list,&g);
	add_to_list(&list,&h);
	add_to_list(&list,&i);
	add_to_list(&list,&j);
	// forEach(list,&increament);
	// printf("%d\n",*wal);
	// deleteAtFirst(&list);
	int *num = deleteElementAt(&list,3);
	printf("deleted %d\n",*num);
	int *waste = getElementAt(list,1);
	int *waste1 = getElementAt(list,2);	
	int *waste2 = getElementAt(list,3);	
	int *waste3 = getElementAt(list,4);	
	// int *waste4 = getElementAt(list,5);	
	int wal = indexOf(list,&h);
	printf("%d\n",*waste);
	printf("%d\n",*waste1);
	printf("%d\n",*waste2);
	printf("%d\n",*waste3);
	// printf("%d\n",*waste4);

	printf("index %d\n",indexOf(list,&j));
	// int *t = get_first_element(list);
	// printf("%d\n",*t);
	// int *h = get_last_element(list);
	// printf("%d\n",*h);	

	return 0;
}