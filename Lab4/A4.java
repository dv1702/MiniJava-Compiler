import syntaxtree.*;
import visitor.*;
import java.util.*;

public class A4 {
   public static void main(String [] args) {
      try {
         Node root = new microIRParser(System.in).Goal();
         // System.out.println("Program parsed successfully");
         HashMap<String, Integer> labelMap = (HashMap<String, Integer>)root.accept(new LabelMapping<>(), null);
         Analysis analysis = (Analysis)root.accept(new LivenessLCA<>(), labelMap);
         root.accept(new MiniRAGenerator<>(), analysis);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 

