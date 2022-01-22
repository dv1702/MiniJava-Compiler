package visitor;
import java.util.*;

public class SymbolTable {
    public String className;
    public String parentClass;
    public HashMap<String, String> fieldVariable;
    public HashMap<String, MethodInfo> method;
    public HashMap<String, Integer> variableOffset;
    public HashMap<String, Integer> methodOffset;

    public SymbolTable(){
        this.className = null;
        this.parentClass = null;
        this.fieldVariable = new HashMap<String, String>();
        this.method = new HashMap<String, MethodInfo> ();
        this.variableOffset = new HashMap<String, Integer> ();
        this.methodOffset = new HashMap<String, Integer> ();
    }
    public void print(){
        System.out.println(className);
        System.out.println(parentClass);

        System.out.println("Field");
        for(String name : variableOffset.keySet()){
            System.out.println(name + " : " + variableOffset.get(name));
        }

        System.out.println("Methods");
        for(String name : this.methodOffset.keySet()){
            System.out.println(name + " :: " + this.methodOffset.get(name));
        }
    }
}
