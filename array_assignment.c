#include "array_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayUtil create(int typesize,int length){
	ArrayUtil array; 
	array.base  = calloc(length,typesize);
	array.typesize = typesize;
	array.length = length;
	return array; 
}

ArrayUtil resize(ArrayUtil array,int length){
	array.base = realloc(array.base,array.typesize*length);
	array.length = length;
	return array;
}

int areEqual(ArrayUtil a,ArrayUtil b){
	if (a.length != b.length){
		return 0;
	}
	else{
		int diff = memcmp(a.base,b.base,a.typesize * a.length);
		if(diff == 0)
			return 1;
		return 0;
	}
}
void dispose(ArrayUtil util){
	free(util.base);
}

int findIndex(ArrayUtil util,void * element){
	if (util.length==0)
	{
		return -1;
	}
	else{
		int i = 0;
		void *group = util.base;
		while((i < util.length) && memcmp(group,element,util.typesize)!=0){
		i++;
		group += util.typesize; 
		}
		return i < util.length ? (i) : -1;
	}
}
void *findFirst(ArrayUtil util,MatchFunc* match,void* hint){
	int *group;
	if(util.length==0){
		return NULL;
	}
	else{
		int i = 0;
		while(i < util.length && (*match)(hint,group)==0){
			i++;
			group = util.base +(util.typesize*i);
	}
		return (i < util.length) ? group : NULL;
	} 

};
void *findLast(ArrayUtil util,MatchFunc* match,void *hint){
	if(util.length==0){
		return NULL;
	}
	else{
	util.length = util.length-1;
	int *group = util.base + (util.typesize*(util.length)); 
	while(util.length >= 0 && (*match)(hint,group)==0){
		util.length--;
		group = util.base + (util.typesize*(util.length)); 
	}
		return (util.length >= 0) ? group : NULL;  
	}
}; 

int count(ArrayUtil util,MatchFunc* match,void *hint){
	int *group;
	int count = 0;
	if (util.length == 0){
		return 0;
	}
	else
		for (int i = 0; i < util.length; ++i)
		{
			group = util.base+(util.typesize*i);
			if ((*match)(hint,group)) count++ ;
		}
	return count;
}
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int count = 0;
	int *group = util.base;
	void *dest = destination;
	int *destin = dest;
	if (util.length < maxItems){
	for (int i = 0; i <util.length ; ++i){
		group = util.base + (util.typesize*i);
		if((*match)(hint,group)){
			destin[count] = *group;
			count++;
		}
	}
}
	return count;
}


void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int *group_of_source = source.base;
	int *group_of_destination = destination.base;
	for (int i = 0; i < source.length; ++i)
	{
		group_of_source = source.base + (source.typesize*i);
		group_of_destination = destination.base + (destination.typesize*i);
		convert(hint,group_of_source,group_of_destination);
	}

}   
 
void add_numbers(void *hint,void *sourceItem,void *destinationItem){
	int *num = sourceItem;
	int *where_to_add = destinationItem;
	int *what_to_add = hint;
	*where_to_add = (*num + *what_to_add); 
}

void multiply_numbers(void *hint,void *sourceItem,void *destinationItem){
	int *num = sourceItem;
	int *where_to_add = destinationItem;
	int *what_to_add = hint;
	*where_to_add = (*num * *what_to_add); 
}


int isEven(void * hint , void * item){
	int *num = item;
	return (*num%2==0);
};
 











































