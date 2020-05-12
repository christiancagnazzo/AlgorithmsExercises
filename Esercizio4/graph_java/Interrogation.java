public class Interrogation {
  public static void main(String[] args) {
    int vertices = 6;
    Graph graph = new Graph(vertices);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 9);
    graph.addEdge(3, 4, 3);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 4);

    graph.edgeIsBridge(0,1, 4,graph);
    graph.edgeIsBridge(3,4, 3,graph);
    graph.edgeIsBridge(2,3, 9,graph);
    }
}