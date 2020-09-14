// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* rightChild;
  	struct node* leftChild;
}node_t;

// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
	int count;		// count keeps track of how many items are in the BST.
	node_t* root;		// root points to the root node in our BST.
}bst_t;

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
// Return NULL if we couldn't allocate memory for the BST.
bst_t* create_bst(){
	// Modify the body of this function as needed.
	bst_t* myBST= malloc(sizeof(bst_t));
	
	if (myBST == NULL){
		return NULL;
	}
	myBST->count = 0;
	myBST->root = NULL;
	return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
// Returns -1 if a NULL is passed to the function
// Should run in constant time.
int bst_empty(bst_t* t){
	
	if (t == NULL){
		return -1;
	}

	if (t->root == 0){
		return 1;
	}
	else {
		return 0;
	}
}

//Create a new node
//Returns a pointer to a newly created node
node_t* creat_node(int item){
	
	node_t* newNode = malloc(sizeof(node_t));

	//Check for NULL
	if (newNode == NULL){
		return NULL;
	}

	newNode->data = item;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

//Add helper method
//For the method, we're again receieving the root node, but we also recieving the new node
int add_helper(node_t* node, node_t* newNode){
	
	if (node->data == newNode->data){
		free(newNode);
		return -1;
	}

	if (newNode->data < node->data){
		if (node->leftChild == NULL){
			node->leftChild = newNode;
			return 0;
		}
		else {
			return add_helper(node->leftChild, newNode);
		}
	}
	else {
		if (node->rightChild == NULL){
			node->rightChild = newNode;
			return 0;
		}
		else {
			return add_helper(node->rightChild, newNode);
		}
	}
	
}

// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go left, otherwise we go right.
// Returns 1 if the operation suceeds
// Returns 0 if the operation fails ( we couldn't allocate enough memory for the new node)
// Returns -1 of NULL tree has been passed in. 
// It should run in O(log(n)) time.
int bst_add(bst_t* t, int item){

	if (t == NULL){
		return -1;
	}

	node_t* node = creat_node(item);
	if (node == NULL){
		return -1;
	}

	int checkAddWorked = 0;
	if (t->root == NULL){
		t->root = node;
		return 1;
	}
	else {
		checkAddWorked = add_helper(t->root, node);
	}
	
	if (checkAddWorked == 0){
		t->count ++;
	}
		
	return checkAddWorked;

}

//Print Helper for ascending
void ascending_order(node_t* root){

	if (root->leftChild != NULL){
		ascending_order(root->leftChild);
	}
	printf("%d\n", root->data);


	if (root->rightChild != NULL){
		ascending_order(root->rightChild);
	}
}

//Print Helper for descending
void descending_order(node_t* root){

	if (root->rightChild != NULL){
		descending_order(root->rightChild);
	}
	printf("%d\n", root->data);
	
	if (root->leftChild != NULL){
		descending_order(root->leftChild);
	}
}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing. 
// It should run in O(n) time.
void bst_print(bst_t*t, int order){

	if (t == NULL){
		printf("\n");
		return;
	}

	if (t->count == 0){
		printf("\n");
		return;
	}
	
	if (order == 0){
		ascending_order(t->root);
	}
	else {
		descending_order(t->root);
	}
	
}

//Sum helper method
int sum_helper(node_t* node){

	if (node == NULL){
		return 0;
	}
	else {
		return node->data + sum_helper(node->leftChild) + sum_helper(node->rightChild);
	}
}

// Returns the sum of all the nodes in the tree. 
// Returns 0 for an empty tree.
// Returns -1 if a NULL tree is passed to the function.
// It should run in O(n) time.
int sum(bst_t *t){
  
	if (t == NULL){
		return -1;
	}
	
	if (t == 0){
		return 0;
	}
	else {
		return sum_helper(t->root);
	}
}

//Find helper method
int find_helper(node_t* root, int value){
	
	if (value == root->data){
		return 1;
	}
	else if (value > root->data && root->leftChild != NULL){
		return find_helper(root->leftChild, value);
	}
	else if (value < root->data && root->rightChild != NULL){
		return find_helper(root->rightChild, value);
	}
	return 0;
}
// Returns 1 if value is found in the tree.
// Returns 0 if the value is not found in three.
// Returns -1 if a NULL tree has been passed to the function
// It should run in O(log(n)) time.
int find(bst_t* t, int value){

	if (t == NULL){
		return -1;
	}
	else {
		return find_helper(t->root, value);
	}
}

// BST Size
// Queries the current size of the BST
// Returns the size of the tree.
// Returns -1 if a NULL tree has been passed in.
// Should run in constant time.
unsigned int bst_size(bst_t* t){
	
	if (t == NULL){
		return -1;
	}
	else {
		return t->count;
	}
}

void free_tree(node_t* node){
	
	if (node->leftChild != NULL){
		free_tree(node->leftChild);
	}

	if (node->rightChild != NULL){
		free_tree(node->rightChild);
	}

	free(node);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_bst(bst_t* t){

	if (t == NULL){
                return;
        }

//        if (t->count == 0){
                free_tree(t->root);
  //      }

        free(t);
}



#endif
