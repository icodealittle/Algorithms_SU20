// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
}


void unitTest4(){

	stack_t* test4 = create_stack(2);

	if(stack_empty(test4)){
		printf("This stack is empty.\n");
	}
	
	printf("Push: %d\n", 1);
	printf("Status: %d\n", stack_enqueue(test4, 1));
	printf("Push: %d\n", 2);
        printf("Status: %d\n", stack_enqueue(test4, 2));
	printf("Push: %d\n", 3);
	printf("Status: %d\n", stack_enqueue(test4, 3));
	printf("Size: %d\n", stack_size(test4));

	if (stack_full(test4)){
		printf("This stack is full.\n");
	}
	printf("Stack size: %d\n",  stack_size(test4));
	printf("Remove: %d\n", stack_dequeue(test4));
	printf("Stack size: %d\n",  stack_size(test4));
        printf("Remove: %d\n", stack_dequeue(test4));
	printf("Stack size: %d\n",  stack_size(test4));

	free_stack(test4);
}

void unitTest5(){
	
	stack_t* test5 = create_stack(3);

        if (stack_empty(test5)){
                printf("This stack is empty.\n");
        }
        printf("Push: %d\n", 1);
        printf("Status: %d\n", stack_enqueue(test5, 1));
        printf("Push: %d\n", 2);
        printf("Status: %d\n", stack_enqueue(test5, 2));
	printf("Push: %d\n", 3);
        printf("Status: %d\n", stack_enqueue(test5, 3));
        printf("Push: %d\n", 4);
        printf("Status: %d\n", stack_enqueue(test5, 4));

        if (stack_full(test5)){
                printf("This stack is full.\n");
        }
        printf("Stack size: %d\n",  stack_size(test5));
        printf("Remove: %d\n", stack_dequeue(test5));
        printf("Stack size: %d\n",  stack_size(test5));
        printf("Remove: %d\n", stack_dequeue(test5));
        printf("Stack size: %d\n",  stack_size(test5));
        printf("Remove: %d\n", stack_dequeue(test5));
	printf("Stack size: %d\n",  stack_size(test5));
	
	printf("Removing: %d\n",stack_dequeue(test5));
	printf("The program is still on.\n");
        free_stack(test5);

}

void unitTest6(){

	stack_t* test6 = create_stack(0);
	
	if (stack_empty(test6)){
		printf("This stack is empty.\n");
	}
	free_stack(test6);

}

void unitTest3(){

	stack_t* test3 = NULL;

	if (test3 == NULL){
		printf("NULL\n");
	}

	free_stack(test3);
}

void unitTest2(){
	stack_t* test2 = create_stack(32);
	printf("The stack capacity: %d\n", test2->capacity);

	free_stack(test2);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	printf("=========================================\n");
	unitTest2();
	printf("=========================================\n");
	unitTest3();
	printf("=========================================\n");
	unitTest4();
	printf("=========================================\n");
	unitTest5();
	printf("=========================================\n");
	unitTest6();
	return 0;
}
