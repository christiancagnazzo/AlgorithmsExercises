public class EditDistanceAlgorithm {
  
  /*
  * Edit distance calculates the minimum distance 
  * between the strings s1 and s2 passed as a parameter. 
  * The edit distance is defined as the minimum number of cancellations and insertions 
  * to be made to transform the string s2 into the string s1.
  */ 
  public static int editDistance(final String s1, final String s2){
    int d_nop, d_canc, d_ins;
    
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
  * using dynamic programming
  */ 
  public static int editDistanceDyn(final String s1, final String s2){
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    final int[][] memo = new int[s2.length()][s1.length()]; 

    for (int i = 0; i < s2.length(); i++ )
      for (int j = 0; j < s1.length(); j++)
        memo[i][j] = Integer.MAX_VALUE;  
    
    return edit(s1,s2,memo);
  }


  private static int edit(final String s1, final String s2, final int[][] memo){
    final int row = s2.length()-1;
    final int col = s1.length()-1;
    
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    if (memo[row][col] != Integer.MAX_VALUE){
      return memo[row][col];
    }

    if (s2.charAt(row) == s1.charAt(col))
      memo[row][col] = edit(s1.substring(0,col), s2.substring(0, row), memo);
    else
      memo[row][col] = Math.min(1 + edit(s1, s2.substring(0, row), memo), 1 +  edit(s1.substring(0,col), s2, memo));

    return memo[row][col];
  }

}
