
# Insertion Sort 

For this assignment, you are going to implement in 'C' insertion sort. A skeleton file has been provided called `sort.c`. You will know your result is correct, if the data you have sorted is done so in ascending order.

## Insertion sort at a high level

<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif" alt="Stack picture">

Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It starts by splitting the input array into a sorted and unsorted part. At each iteration it looks at the first element in the unsorted part of the array and tries to place it in the right position in the sorted part of the array. As the sort progresses the unsorted part becomes smaller and smaller eventually leading the the sorted part of the array becoming the size of the entire array. 

Insertion sort provdes several advantages over other sorts (although slower then more efficient sorts such as heapsort, quicksort, or mergesort which we will later learn):

* It is simple to implement 
* It is more efficient in practice than most other simple quadratic (i.e., O(n2)) sorts such as selection sort or bubble sort
* It is efficient for data sets that are already substantially sorted: 
* It does in-place sorting, that is only requires a constant amount O(1) of additional memory space (i.e. no additional arrays are created to temporarily store data)

You can watch [this](https://youtu.be/OGzPmgsI-pQ) to visually see how insertiong srt works.

## Pseudo-code

The pseudo-code for insertion sort goes as follows
```c
1. Start with the first element being in the sorted part of your array.
2. Look at the first element of the unsorted part of your array. 
3. Iterate through the sorted part of your array, find the correct position where to insert the element form part 2.
   - (Hint: you need to put the element in front of the first element that is smaller than your current element. )
4. Repeat steps 2. and 3. untill the sorted part of your array becoems the entire array.
```

Note: Regardles if we are using an array or a linked list, the algorithm looks the same. However, for this assignment, an array is slightly easier to work with.

## Designing the algorithm

An algorithm itself does not have to be one single function. Sometimes it is helpful to have some 'helper functions' to make the code easier to understand. For insertion sort, we recommend at least functions: 

1. swap -- Swaps two integers in an array
2. sortIntegers -- This is where you will perform the actual insertion sort.

## Compiling and running the program.

When you have made an attempt at the sorting algorithm, go ahead and try to run it. Remember to save, compile, and test early and often!

* Compile the source code with: `clang sort.c -o sort`
* Run the source code with: `./sort`

# Part 2 - Insertion Sort Complexity Q & A.

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-Oh (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. n^2 is the worst-case complexity of this algorithm assignment. It is in a reverse, therefore we need to use n - 1 to compare any insertion from the previous element and to swap the nodes. As you compare the second and thrid, fourth, etc. node of the elements – the method is still the same. n - 2 for the second comaprison and swap, n - 3 for the third comparison and swap, n - 4 for the comparison and swap, etc. The repeat formula fo rthis method is: n(n-1) = n^2.
2. An already sorted list is the best case complexity for n in this algorithm assighment. Because of the all the array lists are already sorted, there are no loops being implements, whereas loop implementations are needed  for any worst-case complexity sort. A good example for the best case complexity is an array list of [1, 2, 3, 4, 5, 6, 7, 8]. 
3. If the array is already mostly sorted, Insertion Sort does well because there is less need to transpose elements. Insertion Sort requires very little extra space to function; it only needs to reserve space for a single element, especially with O(1) (oreilly).
4. A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted. An insertion sort algorithms is a stable sort because you can/allow only to swap the node elements if any of the element is larger then the ke, which is make it stable simce you're switching any of the element. 


# Deliverable

- Modify the file called **sort.c** and implement a version of insertion sort that sorts numbers in ascending order.
- Answer the questions in Part 2
  
# Rubric

- 40% Correct implementation of insertion sort (and not some other sort)
  - There should be no memory leaks
  - There should be no bugs in your functions 
  - Your implementation will be graded by our set of unit tests, and we will check your code 'style' as well.  
- 10% Correct answers to part 2
   - Make sure to edit your readme.

# More resources to help

- [Insertion sort video](https://www.youtube.com/watch?v=OGzPmgsI-pQ)
- [Khan Academy Sorting, pseudocode, analysis, and exercise](https://www.khanacademy.org/computing/computer-science/algorithms/insertion-sort/a/insertion-sort)

# (Optional) Going Further Task:

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task.

- Implement insertion sort, but this time, use a linked list as the storage data structure, instead of an array.

