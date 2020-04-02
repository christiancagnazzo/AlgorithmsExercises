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
}