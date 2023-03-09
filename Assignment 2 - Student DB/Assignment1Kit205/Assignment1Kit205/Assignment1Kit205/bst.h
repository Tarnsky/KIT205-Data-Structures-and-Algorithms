#pragma once
#include "list.h"


typedef struct bstNode {
	long student_id;
	UnitList units;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
	BSTNodePtr root;
} StudentBST;

StudentBST new_bst();
BSTNodePtr find_bst_node(BSTNodePtr self, long id);
BSTNodePtr find_bst(StudentBST *self, long id);
BSTNodePtr insert_bst_node(BSTNodePtr self, long id);
void insert_bst(StudentBST *self, long id);
BSTNodePtr min_node(BSTNodePtr self);
BSTNodePtr delete_bst_node(BSTNodePtr self, long id);
void delete_bst(StudentBST *self, long id);
void print_pre_order_bst_node(BSTNodePtr self);
void print_pre_order_bst(StudentBST* self);
void print_in_order_bst_node(BSTNodePtr self);
void print_in_order_bst(StudentBST* self);
void print_post_order_bst_node(BSTNodePtr self);
void print_post_order_bst(StudentBST* self);
int treeHight(BSTNodePtr self);
void add_unit_node(StudentBST* self, long id, char* unit_code);
void add_unit(BSTNodePtr self, long id, char* unit_code);
void prnt_unit(BSTNodePtr self, long id);
void prnt_unit_node(StudentBST* self, long id);
void delete_unit(BSTNodePtr self, long id, char* unit_code);
void delete_unit_node(StudentBST* self, long id, char* unit_code);
