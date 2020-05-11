#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define ERROR_EXIT_CODE 1

int main(int argc, char const *argv[]){
  if (argc != 2){
    printf("Parameters error - usage: app <input file>");
    exit(ERROR_EXIT_CODE);
  }

  // reading file
  FILE * file = fopen(argv[1], "r");
  int vertices, src, dest, weight, q;
  fscanf(file,"%d\n",&vertices);
  Edge graph_edge[vertices-1];
  int i = 0;
  while (i < (vertices-1)){
    fscanf(file,"%d%d%d\n",&src,&dest,&weight);
    graph_edge[i].src = src;
    graph_edge[i].dest = dest;
    graph_edge[i].weight = weight;
    i++;
  }
  fscanf(file,"%d\n",&q);
  Edge interrogation[q];
  i = 0;
  while (i < (q)){
    fscanf(file,"%d%d%d\n",&src,&dest,&weight);
    interrogation[i].src = src;
    interrogation[i].dest = dest;
    interrogation[i].weight = weight;
    i++;
  }
  fclose(file);

  Graph * graph = Graph_create(graph_edge,vertices);
  //Graph_print(graph);  
  printf("Connesso: %d\n", Graph_edge_is_bridge(graph));
}