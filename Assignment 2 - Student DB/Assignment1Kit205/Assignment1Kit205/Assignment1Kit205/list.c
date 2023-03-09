#include <stdlib.h>
#include <stdio.h>


#include "list.h"


UnitList new_list() {
	UnitList temp;
	temp.head = NULL;
	return temp;
}


void prnt_list(UnitList* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("\n Unit enrollments: ");
		printf("\n %s \n", current->unit_code);
		current = current->next;
	}
	printf("\n");
}

void insert_at_front(UnitList* self, char* data) {

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->unit_code = data;
	new_node->next = self->head;
	self->head = new_node;
}

void insert_in_order(UnitList* self, char* data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->unit_code = data;
	new_node->next = NULL;

	while (current != NULL && current->unit_code < data) {
		prev = current;
		current = current->next;
	}
	if
		(current == self->head) {
		// at front
		new_node->next = current;
		self->head = new_node;
	}
	else
	{
		// middle
		new_node->next = current;
		prev->next = new_node;
	}
}

void delete_list(UnitList* self, char* data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->unit_code == data) {
			if (prev == NULL) {          // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

void destroy_list(UnitList* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

void reverse_list(UnitList* self) {
	struct listNode* prev = NULL;
	struct listNode* current = self->head;
	struct listNode* next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	self->head = prev;
}
//UnitList merge(UnitList* a, UnitList* b)
//{
//	while (b != NULL)
//	{
//		ListNodePtr current = b->head;
//		insert_at_front(a, b->head);
//		ListNodePtr to_free = current;
//		current = current->next;
//		free(to_free);
//	}
//}

