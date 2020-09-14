// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.

//First unit test case
// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){
	
	queue_t* test1 = create_queue(1);

	if (queue_full(test1)){
                printf("This queue is full.\n");
        }
        printf("Add: %d\n", 1);
	printf("Status: %d\n", queue_enqueue(test1, 1));
	printf("Size: %d\n", queue_size(test1));

        if (queue_full(test1)){
                printf("This queue is full.\n");
        }
	printf("Add: %d\n", 2);
        printf("Status: %d\n", queue_enqueue(test1, 2));
        printf("Size: %d\n", queue_size(test1));

        if (queue_empty(test1)){
                printf("This queue is empty.\n");
        }
	printf("Removing: %d\n",queue_dequeue(test1));
        printf("Size: %d\n", queue_size(test1));
        printf("Removing: %d\n",queue_dequeue(test1));
        printf("Size: %d\n", queue_size(test1));

        free_queue(test1);

}

//Second unit test case
//Following the same format as the first unit test, but using an even number queue
void unitTest2(){

	queue_t* test2 = create_queue(4);

        if (queue_full(test2)){
                printf("This is a full queue.\n");}
	printf("Add: %d\n", 1);
        printf("Status: %d\n", queue_enqueue(test2, 1));
        printf("Size: %d\n", queue_size(test2));

	if (queue_full(test2)){
                printf("This is a full queue.\n");}
        printf("Add: %d\n", 2);
        printf("Status: %d\n", queue_enqueue(test2, 2));
        printf("Size: %d\n", queue_size(test2));

	if (queue_full(test2)){
                printf("This is a full queue.\n");}
        printf("Add: %d\n", 3);
        printf("Status: %d\n", queue_enqueue(test2, 3));
        printf("Size: %d\n", queue_size(test2));

	if (queue_full(test2)){
                printf("This is a full queue.\n");}
        printf("Add: %d\n", 4);
        printf("Status: %d\n", queue_enqueue(test2, 4));
        printf("Size: %d\n", queue_size(test2));

        if (queue_empty(test2)){
                printf("This is an empty queue.\n");}

        printf("Removing: %d\n",queue_dequeue(test2));
        printf("The size is %d.\n", queue_size(test2));
        printf("Removing: %d\n",queue_dequeue(test2));
        printf("The size is %d.\n", queue_size(test2));
        printf("Removing: %d\n",queue_dequeue(test2));
        printf("The size is %d.\n", queue_size(test2));
        printf("Removing: %d\n",queue_dequeue(test2));
        printf("The size is %d.\n", queue_size(test2));
        printf("Removing: %d\n",queue_dequeue(test2));
        printf("The size is %d.\n", queue_size(test2));
        free_queue(test2);	
}

//Third unit test case
//Similar format, but more focus on empty queue and the dequeue of an empty queue
void unitTest3(){

	queue_t* test3 = create_queue(0);

	//Empty queue
	if (queue_empty(test3)){
		printf("This queue is empty.\n");
	}

	free_queue(test3);

}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	printf("============================================\n");
	unitTest2();
	printf("============================================\n");
	unitTest3();
	printf("============================================\n");

	return 0;
}
