import org.junit.*;
import static org.junit.Assert.*;

public class TestEditDistanceAlgorithm {

  @Test
  public void testEditDistanceEmptyString(){
    String s1 = "";
    String s2 = "";

    assertTrue( EditDistanceAlgorithm.editDistance(s1, s2) == 0);
  }

  @Test
  public void testEditDistanceOneEmptyString(){
    String s1 = "rosso";
    String s2 = "";

    assertTrue( EditDistanceAlgorithm.editDistance(s1, s2) == 5);
  }

  @Test
  public void testEditDistanceEqualsString(){
    String s1 = "pioppo";
    String s2 = "pioppo";

    assertTrue( EditDistanceAlgorithm.editDistance(s1, s2) == 0);
  }

  @Test
  public void testEditDistanceString(){
    String s1 = "tassa";
    String s2 = "passato";

    assertTrue( EditDistanceAlgorithm.editDistance(s1, s2) == 4);
  }

  @Test
  public void testEditDistanceDynEmptyString(){
    String s1 = "";
    String s2 = "";

    assertTrue( EditDistanceAlgorithm.editDistanceDyn(s1, s2) == 0);
  }

  @Test
  public void testEditDistanceDynOneEmptyString(){
    String s1 = "rosso";
    String s2 = "";

    assertTrue( EditDistanceAlgorithm.editDistanceDyn(s1, s2) == s1.length());
  }

  @Test
  public void testEditDistanceDynEqualsString(){
    String s1 = "pioppo";
    String s2 = "pioppo";

    assertTrue( EditDistanceAlgorithm.editDistanceDyn(s1, s2) == 0);
  }

  @Test
  public void testEditDistanceDynString(){
    String s1 = "tassa";
    String s2 = "passato";

    assertTrue( EditDistanceAlgorithm.editDistanceDyn(s1, s2) == 4);
  }
  
}

