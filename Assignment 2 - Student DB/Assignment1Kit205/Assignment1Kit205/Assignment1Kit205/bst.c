#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

StudentBST new_bst() {
    StudentBST temp;
    temp.root = NULL;
    return temp;
}

BSTNodePtr find_bst_node(BSTNodePtr self, long id) {
    if (self == NULL || (id == self->student_id)) {
        return self;
    }
    else if (id < self->student_id) {
        return find_bst_node(self->left, id);
    }
    else {
        return find_bst_node(self->right, id);
    }
}
BSTNodePtr find_bst(StudentBST* self, long n) {
    return find_bst_node(self->root, n);
}

BSTNodePtr insert_bst_node(BSTNodePtr self, long id) {
    if (self == NULL) { /* found where to put it*/
        self = malloc(sizeof * self);
        self->student_id = id;
        self->left = self->right = NULL;

        
    }
    else if (id < self->student_id) {
        self->left = insert_bst_node(self->left, id);
    }
    else if (id > self->student_id) {
        self->right = insert_bst_node(self->right, id);
    }
    return self;
}

void insert_bst(StudentBST* self, long id) {
    self->root = insert_bst_node(self->root, id);
}

BSTNodePtr min_node(BSTNodePtr self) {
    BSTNodePtr current = self;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

BSTNodePtr delete_bst_node(BSTNodePtr self, long id) {
    if (self != NULL) {
        if (id == self->student_id) { // found item 
            if (self->left != NULL && self->right != NULL) {
                // two child case 
                BSTNodePtr successor = min_node(self->right);
                self->student_id = successor->student_id;
                self->right = delete_bst_node(self->right, self->student_id);
            }
            else { // one or zero child case 
                BSTNodePtr to_free = self;
                if (self->left) {
                    self = self->left;
                }
                else {
                    self = self->right;
                }
                free(to_free);
            }
        }
        else if (id < self->student_id) {
            self->left = delete_bst_node(self->left, id);
        }
        else {
            self->right = delete_bst_node(self->right, id);
        }
    }
    return self;
}

void delete_bst(StudentBST* self, long id) {
    self->root = delete_bst_node(self->root, id);
}

void print_pre_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        printf(" %d ", self->student_id);
        print_pre_order_bst_node(self->left);
        print_pre_order_bst_node(self->right);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_pre_order_bst(StudentBST* self) {
    print_pre_order_bst_node(self->root);
}
void print_in_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_in_order_bst_node(self->left);
        printf(" %d ", self->student_id);
        prnt_unit(self, self->student_id);
        print_in_order_bst_node(self->right);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_in_order_bst(StudentBST* self) {
    print_in_order_bst_node(self->root);
}
void print_post_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_post_order_bst_node(self->left);
        print_post_order_bst_node(self->right);
        printf(" %d ", self->student_id);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_post_order_bst(StudentBST* self) {
    print_post_order_bst_node(self->root);
}


int treeHight(BSTNodePtr self)
{
    if (self == NULL)
    {
        return 0;
    }
    else
    {
        /* compute the depth of each subtree */
        int lDepth = treeHight(self->left);
        int rDepth = treeHight(self->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else
            return(rDepth + 1);
    }
}

void add_unit(BSTNodePtr self, long id, char* unit_code) {
    BSTNodePtr result = find_bst(self, id);
    result = find_bst(self, id);
    if (result != 0) {
        insert_at_front(&self->units, unit_code);
    }
}
void add_unit_node(StudentBST* self, long id, char* unit_code) {
     add_unit(&self->root, id, unit_code);
}

void prnt_unit(BSTNodePtr self, long id) {
    BSTNodePtr result = find_bst(self, id);
    result = find_bst(self, id);
    if (result != 0) {
        prnt_list(&self->units);
    }
}

void prnt_unit_node(StudentBST* self, long id) {
    prnt_unit(&self->root, id);
}

void delete_unit(BSTNodePtr self, long id, char* unit_code) {
    BSTNodePtr result = find_bst(self, id);
    result = find_bst(self, id);
    if (result != 0) {
        delete_list(&self->units, unit_code);
    }
}
void delete_unit_node(StudentBST* self, long id, char* unit_code) {
     delete_unit(&self->root, id, unit_code);
}

