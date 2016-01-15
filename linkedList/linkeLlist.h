typedef struct element{
	int index;
	void* value;
	struct element *next;
}Element;

typedef struct list{
	Element *first;
	Element *last;
	int length;
} LinkedList;

typedef void(*ElementProcessor)(void*);


LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int index);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *,int);
void decrementIndex(Element *element);
void *deleteAtFirst(LinkedList *list);