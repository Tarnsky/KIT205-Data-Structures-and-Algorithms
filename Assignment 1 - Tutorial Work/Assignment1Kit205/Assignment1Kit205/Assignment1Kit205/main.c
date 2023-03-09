#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
#include "bst.h"



//Commment out list merge and data imput code

int main()
{
	//list main
	printf("List \n");

	List my_listOne;
	my_listOne = new_list();
	List my_listTwo;
	my_listTwo = new_list();
	//Adding numbers
	insert_at_front(&my_listOne, 1);
	insert_at_front(&my_listOne, 2);
	insert_at_front(&my_listOne, 3);
	insert_at_front(&my_listOne, 4);
	insert_at_front(&my_listOne, 5);

	prnt_list(&my_listOne);
	//Testing reverse
	printf("Reverse List");
	reverse_list(&my_listOne);
	prnt_list(&my_listOne);
	//Destroy List One
	printf("Destroy List\n");
	destroy_list(&my_listOne);
	printf("Merge List one and two \n");
	//Adding new data lists
	prnt_list(&my_listOne);
	
	insert_at_front(&my_listOne, 1);
	insert_at_front(&my_listOne, 2);
	insert_at_front(&my_listOne, 3);
	insert_at_front(&my_listOne, 4);
	prnt_list(&my_listOne);
	insert_at_front(&my_listTwo, 5);
	insert_at_front(&my_listTwo, 6);
	insert_at_front(&my_listTwo, 7);
	insert_at_front(&my_listTwo, 8);
	prnt_list(&my_listTwo);
	merge(&my_listOne, &my_listOne);
	prnt_list(&my_listOne);

	/*int quit = 0;
	int imput;
	while (quit !=1)
	{
		int option;
		insert_at_front(&my_list, 1);
		insert_at_front(&my_list, 2);
		insert_at_front(&my_list, 3);
		insert_at_front(&my_list, 4);
		insert_at_front(&my_list, 5);
		printf("Please enter option \n");
		printf("0 quit, 1 insert, 2 delete, 3 print \n");
		scanf("%d", &option);
		if (option == 0)
		{
			quit = 1;
		}
		if (option == 1)
		{
			printf("enter num \n");
			scanf("%d", &imput);
			insert_at_front(&my_list, imput);
		}
		if (option == 2)
		{
			delete_list(&my_list, imput);
		}
		if (option == 3) {
			prnt_list(&my_list);
		}
	}*/

	//bst main
	printf("Tree \n");
	BST tree = new_bst();
	insert_bst(&tree, 1);
	insert_bst(&tree, 4);
	insert_bst(&tree, 3);
	insert_bst(&tree, 9);
	insert_bst(&tree, 2);
	insert_bst(&tree, 7);
	insert_bst(&tree, 6);
	insert_bst(&tree, 8);
	printf("Pre order \n");
	print_pre_order_bst(&tree);
	printf("\n");
	printf("In order \n");
	print_in_order_bst(&tree);
	printf("\n");
	printf("Post order\n");
	print_post_order_bst(&tree);
	printf("\n");
	printf("Tree hight \n");
	printf("%d", treeHight(tree.root));

//int quit = 0;
//int data;
//while (quit == 0) {
//    printf("Enter some data: ");
//    scanf("%d", &data);
//    if (data != 0) {
//        insert_bst(&tree, data);
//    }
//    else {
//        quit = 1;
//    }
//}

	return 0;
}