package graph;

import java.util.ArrayList;
import java.util.LinkedList;
import edge.Edge;

public class Graph {
  private int vertices;
  private ArrayList<Edge> [] adjacencylist;
  private int max_weight;

  public Graph(int vertices) {
    this.vertices = vertices;
    this.max_weight = Integer.MIN_VALUE;
    this.adjacencylist = new ArrayList[vertices+1];
    for (int i = 1; i <= vertices ; i++) {
      adjacencylist[i] = new ArrayList<>();
    }
  }

  public int getVertices(){
    return this.vertices;
  }

  public void addEdge(int source, int destination, int weight){
    Edge first_edge = new Edge(source, destination, weight);
    adjacencylist[source].add(first_edge);
  
    Edge second_edge = new Edge(destination, source, weight);
    adjacencylist[destination].add(second_edge);

    if (weight > this.max_weight)
      this.max_weight = weight;
  }


  /* Visit of the graph. It requires as 
  input the vertex from which to start the visit and three arrays 
  that are filled with parent and the level of each vertex and the 
  weight of the branch that connects each node to the parent */ 

  public void bfs(int v, int pred[], int[] weight, int[] levels){ 
    LinkedList<Integer> queue = new LinkedList<Integer>(); 
    int src = 1;

    boolean visited[] = new boolean[v]; 
    for (int i = 0; i < v; i++) { 
      visited[i] = false; 
      weight[i] = -1;
      pred[i] = -1; 
    } 

    visited[src] = true; 
    levels[src] = 0;
    queue.add(src); 

    while (!queue.isEmpty()) { 
      int u = queue.remove(); 
      for (int i = 0; i < adjacencylist[u].size(); i++) { 
        if (visited[adjacencylist[u].get(i).destination] == false) { 
          levels[adjacencylist[u].get(i).destination] = levels[u] + 1;
          visited[adjacencylist[u].get(i).destination] = true; 
          pred[adjacencylist[u].get(i).destination] = u; 
          weight[adjacencylist[u].get(i).destination] = adjacencylist[u].get(i).weight;
          queue.add(adjacencylist[u].get(i).destination);
        } 
      } 
    } 
  }


  /* Returns true if the edge passed as input can replace another edge
  by keeping the cycle connected and reducing its weight. It also requires 
  as input the arrays of the parent, the level and weight of 
  the branch with the dad of each node obtained from the bfs */

  public boolean interrogation(Edge interrogation, int[] pred, int[] weight, int[] levels){
    if (interrogation.weight >= this.max_weight)
      return false;
    
    int l = interrogation.source;
    int r = interrogation.destination;

    int min_lev = Math.min(levels[l], levels[r]);
    
    while (levels[l] != min_lev){
      if (weight[l] > interrogation.weight)
        return true;
      l = pred[l];
    }

    while (levels[r] != min_lev){
      if (weight[r] > interrogation.weight)
        return true;
      r = pred[r];
    }

    while (l != r){
      if (weight[l] > interrogation.weight)
        return true; 
      l = pred[l];
      if (weight[r] > interrogation.weight)
        return true; 
      r = pred[r];
    }

    return false;
  }
}
