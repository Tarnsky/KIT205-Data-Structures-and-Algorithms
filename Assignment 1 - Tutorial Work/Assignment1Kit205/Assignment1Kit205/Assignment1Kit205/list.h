




typedef struct listNode {
	int data;
	struct listNode* next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;

void prnt_list(List* self);
List new_list();
void insert_at_front(List* self, int data);
void insert_in_order(List* self, int data);
void delete_list(List* self, int data);
void destroy_list(List* self);
void reverse_list(List* self);
List merge(List* a, List* b);


