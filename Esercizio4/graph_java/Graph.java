import java.util.LinkedList;

public class Graph {
  int vertices;
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

  private LinkedList<Integer> shortestPath(LinkedList<Edge>[] adjacencylist, int s, int dest, int v) { 
    int pred[] = new int[v]; 
    int weight[] = new int[v]; 

    BFS(adjacencylist, s, dest, v, pred, weight);

    LinkedList<Integer> path = new LinkedList<Integer>(); 
    LinkedList<Integer> weight_list = new LinkedList<Integer>();
    int crawl = dest; 
    path.add(crawl); 
    while (pred[crawl] != -1) { 
      path.add(pred[crawl]); 
      weight_list.add(weight[crawl]);
      crawl = pred[crawl]; 
    } 

    return weight_list;
  }


  private static boolean BFS(LinkedList<Edge>[] adj, int src, int dest, int v, int pred[], int[] weight){ 
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
      for (int i = 0; i < adj[u].size(); i++) { 
        if (visited[adj[u].get(i).destination] == false) { 
          visited[adj[u].get(i).destination] = true; 
          pred[adj[u].get(i).destination] = u; 
          weight[adj[u].get(i).destination] = adj[u].get(i).weight;
          queue.add(adj[u].get(i).destination); 

          if (adj[u].get(i).destination == dest) 
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
  }
}
