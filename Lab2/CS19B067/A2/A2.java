import syntaxtree.*;
import visitor.*;
import java.util.*;

public class A2 {
   public static void main(String [] args) {
      try {
         Node root = new MiniJavaParser(System.in).Goal();
         HashMap<String, SymbolTable> table = new HashMap<String, SymbolTable> ();

         root.accept(new GJDepthFirst(), table);
         root.accept(new TypeCheck(), table);
         //System.out.println("Program parsed successfully");
         System.out.println("Program type checked successfully");
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 

