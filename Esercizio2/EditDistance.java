public class EditDistance{
  public static int edit_distance(String s1, String s2){
    int d_nop, d_canc, d_ins;
    
    if (s1.length() == 0)
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    if (s1.charAt(0) == s2.charAt(0))
      d_nop = edit_distance(s1.substring(1), s2.substring(1));
    else
      d_nop = Integer.MAX_VALUE;
    
    d_canc = 1 + edit_distance(s1, s2.substring(1));
    d_ins = 1 + edit_distance(s1.substring(1), s2);
    
    return Math.min(Math.min(d_nop, d_ins),d_canc);
  }

  private static int edit(String s1, String s2, int[][] memo){
    int i = s2.length()-1;
    int j = s1.length()-1;
    
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    if (memo[i][j] != Integer.MAX_VALUE){
      return memo[i][j];
    }

    if (s2.charAt(i) == s1.charAt(j))
      memo[i][j] = edit(s1.substring(0,j), s2.substring(0, i), memo);
    else
      memo[i][j] = Math.min(1 + edit(s1, s2.substring(0, i), memo), 1 +  edit(s1.substring(0,j), s2, memo));

    return memo[i][j];
  }

  public static int edit_distance_dyn(String s1, String s2){
    if (s1.length() == 0)   
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    int[][] memo = new int[s2.length()][s1.length()]; 

    for (int i = 0; i < s2.length(); i++ )
      for (int j = 0; j < s1.length(); j++)
        memo[i][j] = Integer.MAX_VALUE;  
    
    return edit(s1,s2,memo);
  }
}
