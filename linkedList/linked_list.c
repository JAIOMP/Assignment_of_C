#include "linkeLlist.h"
#include <stdlib.h>

LinkedList createList(void){
	LinkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
	return list;
};

int add_to_list(LinkedList *List,void *val){
	Element *e = (Element *) malloc(sizeof(Element));
	e->value = val;
	e->next = NULL;
	if(List->length == 0){
		List->first = List->last = e;
	}
	else{
		List->last->next = e;
		List->last = e;
	}
	List->length++;
	return List->length;
};

