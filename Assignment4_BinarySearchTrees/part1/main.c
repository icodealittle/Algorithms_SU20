// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void unitTest1(){

	//Check NULL test
	bst_t*  test1 = NULL;

	printf("Empty Tree: %d\n", bst_empty(test1));
	printf("Add: %d\n", 10, bst_add(test1, 10));
	printf("The tree sum is: %d\n", sum(test1));
	printf("Is 10 in the tree? %d\n", find(test1, 10));
	printf("Size: %d\n", bst_size(test1));
	printf("Ascending Order: \n");
	 bst_print(test1, 0);
	printf("Descending Order: \n");
	 bst_print(test1, 1);
	
	free_bst(test1);
}

void unitTest2(){

	bst_t* test2 = create_bst();

	bst_add(test2, 6);
	printf("Empty Tree. Should return 0: %d\n", bst_empty(test2));
	printf("Size: %d\n", bst_size(test2));
	printf("Is there an integer in this tree? %d\n", find(test2, 0));
	printf("Descending Order: \n");
	bst_print(test2, 0);
	free_bst(test2);
}

void unitTest3(){

	bst_t* test3 = create_bst();
	
	printf("Add: %d\n", 50);
	printf("%d was added to the tree: %d\n", 50, bst_add(test3, 50));
	printf("Add: %d\n", 20);
	printf("%d was added to the tree: %d\n", 20, bst_add(test3, 20));
	printf("Add: %d\n", 70);
	printf("%d was added to the tree: %d\n", 70, bst_add(test3, 70));
	printf("Add: %d\n", 90);
        printf("%d was added to the tree: %d\n", 90, bst_add(test3, 90));
	printf("Add: %d\n", 40);
        printf("%d was added to the tree: %d\n", 40, bst_add(test3, 40));
	printf("Add: %d\n", 80);
        printf("%d was added to the tree: %d\n", 80, bst_add(test3, 80));
	printf("Add: %d\n", 100);
        printf("%d was added to the tree: %d\n", 100, bst_add(test3, 100));
	printf("Add: %d\n", 30);
        printf("%d was added to the tree: %d\n", 30, bst_add(test3, 30));
	printf("Add: %d\n", 60);
        printf("%d was added to the tree: %d\n", 60, bst_add(test3, 60));
	printf("Add: %d\n", 10);
        printf("%d was added to the tree: %d\n", 10, bst_add(test3, 10));
	printf("Descending Order: \n");
	bst_print(test3, 1);
	
	printf("Is 15 in the tree?\n");
	printf("Should return with 0: %d\n", find(test3, 15));
	printf("Size: %d\n", bst_size(test3));

	free_bst(test3);
}

void unitTest4(){

	bst_t* test4 = create_bst();

	printf("Add: %d\n", -10);
	printf("%d was added to the tree: %d\n", -10, bst_add(test4, -10));
	printf("Add: %d\n", 2);
        printf("%d was added to the tree: %d\n", 2, bst_add(test4, 2));
	printf("Add: %d\n", 15);
        printf("%d was added to the tree: %d\n", 15, bst_add(test4, 15));
	printf("Add: %d\n", -12);
        printf("%d was added to the tree: %d\n", -12, bst_add(test4, -12));
	printf("Add: %d\n", 50);
        printf("%d was added to the tree: %d\n", 50, bst_add(test4, 50));
	printf("Size: %d\n", bst_size(test4));
	printf("Ascending Order: \n");
	bst_print(test4, 0);
	printf("Sum: %d\n", sum(test4));

	free_bst(test4);

}

void unitTest5(){

	bst_t* test5 = create_bst();

	printf("Add: %.2f\n", 9.99);
        printf("%.2f was added to the tree: %.2f\n", 9.99, bst_add(test5, 9.99));
	printf("Add: %.2f\n", 2.5);
        printf("%.2f was added to the tree: %.2f\n", 2.50, bst_add(test5, 2.50));
	printf("Add: %.2f\n", 0.67);
        printf("%.2f was added to the tree: %.2f\n", 0.67, bst_add(test5, 0.67));
	printf("Add: %.2f\n", 1.11);
        printf("%.2f was added to the tree: %.2f\n", 1.11, bst_add(test5, 1.11));
	printf("Sum: %.2f\n", sum(test5));
	printf("Descending Order: %.2f\n");
	bst_print(test5, 1);
	printf("Ascending Order: %.2f\n");
	bst_print(test5, 0);

	free_bst(test5);
}

void unitTest6(){

	bst_t* test6 = create_bst();
	
	printf("Add: %d\n", -10);
        printf("%d was added to the tree: %d\n", -10, bst_add(test6, -10));
        printf("Add: %d\n", 2);
        printf("%d was added to the tree: %d\n", 2, bst_add(test6, 2));
        printf("Add: %d\n", 15);
        printf("%d was added to the tree: %d\n", 15, bst_add(test6, 15));
	printf("Add: %d\n", -50);
        printf("%d was added to the tree: %d\n", -50, bst_add(test6, -50));
        printf("Add: %d\n", 20);
        printf("%d was added to the tree: %d\n", 20, bst_add(test6, 20));
        printf("Add: %d\n", 0);
        printf("%d was added to the tree: %d\n", 0, bst_add(test6, 0));
        printf("Add: %d\n", 90);
        printf("%d was added to the tree: %d\n", 90, bst_add(test6, 90));
        printf("Add: %d\n", 40);
        printf("%d was added to the tree: %d\n", 40, bst_add(test6, 40));
        printf("Add: %d\n", 80);
        printf("%d was added to the tree: %d\n", 80, bst_add(test6, 80));
		
	 printf("Size: %d\n", bst_size(test6));
        printf("Ascending Order: \n");
        bst_print(test6, 0);
        printf("Sum: %d\n", sum(test6));
	printf("Descending Order: \n");
	bst_print(test6, 1);

	printf("Is 15 in the tree?\n");
        printf("Should return with 0: %d\n", find(test6, 15));
	printf("Is -10 in the tree?\n");
        printf("Should return with 1: %d\n", find(test6, -10));

	printf("Is the tree empty?\n");
	printf("Should be return 0: %d\n", bst_empty(test6));	
		


	free_bst(test6);
}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	
	printf("===================================================\n");
	printf("NULL Unit Test\n");  
	unitTest1();    
	printf("===================================================\n");
	printf("Empty Tree Unit Test\n");
	unitTest2();
	printf("===================================================\n");
	printf("Tree Unit Test with ten nodes\n");
	unitTest3();
	printf("===================================================\n");
	printf("Tree Unit Test With Neg Number\n");
	unitTest4();
	printf("===================================================\n");
	printf("Tree Unit Test Mixture of Everything\n");
	unitTest6();
    return 0;
}
