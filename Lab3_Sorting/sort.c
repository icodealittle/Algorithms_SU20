// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int* array, int start, int stop){
    // TODO: Iterate through a subset of the array and find the minimum value.
    //       Return the index of that minimum value.
	

	int minimum_value = start;
	
	//Loop Statment
	for (int i = start + 1; i < stop; i++){
		//Loop within loop statement
		//Using 2D array
		//Comparing a lit of 2D array of the 
		//start – minimum value, of the list to the 2D array index.
		if (array[minimum_value] > array[i]){
			minimum_value = i;
		}
	}  
    return minimum_value; // TODO: Modify this to return the
}

// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
void swap(int* a, int* b){
    // TODO: Swap two integers in an array.

	//Temp variable that assigned to 'a*' before swap with b and vice versa
	int swap_integer = *a;

	*a = *b;
	
	*b = swap_integer;
}

// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
    // TODO: Implement selection sort
	
	//First Loop
	for (int j = 0; j  < size - 1; j++){
		int mini_value = findMinimum(array, j + 1, size);
		//Second Loop
		if (array[mini_value] < array[j]){
			swap(&array[mini_value], &array[j]); //Swap the unsorted list
		}
	}
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
