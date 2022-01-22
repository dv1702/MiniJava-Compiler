package visitor;
import java.util.*;

public class SymbolTable {
    public String className;
    public String parentClass;
    public HashMap<String, String> fieldVariable;
    public HashMap<String, MethodInfo> method;

    public SymbolTable(){
        this.className = null;
        this.parentClass = null;
        this.fieldVariable = new HashMap<String, String>();
        this.method = new HashMap<String, MethodInfo> ();
    }
    public void print(){
        System.out.println(className);
        System.out.println(parentClass);

        System.out.println("Field");
        System.out.println(this.fieldVariable);

        System.out.println("Methods");
        for(String name : method.keySet()){
            System.out.println(name);
            method.get(name).print();
        }
    }
}
