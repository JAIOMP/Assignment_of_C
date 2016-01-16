#include <stdio.h>
#include "linkeLlist.h"
void increament(void *element){
	int *value = element;
	*value = *value+1;
}
 
int increament_by(void *hint,void *item){
	return *(int *)item %(*(int *)hint);
}
void add_numbers(void *hint,void *Sourceitem,void *destItem){
	*(int *)destItem = *(int *)(Sourceitem) + (*(int *)hint);
}
void* add(void* hint, void* previousItem, void* item){
	*(int *)item = *(int *)(previousItem) + (*(int *)item);	
	return item;
}

int main()
{
	LinkedList list = createList();
	// int maxElements = 5;
	// void *base[5];
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
	// int *num = deleteElementAt(&list,3);
	// printf("deleted %d\n",*num);
	// printf("index %d\n",indexOf(list,&j));
	// int *t = get_first_element(list);
	// printf("%d\n",*t);
	// int *h = get_last_element(list);
	// printf("%d\n",*h);
	// printf("%d\n",(asArray(&list,base,maxElements)));
	// printf("%d\n",*(int *)base[5]);
	void *ele = &k;
	// LinkedList newList = Filter(list,increament_by,ele);
	LinkedList newList = reverse(&list);
	// Reduce(list,add,&k,&k);
	int *waste = getElementAt(newList,0);
	int *waste0= getElementAt(newList,1);	
	int *waste1 = getElementAt(newList,2);	
	int *waste2 = getElementAt(newList,3);	
	int *waste3 = getElementAt(newList,4);		
	int wal = indexOf(newList,&h);
	printf("%d\n",*waste);
	printf("%d\n",*waste0);
	printf("%d\n",*waste1);
	printf("%d\n",*waste2);
	printf("%d\n",newList.length);
	return 0;
}





































