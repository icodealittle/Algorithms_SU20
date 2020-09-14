// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here


// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

typedef struct node{
	int yearList;
	int numWins;
	struct node* next;
}node_t;

//A function that creates a linked list that populates a linked list with the win data.
node_t* create_list(){
	
	node_t* list_from_2019 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2018 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2017 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2016 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2015 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2014 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2013 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2012 = (node_t*) malloc(sizeof(node_t));
	node_t* list_from_2011 = (node_t*) malloc(sizeof(node_t));
	
	//A linked list of the 2019 wins
	list_from_2019->yearList = 2019;
        list_from_2019->numWins = 84;
        list_from_2019->next = list_from_2018;

	//A linked list of the 2018 wins
	list_from_2018->yearList = 2018;
	list_from_2018->numWins = 108;
	list_from_2018->next = list_from_2017;

	//A linked list of the 2017 wins
	list_from_2017->yearList = 2017;
        list_from_2017->numWins = 93;
        list_from_2017->next = list_from_2016;

	//A linked list of the 2016 wins	
	list_from_2016->yearList = 2016;
        list_from_2016->numWins = 93;
        list_from_2016->next = list_from_2015;

	//A linked list of the 2015 wins
	list_from_2015->yearList = 2015;
        list_from_2015->numWins = 78;
        list_from_2015->next = list_from_2014;

	//A linked list of the 2014 wins
	list_from_2014->yearList = 2014;
        list_from_2014->numWins = 71;
        list_from_2014->next = list_from_2013;

	//A linked list of the 2013 wins
	list_from_2013->yearList = 2013;
        list_from_2013->numWins = 97;
        list_from_2013->next = list_from_2012;

	//A linked list of the 2012 wins
	list_from_2012->yearList = 2012;
        list_from_2012->numWins = 69;
        list_from_2012->next = list_from_2011;

	//A linked list of the 2011 wins
	list_from_2011->yearList = 2011;
        list_from_2011->numWins = 90;
        list_from_2011->next = NULL;

	return list_from_2018; //return statement of the head pointer (???) 
}

//Usage of iterator pattern example from the lab specs
//A small syntax formation from: zentut.com/c-tutorial/c-linked-list/
//A second function that iterates through the linked list and prints out the data.
void print_list(node_t* linkedList){

	node_t* iterator;
	iterator = linkedList;
	while (iterator != NULL){ //Having the iterate method in a loop statement
		printf("%d, %d wins\n", iterator->yearList, iterator->numWins);
		iterator = iterator->next;
	}
}

//Third and last function that free's the linked list
void free_list(node_t* linkedList){
	
	node_t* iterator = linkedList;
	while (iterator != NULL){
		node_t* freeNode = iterator;
		iterator = iterator->next;
		free(freeNode);	
	}
	free(linkedList);	
}

//TODO: Need to change tail variable for a better readability when there's no error in compiling and everything works.
int main(){
	//node_t* tail = create_list();
	//print_list(tail);
	//free_list(tail);
	node_t* i = create_list();
	print_list(i);
	free_list(i); 
	return 0;
}
