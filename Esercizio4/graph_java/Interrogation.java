import java.io.*;
import java.util.*;

public class Interrogation {
  static Graph loadGraph(String file_name) throws IOException {

    FileReader filein = new FileReader(file_name);   
    BufferedReader b = new BufferedReader(filein);      
    int vertices;

    String s = "";
    s = b.readLine();
    vertices = Integer.parseInt(s);
    Graph new_graph = new Graph(vertices);

    int i = 1;
    while (i < vertices){
      s = b.readLine();
      StringTokenizer tok = new StringTokenizer(s);
    
      while (tok.hasMoreTokens()){
        new_graph.addEdge(Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()));
      }
      i++;
    } 

    filein.close();
    return new_graph; 
  }

  static LinkedList<Edge> loadInterrogation(String file_name) throws IOException {
    
    FileReader filein = new FileReader(file_name);   
    BufferedReader b = new BufferedReader(filein); 
    int interrogation, vertices;

    String s = b.readLine();
    vertices = Integer.parseInt(s);
    
    int i = 1;
    while (i < vertices){
      b.readLine();
      i++;
    }

    s = b.readLine();
    interrogation = Integer.parseInt(s);
    
    LinkedList<Edge> list = new LinkedList<>();

    i = 0;
    do {
      s = b.readLine();
      StringTokenizer tok = new StringTokenizer(s);

      while (tok.hasMoreTokens()){
        Edge new_edge = new Edge(Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()));
        list.addFirst(new_edge);
      }
      i++;
    } while (i < interrogation);

    b.close();
    return list;
  }

  public static void main(String[] args) throws IOException {
    Graph graph = loadGraph("graph_substitution_tests/test4/input.txt");
    LinkedList<Edge> interrogation = loadInterrogation("graph_substitution_tests/test4/input.txt");
    /*Graph graph = new Graph(6);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 3);
    graph.addEdge(3, 4, 5);
    graph.addEdge(3, 5, 4);
    graph.addEdge(2, 6, 4);*/
    //  LinkedList<Edge> interrogation = new LinkedList<>();
    //interrogation.add(new Edge(257, 249, 4));
    //int vertices = 6;
    int vertices = graph.vertices;
    int[] weight = new int[vertices+1];
    int[] pred = new int[vertices+1];
    graph.BFS(vertices+1, pred, weight);
   
    FileWriter file = new FileWriter("output.txt");
    BufferedWriter b = new BufferedWriter(file);

    for (int i = interrogation.size()-1; i >= 0 ; i--){
      if (graph.interrogation(interrogation.get(i),pred,weight))
        b.write("YES\n");
      else
        b.write("NO\n");
    }

    b.flush();
    b.close();
  }

 
}