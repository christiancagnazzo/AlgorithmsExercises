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

  public static int edit(String s1, String s2, int[][] memo){
    int i = s2.length()-1;
    int j = s1.length()-1;
    
    if (memo[i][j] != Integer.MAX_VALUE)
      return memo[i][j];
    
    if (s2.charAt(i) == s1.charAt(j))
      memo[i][j] = edit(s1.substring(0,j), s2.substring(0, i), memo);
    else
      memo[i][j] = Math.min(1 + edit(s1, s2.substring(0, i), memo), 1 +  edit(s1.substring(0,j), s2, memo));

    return memo[i][j];
  }

  public static int edit_distance_dyn(String s1, String s2){
    int[][] memo = new int[s2.length()][s1.length()]; 
    if (s1.charAt(0) == s2.charAt(0)){
      for (int i = 0; i < s2.length(); i++) //righe
        memo[i][0] = i;
      for (int i = 0; i < s1.length(); i++) //colonne
        memo[0][i] = i;
    }
    else {
      for (int i = 0; i < s2.length(); i++) //righe
        memo[i][0] = i+2;
      for (int i = 0; i < s1.length(); i++) //colonne
        memo[0][i] = i+2;
    }
    for (int i = 1; i < s2.length(); i++ )
      for (int j = 1; j < s1.length(); j++)
        memo[i][j] = Integer.MAX_VALUE;    
    return edit(s1,s2,memo);
  }

  public static void main(String[] args) {
    String s1 = "vinai";
    String s2 = "cioi";
    System.out.println(edit_distance_dyn(s1, s2));
  }
}
