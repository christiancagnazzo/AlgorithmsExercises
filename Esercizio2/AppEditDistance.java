import java.io.*;
import java.util.ArrayList;

public class AppEditDistance {
  
  private static ArrayList<String> load_data(String pathname){
    
    ArrayList<String> str = new ArrayList<String>();
    try {
      FileReader filein = new FileReader(pathname);      
      int next;
      do {
        next = filein.read(); 
        String s = "";
        while (next != -1 && Character.isLetter(next)){
          s+= (char) next;
          next = filein.read();
        }
        if (s != "")
          str.add(s.toLowerCase());
      } while (next != -1);
      filein.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
    return str;

  }

  public static void print(String word, ArrayList<String> corrector){

    System.out.println("\nParola:\t "+word);
    System.out.print("Forse volevi scrivere:\t");
    
    for (int i = 0; i < corrector.size(); i++)
      System.out.print(corrector.get(i)+"\t");

  }

  public static void correct_me(ArrayList<String> dictionary, ArrayList<String> text){
    
    ArrayList<String> list = new ArrayList<String>();
    
    for (int i = 0; i < text.size(); i++){
      list.clear();  
      int min = Integer.MAX_VALUE;
      for (int j = 0; j < dictionary.size(); j++){
        int k = EditDistance.edit_distance_dyn(dictionary.get(j), text.get(i));
        if (k < min){
          list.clear();
          min = k;
          list.add(dictionary.get(j));
        }
        else if (k == min)
          list.add(dictionary.get(j));
      }
    
    //print(text.get(i),list);

    }  
  }
  

  public static void main(String[] args) throws IOException {
    
    if (args.length != 2){
      System.out.println(" java AppEditDistance <path dictionary> <path text>");
      return;
    } 
  
    ArrayList<String> dictionary = load_data(args[0]); 
    ArrayList<String> text = load_data(args[1]);

    correct_me(dictionary, text);

    }
}
