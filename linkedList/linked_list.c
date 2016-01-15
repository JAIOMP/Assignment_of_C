#include <stdio.h>
#include "linkeLlist.h"
#include <stdlib.h>
#include <string.h>

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
		e->index = List->length;
		List->first = List->last = e;
	}
	else{
		e->index = List->length;
		List->last->next = e;
		List->last = e;
	}
	List->length++;
	return List->length;
};

void *get_first_element(LinkedList list){
	return list.first->value;
};

void *get_last_element(LinkedList list){
	return list.last->value;
};

void forEach(LinkedList list, ElementProcessor e){
	Element *val = list.first;
	for (int i = 0; i < list.length; ++i){
		e(val->value);
		val = val->next;
	}
}

void * getElementAt(LinkedList list, int index){
	Element *val = list.first;
	for (int i = 0; i < index; ++i){
		val = val->next;
	}
	return val->value;	
}
int indexOf(LinkedList list, void *value){
	Element *val = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		printf("length%d\n", i);
		if(memcmp(val->value,value,sizeof(value))==0)
			return i;
	val = val->next;
	}
	return -1;
}

void *deleteAtFirst(LinkedList *list){
	Element *element = list->first;
	void * deletedElement = element->value;
	list->first = element->next;
	free(element);
	list->length--;
	return deletedElement;
};

void decrease_index(Element *element) {
	while (element) {
		element->index--;
		element = element->next;
	}
}


void * deleteElementAt(LinkedList *list, int index) {
	Element *ptr = (Element *)list->first;
	Element *prev;
	Element *deletedElement;
	int length = 0;
	if (index == 0)return deleteAtFirst(list);
	while(ptr!=NULL){
		length++;
		if (index == length){
			deletedElement = ptr->value;
			prev->next = ptr->next;
			decrease_index(ptr);
			list->length--;
			if (index==(list->length-1)) list->last = prev;
			return deletedElement;
		};
		prev = ptr;
		ptr = ptr->next;
 	}
	return NULL;
}



















