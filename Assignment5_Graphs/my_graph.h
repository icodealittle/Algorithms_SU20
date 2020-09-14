// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
}graph_t;

typedef struct graph_node{
    int data;
    dll_t* inNeighbors; //The nodes that list inNeighbor
    dll_t* outNeighbors; //The nodes that list outNeighbor
}graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}


//Returns the node pointer if the node exists.
//Returns NULL if the node doesn't exist or the graph is NULL
//Ietrator DLL graph node
graph_node_t* find_node( graph_t * g, int value){

	if (g == NULL){
		return NULL;
	}
	
	node_t* iterator = g->nodes->head;
	while (iterator != NULL){
		graph_node_t* tempNode = iterator->data; 
		if (tempNode->data == value){
			return tempNode;
		}
			iterator = iterator->next;
	}
	return NULL;
}

graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    
    return graph_node;
}


//Returns 1 on scucess
//Returns 0 on failure ( or if the node already exists )
//Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return -1;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

//Returns 1 on success
//Returns 0 on failure ( or if the node doesn't exist )
//Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    //The function removes the node from the graph along with any edges associated with it.
    //That is, this node would have to be removed from all the in and out neighbor's lists that countain it.
 	
	if (g == NULL){
		return -1;
	}
	graph_node_t* tempNode = find_node(g, value);
	if (tempNode == 0){
		return 0;
	}

	//Iterator process

	node_t* iterator = g->nodes->head;
	while (iterator != NULL){

		graph_node_t* temp_node = iterator->data;

		dll_remove_value(temp_node->inNeighbors, tempNode);

		dll_remove_value(temp_node->outNeighbors, tempNode);

		iterator = iterator->next;

	}


	dll_remove_value(g->nodes, tempNode);
	free(tempNode);
	return 1;

}



//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
//Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    //The function adds an edge from source to destination but not the other way.
    //Make sure you are not adding the same edge multiple times.
        //Make sure you modify the in and out neighbors appropriatelly. destination will be an out neighbor of source.
    //Source will be an in neighbor of destination.
    

	if (g == NULL){
		return -1;
	}

	graph_node_t* node_source = find_node(g, source);
	graph_node_t* node_dest = find_node(g, destination);

	
	if (node_source == NULL){
		return 0;
	}

	if (node_dest == NULL){
                return 0;
        }
	
	dll_push_back(node_dest->inNeighbors, node_source);
	dll_push_back(node_source->outNeighbors, node_dest);

	
	g->numEdges ++;
	return 1;
}


//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
//Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    //The function removes an edge from source to destination but not the other way.
    //Make sure you remove destination from the out neighbors of source.
    //Make sure you remove source from the in neighbors of destination.
    
	if (g == NULL){
		return -1;
	}
	
	graph_node_t* node_source = find_node(g, source);
	graph_node_t* node_dest = find_node(g, destination);
	
	if (node_source == NULL){
		return 0;
	}

	if (node_dest == NULL){
                return 0;
        }

	dll_remove_helper(node_source->outNeighbors, node_dest);
	dll_remove_helper(node_dest->inNeighbors, node_source);
	
	g->numEdges--;
	return 1;
}


//Returns 1 on success
//Returns 0 on failure ( or if the source or destination nodes don't exist )
//Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destintaion){
    
	if (g == NULL){
		return -1;
	}

	if (find_node(g, source) == 0){
		return 0;
	}

	if (find_node(g, destintaion) == 0){
		return 0;
	}
	
	graph_node_t* temp_source_node = find_node(g, source);
	graph_node_t* temp_dest_node = find_node(g, destintaion);
	
	return DLL_find(temp_source_node->outNeighbors, temp_dest_node) && DLL_find(temp_dest_node->inNeighbors, temp_source_node);
	
	
}

//Returns dll_t* of all the in neighbors of this node.
//Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors(graph_t * g, int value ){

	if (g == NULL){
		return NULL;
	}
	
	graph_node_t* node = find_node(g, value);
	//dll_t* node = (dll_t*) malloc(sizeof(dll_t));
	
	if (node == NULL){
		return NULL;
	}
	
	return node->inNeighbors;
}

//Returns the number of in neighbors of this node.
//Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    
	 if (g == NULL){
                return -1;
        }
	
	graph_node_t* temp_node = find_node(g, value);
	if (temp_node == NULL){
		return -1;
	}
	
	return temp_node->inNeighbors->count;
}

//Returns dll_t* of all the out neighbors of this node.
//Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){

	if (g == NULL){
		return NULL;
	}
	
	graph_node_t* node = find_node(g, value);

	
	if (node == NULL){
		return NULL;
	}
	
	return node->outNeighbors;
	
}

//Returns the number of out neighbors of this node.
//Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    
	 if (g == NULL){
                return -1;
        }
	
	graph_node_t* temp_node = find_node(g, value);
	if (temp_node == NULL){
		return -1;
	}
	
	return temp_node->outNeighbors->count;
	
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    
	if (g == NULL){
		return -1;
	}
	return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    

	if (g == NULL){
		return -1;
	}
	return g->numEdges;
}

//Returns 1 if reachable
//Returns 0 if not reachable.
//Returns -1 if the graph is NULL or if either of the nodes doesn't exist.
int is_reachable(graph_t * g, int source, int dest){
    //Implement using BFS.
    //Make sure you don't get stuck into an infinite loop.
	
	if (g == NULL){
		return -1;
	}
	
// 	if ((find_node(g, source) == 0) && (find_node(g, dest) == 0)){
// 		return 0;
// 	}

	if (source == dest){
		return 1;
	}
	
	int found = 0;
	int visits = 0;
	
	dll_t* gDLL = create_dll(graph_num_nodes(g));
	node_t* itr = g->nodes->head;
	graph_node_t* current_node = NULL;
	graph_node_t* nei_node = current_node->outNeighbors;
	dll_push_front(gDLL, itr->data);
	while (dll_empty(gDLL) != NULL){
		visits = dll_pop_back(gDLL);
		if (visits == dest){
			found = 1;
			break;
		}
		current_node = find_node(g, visits);
		nei_node = current_node->outNeighbors;
		while (nei_node != NULL){
			if (current_node->outNeighbors != NULL){
				dll_pop_back(gDLL);
			}
			nei_node = nei_node->data;
		}
	}
	free_dll(gDLL);
	
	
// // 	dll_push_front(source);
// 	dll_t* outNeighbors = source.outNeighbors;
// 	for (outNeighbors : outNeighbors){
// 		if (outNeighbors.visits != 1){
// 			int found = is_reachable(g, outNeighbors, dest);
// 			if (found == 1){
// 				return 1;
// 			}
// 		}
// 	}
	return 0;
}


//Returns 1 if the graph has a cycle.
//Returns 0 if the graph doesn't have a cycle.
//Returns -1 if the graph is NULL or if either of the nodes doesn't exist.
int has_cycle(graph_t * g){
    //Implement using DFS.
    //Make sure you don't get stuck into an infinite loop.
	
	if (g == NULL){
		return -1;
	}

// 	//TA mentioned to Austin and Austin walked me throught about the implement of a brute force implementation
// 	int a;
// 	int b;
// 	for (a = 0; a < g->nodes; a++){
// 		for (b = 0; b < g->nodes; b++){
// 			if (a != b){
// 				if ((is_reachable(g, ((graph_node_t*) dll_get(g->nodes, a))->data, 
// 				     ((graph_node_t*) dll_get(g->nodes, b))->data)) &&
// 					(is_reachable(g, ((graph_node_t*) dll_get(g->nodes, b))->data, 
// 						      ((graph_node_t*) dll_get(g->nodes, a))->data))){
// 						return 1;
// 					}
// 			}
// 		}
// 	}
	
	int found = 0;
	int visits = 0;
	
	dll_t* gDLL = create_dll(graph_num_nodes(g));
	node_t* itr = g->nodes->head;
	graph_node_t* current_node = NULL;
	graph_node_t* nei_node = current_node->outNeighbors;
	dll_push_front(gDLL, itr->data);
	while (dll_empty(gDLL) != NULL){
		visits = dll_pop_back(gDLL);
		if (g == visits){
			found = 1;
			break;
		}
		current_node = find_node(g, visits);
		nei_node = current_node->outNeighbors;
		while (nei_node != NULL){
			if (current_node->outNeighbors != NULL){
				dll_pop_back(gDLL);
			}
			nei_node = nei_node->data;
		}
	}
	free_dll(gDLL);
	
    return 0;
}
				    
//Prints all the nodes from source to destination ( including the source and destination),
//i.e. print_path(1,5) => 1 2 3 4 5
//otherwise it prints "path does not exit" or if source or dest nodes do not exist or if the graph is NULL.
void print_path(graph_t * g, int source, int dest){
	
	if (g == NULL){
		return -1;
	}

	if (is_reachable(g, source, dest) == NULL){
		printf("Path does not exist\n", source);
	}
	
	if (source == dest){
		printf("Path does not exist\n", source);
	}
	
	if (is_reachable(g, source, dest) == 0){
		printf("Path does not exist\n", source);
	}
	
	if (source != dest){
		node_t* temp_node = g->nodes->head;
		graph_node_t* node = temp_node->data;
		while (node != NULL){
			if (node->data == dest){
				printf("%d\n", dest);
			}
			
			if (is_reachable(g, node->data, dest) == 0){
				break;
			}
		}
		if (node != NULL){
			print_path(g, node->data, dest);
		}
	}
	
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){

	if (g == NULL){
		return;
	}
	
	node_t* temp_node = g->nodes->head;
	while (temp_node != NULL){
		graph_node_t* graphNode = (graph_node_t*) temp_node->data;
		free_dll(graphNode->inNeighbors);
		free_dll(graphNode->outNeighbors);
		free(graphNode);
		temp_node = temp_node->next;
	}
	
	free_dll(g->nodes);
	free(g);
	
}



#endif
