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

  public void printGraph(){
    for (int i = 1; i <= vertices; i++) {
      LinkedList<Edge> list = adjacencylist[i];
      for (int j = 0; j < list.size(); j++) {
        System.out.println("vertex " + i + " is connected to " +
        list.get(j).destination + " with weight " +  list.get(j).weight);
      }
    }
  }

  public void removeEdge(int source, int destination) {
    for (int i = 0; i < adjacencylist[source].size(); i++) {
      if(adjacencylist[source].get(i).destination == destination) {
        adjacencylist[source].remove(i);
        break;
      }
    }

    for (int i = 0; i < adjacencylist[destination].size(); i++) {
      if(adjacencylist[destination].get(i).destination == source) {
        adjacencylist[destination].remove(i);
        break;
      }
    }
  }

  private int countConnectedComponents() {
    boolean[] visited = new boolean[vertices+1];
    int count = 0;
    int index;
    while((index = checkGraphIsVisited(visited))!=-1){
        dfs(index, visited);
        count++;
    }
    return count;
  }

  private int checkGraphIsVisited(boolean[] visited){
    for (int i = 1; i < visited.length ; i++) {
      if(!visited[i])
        return i;
    }
    return -1;
  }

  private void dfs(int start, boolean[] visited) {
    visited[start] = true;
    for (int i = 0; i < adjacencylist[start].size(); i++) {
      int destination = adjacencylist[start].get(i).destination;
      if (!visited[destination])
        dfs(destination, visited);
    }
  }

  private boolean edgeIsBridge(int source, int destination, int weight){
    removeEdge(source, destination);
    int newCount = countConnectedComponents();
    addEdge(source, destination, weight);

    if(newCount == 1){
      return false;
    } else {
      return true;
    }
  }

  public boolean interrogation(Edge interrogation){
    addEdge(interrogation.source, interrogation.destination, interrogation.weight);
    for (int i = 1; i <= vertices; i++) {
      LinkedList<Edge> list = adjacencylist[i];
      for (int j = 0; j < list.size(); j++) {
        if (list.get(j).weight > interrogation.weight){
          if (!edgeIsBridge(list.get(j).source,list.get(j).destination,list.get(j).weight)){
            removeEdge(interrogation.source, interrogation.destination);
            return true;
          }
        }
      }
    }
    removeEdge(interrogation.source, interrogation.destination);
    return false;
  }
  
}
  

