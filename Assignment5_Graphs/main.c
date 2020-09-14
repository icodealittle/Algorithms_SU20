// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void test1(){
 
    graph_t * testGraph = create_graph();
    printf("Adding 1 to graph.  Return: %d\n", graph_add_node(testGraph, 1));
    printf("Adding 2 to graph. Return: %d\n", graph_add_node(testGraph, 2));
    printf("Adding 4 to graph. Return: %d\n", graph_add_node(testGraph, 4));
    printf("Adding 11 to graph. Return: %d\n", graph_add_node(testGraph, 11));
    printf("Adding 8 to graph. Return: %d\n", graph_add_node(testGraph, 8));
    printf("Adding 16 to graph. Return: %d\n", graph_add_node(testGraph, 16));
    printf("Num nodes: %d\n", graph_num_nodes(testGraph));
    printf("Adding 8 AGAIN to graph. Return: %d\n", graph_add_node(testGraph, 8));
    printf("Total nodes: %d\n", graph_num_nodes(testGraph));
	printf("3 is not in graph. Return: %d\n", find_node(testGraph, 3));

	//Add edges
    printf("Adding edges from source 2 to destination 4. Return: %d\n", graph_add_edge(testGraph, 2, 4));
    printf("Adding edges from source 2 to destination 16. Return: %d\n", graph_add_edge(testGraph, 2, 16));
    printf("Adding edges from source 4 to destination 8. Return: %d\n", graph_add_edge(testGraph, 4, 8));
    printf("Adding edges from source 4 to destination 11. Return: %d\n", graph_add_edge(testGraph, 4, 11));
    printf("Adding edges from source 8 to destination 11. Return: %d\n", graph_add_edge(testGraph, 8, 11));
    printf("Adding edges from source 8 to destination 16. Return: %d\n", graph_add_edge(testGraph, 8, 16));
    printf("Adding edges from source 11 to destination 8. Return: %d\n", graph_add_edge(testGraph, 11, 8));
    printf("Adding edges from source 11 to destination 2. Return: %d\n", graph_add_edge(testGraph, 11, 2));
    printf("Adding edges from source 11 to destination 11. Return: %d\n", graph_add_edge(testGraph, 11, 11));
    printf("Adding edges from source 16 to destination 4. Return: %d\n", graph_add_edge(testGraph, 16, 4));
    printf("Adding edges from source 1 to destination 4. THIS DOESNT EXIST. Return: %d\n", graph_add_edge(testGraph, 1, 4));
    printf("Adding edges from source 16 to destination 4. THIS EXISTS ALREADY. Return: %d\n", graph_add_edge(testGraph, 16, 4));
    printf("2->7 does not exist in graph. Return: %d\n", contains_edge(testGraph, 2,7));
   printf("Removing edges from source 11 to destination 11. Return: %d\n", graph_remove_edge(testGraph, 11, 11));
    printf("11->11 does not exist in graph. Return: %d\n", contains_edge(testGraph, 11,11));
    printf("Num of edges now: %d\n", graph_num_edges(testGraph));
	printf("In Neigbors: %d\n", getNumOutNeighbors(testGraph, 4));
	printf("Out Neighbors: %d\n", getNumInNeighbors(testGraph, 8));

	printf("11 cant reach 1. returns %d\n", is_reachable(testGraph, 11, 1));
    printf("Has a cycle. returns %d\n", has_cycle(testGraph));
	print_path(testGraph,11, 3);	
    free_graph(testGraph);
    
}

void test2(){

	graph_t * graph = create_graph();
	graph_add_node(graph, 1);
	graph_add_node(graph, 1);
	graph_add_node(graph, 2);
	printf("total nodes: 2 == %d\n", graph_num_nodes(graph));

	free_graph(graph);
}

void test3(){
	graph_t* graph = NULL;
	graph_add_node(graph, 3);
	graph_add_node(graph, 5);
	graph_add_edge(graph, 3, 5);
	printf("Num of edges: %d\n", graph_num_edges(graph));
	printf("In Neigbors: %d\n", getNumOutNeighbors(graph, 3));
	printf("Out Neighbors: %d\n", getNumInNeighbors(graph, 5));
	printf("Total nodes: %d\n", graph_num_nodes(graph));
	printf("4 is not in graph. returns %d\n", find_node(graph, 4));
	printf("Remove: %d\n",graph_remove_node(graph, 5)); 
	printf("Has a cycle. returns %d\n", has_cycle(graph));
	printf("Num of edges now: %d\n", graph_num_edges(graph));
	free_graph(graph);

}	

void test4(){

	graph_t * graph = create_graph();
	graph_add_node(graph, 4);
	graph_add_node(graph, 8);
	graph_add_node(graph, 7);
	printf("5 is not in graph. returns %d\n", find_node(graph, 5));
	printf("Total nodes: %d\n", graph_num_nodes(graph));
	graph_add_edge(graph, 4, 8);
	printf("Num of edges: %d\n", graph_num_edges(graph));
	printf("Is 2 still in the graph? return: %d\n", find_node(graph, 2));
	free_graph(graph);
	
}

void test5(){

	graph_t * graph = create_graph();
	graph_add_node(graph, 1);
	graph_add_node(graph, 2);
	graph_add_node(graph, 4);
	printf("Total nodes: %d\n", graph_num_nodes(graph));
	printf("Removing 2 from graph. returns: %d\n", graph_remove_node(graph, 2));
	free_graph(graph);
}
	
int main() {
	
	printf("===================================\n");

	test1();

	printf("===================================\n");

	test2();
	
	printf("===================================\n");
	
	test3();
	
	printf("===================================\n");
	
	test4();
	
	printf("===================================\n");
	
	test5();
    return 0;
}
