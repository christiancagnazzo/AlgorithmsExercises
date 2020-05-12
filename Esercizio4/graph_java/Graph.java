import java.util.LinkedList;

public class Graph {
  int vertices;
  LinkedList<Edge> [] adjacencylist;

  public Graph(int vertices) {
    this.vertices = vertices;
    adjacencylist = new LinkedList[vertices];
    for (int i = 0; i < vertices ; i++) {
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
    for (int i = 0; i < vertices ; i++) {
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

  public int countConnectedComponents() {
    boolean[] visited = new boolean[vertices];
    int count = 0;
    int index;
    while((index = checkGraphIsVisited(visited))!=-1){
        dfs(index, visited);
        count++;
    }
    return count;
  }

  public int checkGraphIsVisited(boolean[] visited){
    for (int i = 0; i <visited.length ; i++) {
      if(!visited[i])
        return i;
    }
    return -1;
  }

  public void dfs(int start, boolean[] visited) {
    visited[start] = true;
    for (int i = 0; i < adjacencylist[start].size(); i++) {
      int destination = adjacencylist[start].get(i).destination;
      if (!visited[destination])
        dfs(destination, visited);
    }
  }

  public void edgeIsBridge(int source, int destination, int weight, Graph graph){
    graph.removeEdge(source, destination);
    int newCount = graph.countConnectedComponents();

    if(newCount == 1){
      System.out.println("Given Edge ("+source+"-"+destination+") is not a BRIDGE");
    } else {
      System.out.println("Given Edge ("+source+"-"+destination+") is a BRIDGE");
    }
    System.out.println("-----------------------------------------");
  
    graph.addEdge(source, destination, weight);
  }
}
  

