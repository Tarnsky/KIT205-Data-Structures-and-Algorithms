#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "bst.h"





int main()
{
	UnitList my_list = new_list();
	StudentBST studentList = new_bst();

	int quit = 0;
	int option;
	long id;
	char unit[101];
	BSTNodePtr result;
	
	while (quit != 1)
	{
		//add student id to bst then each bst has of unit codes.
		printf("Please enter option \n");
		printf("0 quit\n1 Add Student\n2 Remove student\n3 Enrol student in a unit\n4 Un-enrol student from a unit\n5 Print an ordered summary of units and the number of students enrolled in each unit\n6 Print an ordered list of students enrolled in a specific unit\n7 Print an ordered list of units that a specific student is enrolled in\n");
		scanf("%d", &option);
		if (option == 0)
		{
			quit = 1;
		}
		if (option == 1)
		{
			printf("Enter studentID: ");
			scanf("%d", &id);
			if (id != 0) 
			{
				insert_bst(&studentList, id);
			}
		}
		if (option == 2)
		{
			printf("Enter studentID to remove: ");
			scanf("%d", &id);
			if (id != 0) {
				delete_bst(&studentList, id);
			}
		}
		if (option == 3)
		{
			printf("Select studentID to enroll: ");
			scanf("%d", &id);
			result = find_bst(&studentList, id);
			if (result != 0)
			{
				printf("Enroll in unit: ");
				scanf("%s", &unit);
				add_unit(&studentList, id, unit);
			}
		}
		if (option == 4)
		{
			printf("Select studentID to Un-enrol: ");
			scanf("%d", &id);
			result = find_bst(&studentList, id);
			if (result != 0)
			{
				printf("Enroll in unit: ");
				scanf("%s", unit);
				delete_unit(&studentList, id, unit);
			}
		}
		if (option == 5) 
		{
			printf("Select unit: ");
			scanf("%s", unit);
			printf("%s \n ", unit);
			print_in_order_bst(&studentList, unit);
		}
		if (option == 6) 
		{
			printf("Select unit: ");
			scanf("%s", unit);
			printf("%s \n ", unit);
			print_in_order_bst(&studentList, unit);
		}
		if (option == 7) 
		{
			printf("Select studentID: ");
			scanf("%d", id);
			result = find_bst(&studentList, id);
			if (result != 0)
			{
				prnt_unit(&studentList, id);
			}
		}

	}

	return 0;
}