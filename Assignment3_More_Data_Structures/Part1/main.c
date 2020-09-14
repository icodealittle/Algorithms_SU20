// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


void unitTest1(){

    dll_t* test1 = create_dll();

    printf("pushing 1 to front of  the list\n");
    dll_push_front(test1, 1);
    printf("size of DLL is: %d\n", dll_size(test1));
    printf("pushing 2 to the front of the list\n");
    dll_push_front(test1, 2);
    printf("pushing 3 to the front of the list\n");
    dll_push_front(test1, 3);
    printf("pushing 4 to the front of the list\n");
    dll_push_front(test1, 4);
    printf("pushing 6 to the front of the list\n");
    dll_push_front(test1, 6);
    printf("size of DLL is: %d\n", dll_size(test1));
    printf("inserting 5 to positin 1\n");
    dll_insert(test1, 1, 5);
    printf("size of DLL is: %d\n", dll_size(test1));
    printf("removing number at the front of the list\n");
    dll_pop_front(test1);
    printf("size of DLL is: %d\n", dll_size(test1)); 
    printf("number at position 3 is: %d\n", dll_get(test1, 3));
    dll_remove(test1, 3);
    printf("removing number at position 3\n");
    printf("number at position 3 is NOW: %d\n", dll_get(test1, 3));
    printf("removing the last number\n");
    dll_pop_back(test1);
    printf("size of the DLL is: %d\n", dll_size(test1));
    printf("inserting 8 to the end of the list\n");
    dll_push_back(test1, 8);
    printf("DLL is not empty: %d\n", dll_empty(test1));

    free_dll(test1);

}

void UnitTest2(){

    dll_t * test2 = create_dll();

    printf("DLL should be empty.\n");
    printf("This DLL should be returning back 1 : %d\n", dll_empty(test2));
    printf("This DLL should be returning back 0 : %d\n", dll_remove(test2, 4));
    printf("This DLL should be returning back 0 : %d\n", dll_get(test2, 1));
    
    free_dll(test2);

}

void UnitTest3(){

    dll_t * test3 = create_dll();

    dll_push_front(test3, 9);
    dll_push_front(test3, 13);
    dll_push_front(test3, 1);

    printf("Size should be return back 3 : %d\n", dll_size(test3));
    printf("Pop to the front. Should be returning back with 1 : %d\n", dll_pop_front(test3));
    printf("Pop to the front. Should be returning back with 13 : %d\n", dll_pop_front(test3));
    printf("Pop to the front. Should be returning back with 9 : %d\n", dll_pop_front(test3));
    
     free_dll(test3);
}

void UnitTest4(){
    
    dll_t * test4 = create_dll();

    dll_push_front(test4, 9);
    dll_push_front(test4, 10);
    dll_push_front(test4, 30);
    dll_insert(test4, 1, 2);

    printf("Pop back. Should be returning back with 9 : %d\n", dll_pop_back(test4));
    printf("Get front. Should be returning back 10 : %d\n", dll_get(test4, 0));
    printf("Pop front. Should be returning back with 30 : %d\n", dll_pop_front(test4));
    printf("Pop front. Should be returning back with 2 : %d\n", dll_pop_front(test4));
    printf("Size should be return back 1 :  %d\n", dll_size(test4));
    
     free_dll(test4);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	printf("====================================================\n");
	unitTest1();
	printf("====================================================\n");
	UnitTest2();
	printf("====================================================\n");
	UnitTest3();
	printf("====================================================\n");
	UnitTest4();
	printf("====================================================\n");
	
    return 0;
}
