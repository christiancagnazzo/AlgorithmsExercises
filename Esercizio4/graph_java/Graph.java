import java.util.ArrayList;
import java.util.LinkedList;


public class Graph {
  private int vertices;
  private ArrayList<Edge> [] adjacencylist;
  private int max_weight;

  public Graph(int vertices) {
    this.vertices = vertices;
    this.adjacencylist = new ArrayList[vertices+1];
    for (int i = 1; i <= vertices ; i++) {
      adjacencylist[i] = new ArrayList<>();
    }
    this.max_weight = 0;
  }

  public void setMaxWeight(int weight){
    this.max_weight = weight;
  }

  public int getVertices(){
    return this.vertices;
  }

  public void addEdge(int source, int destination, int weight){
    Edge first_edge = new Edge(source, destination, weight);
    adjacencylist[source].add(first_edge);
  
    Edge second_edge = new Edge(destination, source, weight);
    adjacencylist[destination].add(second_edge);
  }

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
