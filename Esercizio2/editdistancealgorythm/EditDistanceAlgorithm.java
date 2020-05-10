
public class EditDistanceAlgorithm {

  /*
  * Edit distance calculates the minimum distance 
  * between the strings s1 and s2 passed as a parameter. 
  * The edit distance is defined as the minimum number of cancellations and insertions 
  * to be made to transform the string s2 into the string s1. Return -1 if strings are null.
  */ 
  public static int editDistance( String s1,  String s2){
    int d_nop, d_canc, d_ins;
    
    if (s1 == null || s2 == null)
      return -1;

    if (s1.length() == 0)
      return s2.length();

    if (s2.length() == 0)
      return s1.length();
    
    if (s1.charAt(0) == s2.charAt(0))
      d_nop = editDistance(s1.substring(1), s2.substring(1));
    else
      d_nop = Integer.MAX_VALUE;
    
    d_canc = 1 + editDistance(s1, s2.substring(1));
    d_ins = 1 + editDistance(s1.substring(1), s2);
    
    return Math.min(Math.min(d_nop, d_ins),d_canc);
  }

  /*
  * Edit distance dynamic calculates the minimum distance between 
  * the strings s1 and s2 passed as a parameter 
  * using dynamic programming. Return -1 if strings are null.
  */ 
  public static int editDistanceDyn(String s1,String s2){
    if (s1 == null || s2 == null)
      return -1;
    
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    int[] memo = new int[s1.length()*s2.length()];
    
    for (int i=0; i < s1.length()*s2.length(); i++)
      memo[i] = Integer.MAX_VALUE;
    
    return edit(s1,s2,memo,s1.length());
  }

  /* In an array read as a matrix the position [i,j] is found in the index [i*number_of_columns+j] */
  private static int edit( String s1,  String s2,  int[] memo, int columns){
    int row = s2.length()-1;
    int col = s1.length()-1;
    
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    if (memo[row*columns+col] != Integer.MAX_VALUE){
      return memo[row*columns+col];
    }
    
    if (s2.charAt(row) == s1.charAt(col))
      memo[row*columns+col] = edit(s1.substring(0,col), s2.substring(0, row), memo, columns);
    else
      memo[row*columns+col] = Math.min(1 + edit(s1, s2.substring(0, row), memo, columns), 1 +  edit(s1.substring(0,col), s2, memo, columns));
      
    return memo[row*columns+col];
  }
}
