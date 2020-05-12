#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define TRUE 1
#define FALSE 0

struct _Graph {
  int vertices;
	Node** head;
};

struct _Node {
	int dest;
  int weight;
	Node* next;
};


Graph * Graph_create(Edge edges[], int vertices){
	Graph* graph = (Graph*) malloc(sizeof(Graph));
  Node ** adj = (Node **) malloc(sizeof(Node*)*vertices+1);
  graph->head = adj;
  graph->vertices = vertices;
  
	for (int i = 0; i < vertices+1; i++)
		graph->head[i] = NULL;

	for (int i = 0; i < vertices-1; i++){
    int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		Node* new_o = (Node*)malloc(sizeof(Node));
		new_o->dest = dest;
		new_o->weight = weight;

		new_o->next = graph->head[src];
    graph->head[src] = new_o;
    
    Node* new_t = (Node*)malloc(sizeof(Node));
		new_t->dest = src;
    new_t->weight = weight;
    
    new_t->next = graph->head[dest];
		graph->head[dest] = new_t;
	}

	return graph;
}

void Graph_add_edge(Graph * graph, Edge * edge){
  Node * new_o = (Node *) malloc(sizeof(Node));

  new_o->weight = edge->weight;
  new_o->dest = edge->dest;
  new_o->next = graph->head[edge->src];
  graph->head[edge->src] = new_o;

  Node * new_t = (Node *) malloc(sizeof(Node));

  new_t->weight = edge->weight;
  new_t->dest = edge->src;
  new_t->next = graph->head[edge->dest];
  graph->head[edge->dest] = new_t;
}

void Graph_dfs(Graph * graph, int start, int * visited){
  visited[start] = TRUE;
  Node * curr = graph->head[start];
  while (curr != NULL){
    int dest = curr->dest;
    if (!visited[dest])
      Graph_dfs(graph, dest, visited);
    curr = curr->next;
  }
}


int Graph_is_connected(Graph * graph){
  int visited[graph->vertices];
  for (int i = 0; i < graph->vertices; i++)
    visited[i] = FALSE;
  Graph_dfs(graph,1,visited);
  for (int i = 1; i < graph->vertices; i++)
    if (visited[i] == FALSE) 
      return FALSE;
  return TRUE;
}


void Graph_print(Graph* graph)
{
	int i;
	for (i = 0; i < graph->vertices+1; i++){
		Node* ptr = graph->head[i];
		while (ptr != NULL){
			printf("%d -> %d (%d)\t", i, ptr->dest, ptr->weight);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
