#pragma once


typedef char* String;

typedef struct listNode {
	String unit_code;
	struct listNode* next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} UnitList;

void prnt_list(UnitList* self);
UnitList new_list();
void insert_at_front(UnitList* self, char* data);
void insert_in_order(UnitList* self, char* data);
void delete_list(UnitList* self, char* data);
void destroy_list(UnitList* self);
void reverse_list(UnitList* self);
//UnitList merge(UnitList* a, UnitList* b);


