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
    Graph graph = new Graph(vertices);

    int i = 1;
    while (i < vertices){
      s = b.readLine();
      StringTokenizer tok = new StringTokenizer(s);
    
      while (tok.hasMoreTokens()){
        int source = Integer.parseInt(tok.nextToken());
        int destination = Integer.parseInt(tok.nextToken());
        int weight = Integer.parseInt(tok.nextToken());
        graph.addEdge(source, destination, weight);
      }
      i++;
    } 

    filein.close();
    return graph; 
  }

  static ArrayList<Edge> loadInterrogation(String file_name) throws IOException {
    
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
    
    ArrayList<Edge> list = new ArrayList<>();

    i = 0;
    do {
      s = b.readLine();
      StringTokenizer tok = new StringTokenizer(s);

      while (tok.hasMoreTokens()){
        Edge new_edge = new Edge(Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()));
        list.add(new_edge);
      }
      i++;
    } while (i < interrogation);

    b.close();
    return list;
  }

  public static void main(String[] args) throws IOException {
    if (args.length != 2){
      System.out.println("Parameters error - Usage: java Interrogation <file input> <file output>");
      return;
    }
    
    Graph graph = loadGraph(args[0]);
    ArrayList<Edge> list = loadInterrogation(args[0]);

    int vertices = graph.getVertices();
    int[] weight = new int[vertices+1];
    int[] pred = new int[vertices+1];
    int[] levels = new int[vertices+1];

    graph.bfs(vertices+1, pred, weight, levels);
   
    FileWriter file = new FileWriter(args[1]);
    BufferedWriter f = new BufferedWriter(file);

    for (int j = 0; j < list.size(); j++){
      if (graph.interrogation(list.get(j),pred,weight,levels))
        f.write("YES\n");
      else
        f.write("NO\n");
    }
    
    f.flush();
    f.close();
  }

 
}