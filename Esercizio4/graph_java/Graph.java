import java.util.LinkedList;

public class Graph {
  public int vertices;
  LinkedList<Edge> [] adjacencylist;

  public Graph(int vertices) {
    this.vertices = vertices;
    adjacencylist = new LinkedList[vertices+1];
    for (int i = 1; i <= vertices ; i++) {
      adjacencylist[i] = new LinkedList<>();
    }
  }

  public void addEdge(int source, int destination, int weight){
    Edge first_edge = new Edge(source, destination, weight);
    adjacencylist[source].addFirst(first_edge);
  
    Edge second_edge = new Edge(destination, source, weight);
    adjacencylist[destination].addFirst(second_edge);
  }

  /* SOLUTION CORRECT BUT NOT EFFICIENT */ 
  /*private LinkedList<Integer> shortestPath(LinkedList<Edge>[] adjacencylist, int src, int dest, int v) { 
    int pred[] = new int[v]; 
    int weight[] = new int[v]; 

    BFS(src, dest, v, pred, weight);

    //LinkedList<Integer> path = new LinkedList<Integer>(); 
    LinkedList<Integer> weight_list = new LinkedList<Integer>();
    int w = dest; 
    //path.add(w); 
    while (pred[w] != -1) { 
      //path.add(pred[w]); 
      weight_list.addFirst(weight[w]);
      w = pred[w]; 
    } 
    for (int i = 0; i<weight_list.size(); i++)
      System.out.println(weight_list.get(i)+" ");
    return weight_list;
  }


  private boolean BFS(int src, int dest, int v, int pred[], int[] weight){ 
    LinkedList<Integer> queue = new LinkedList<Integer>(); 

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

          if (adjacencylist[u].get(i).destination == dest) 
            return true; 
        } 
      } 
    } 
    return false; 
  }

  public boolean interrogation(Edge interrogation){
    LinkedList<Integer> path = shortestPath(adjacencylist, interrogation.source,interrogation.destination, vertices+1);
    for (int i = path.size() - 1; i >= 0; i--) { 
      if (path.get(i) > interrogation.weight)
        return true;
    }
    return false;
  }*/

  /* ------------------------------------------------------------------------------------ */

  public void BFS(int v, int pred[], int[] weight){ 
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
    int cparent = LCA(interrogation.source, interrogation.destination, pred);
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

  // O(h)
  private int LCA(int u, int v, int[] pred){
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
