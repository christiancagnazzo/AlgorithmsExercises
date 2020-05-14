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
    
    return list;
  }

  public static void main(String[] args) throws IOException {
    Graph graph = loadGraph("input.txt");
    LinkedList<Edge> interrogation = loadInterrogation("input.txt");
    //graph.printGraph();
    }
}