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
typedef int(MatchFunc)(void *,void *);
typedef void(ConvertFunc)(void *,void *,void *);
typedef void *(Reducer)(void *,void *,void *);


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
int asArray(LinkedList *list, void ** arr, int maxElements);
LinkedList Filter(LinkedList list, MatchFunc increase,void*);
LinkedList map(LinkedList, ConvertFunc, void * );
void *Reduce(LinkedList list, Reducer plus, void *hint, void *initialValue);
LinkedList reverse(LinkedList *list);
