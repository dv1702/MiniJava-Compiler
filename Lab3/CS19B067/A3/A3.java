import syntaxtree.*;
import visitor.*;
import java.util.*;

public class A3 {
   public static void main(String [] args) {
      try {
         Node root = new MiniJavaParser(System.in).Goal();
         HashMap<String, SymbolTable> table = new HashMap<String, SymbolTable>();
         root.accept(new SymbolTableGenerator<>(), table); // Your assignment part is invoked here.

         root.accept(new MicroIRGenerator<>(), table);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 

