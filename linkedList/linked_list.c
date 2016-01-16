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

int asArray(LinkedList *list, void ** array, int maxElements){
	printf("length %d\n", list->length);
	Element *e = list->first;
	int length = list->length > maxElements ? maxElements : list->length;
	int i = 0;
	while(i<=length){
		array[i] = e->value;
		e = e->next;
		i++;
	}
	return length;
}
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


LinkedList Filter(LinkedList list, MatchFunc increament,void* ele){
	Element *item = list.first;
	LinkedList result = createList();
	while(list.length!=0){
		int val = increament(ele,item->value);
		if (val==0){
			if(result.length == 0){
			result.first = result.last = item;
			}
		else{
		result.last->next = item;
		result.last = item;
		}
		result.length++;	
		}

		item = item->next;
		list.length--;		
	}
	return result;
}

LinkedList map(LinkedList list, ConvertFunc add_numbers, void * hint){
	Element *item = list.first;
	LinkedList result = createList();
	while(list.length!=0){
			if(result.length == 0){
			result.first = result.last = item;
			add_numbers(hint,item->value,result.first->value);
			}
		else{
		result.last->next = item;
		result.last = item;
		add_numbers(hint,item->value,result.last->value);
		}
		result.length++;
		item = item->next;
		list.length--;		
	}
	return result;
}

void addElement(LinkedList *list, void *val) {
	Element *element = (Element *)malloc(sizeof(Element));
	element->value = val;
	element->next = NULL;
	element->index = 0;
	if (list->first== NULL)
		list->first = list->last = element;
	else if (list->first!= NULL) {
		element->next = list->first;
		list->first= element;
	}
	list->length++;
}

LinkedList reverse(LinkedList *list){
	Element *e = list->first;
	LinkedList newList = createList();
	while(e!=NULL){
		addElement(&newList,e->value);
		e = e->next;
	}
	return newList;
}


void *Reduce(LinkedList list,Reducer plus, void *hint, void *initialValue){
	Element *item = list.first;
	while(item!=NULL){
		initialValue = (*plus)(hint,initialValue,item->value);
		item = item->next;
	}
	return initialValue;
}
	











