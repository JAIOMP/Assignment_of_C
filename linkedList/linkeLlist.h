typedef struct element{
	void* value;
	struct element *next;
}Element;

typedef struct list{
	Element *first;
	Element *last;
	int length;
} LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *,void *);