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

  public void bfs(int v, int pred[], int[] weight){ 
    LinkedList<Integer> queue = new LinkedList<Integer>(); 
    int src = 1;

    boolean visited[] = new boolean[v]; 
    for (int i = 0; i < v; i++) { 
      visited[i] = false; 
      weight[i] = -1;
      pred[i] = -1; 
    } 

    visited[src] = true; 
    queue.add(src); 

    while (!queue.isEmpty()) { 
      int u = queue.remove(); 
      for (int i = 0; i < adjacencylist[u].size(); i++) { 
        if (visited[adjacencylist[u].get(i).destination] == false) { 
          visited[adjacencylist[u].get(i).destination] = true; 
          pred[adjacencylist[u].get(i).destination] = u; 
          weight[adjacencylist[u].get(i).destination] = adjacencylist[u].get(i).weight;
          queue.add(adjacencylist[u].get(i).destination);
        } 
      } 
    } 
  }

  public boolean interrogation(Edge interrogation, int[] pred, int[] weight){
    if (interrogation.weight >= this.max_weight)
      return false;
    
    int cparent = lca(interrogation.source, interrogation.destination, pred);
    int l = interrogation.source;
    int r = interrogation.destination;
  
    while (l != r){  
      if (l != cparent){
        if (weight[l] > interrogation.weight)
          return true;
        else
          l = pred[l];
      }
      if (r != cparent){
        if (weight[r] > interrogation.weight)
          return true;
        else
          r = pred[r];
      }
    }
    return false;
  }

  private int lca(int u, int v, int[] pred){
    int lca;
    boolean[] visited = new boolean[vertices+1];
    
    while(true){
      visited[u] = true; 
      if(u == 1){
        break; 
      }
      u = pred[u]; 
    }

    while(true){
      if(visited[v]){
        lca = v;    
        break;  
      }
      v = pred[v]; 
    }
    return lca; 
  }
}
