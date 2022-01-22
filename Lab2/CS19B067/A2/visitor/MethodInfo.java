package visitor;
import java.util.*;

public class MethodInfo {
    public String name;
    public String parentClass;
    public String accessType;
    public String returnType;
    public int totalCovered;
    public String callingMethod;
    public String callingMethodClass;

    public List<ParameterInfo> signature;
    public HashMap<String, String> localVariable;
    public MethodInfo(){
        this.name = null;
        this.totalCovered = 0;
        this.callingMethod = null;
        this.callingMethodClass = null;
        this.parentClass = null;
        this.accessType = null;
        this.returnType = null;
        this.signature = new ArrayList<ParameterInfo>();
        this.localVariable = new HashMap<String, String>();
    }
    public void print(){
        System.out.println(parentClass + " " + accessType + " " + returnType);
        for(ParameterInfo parameter : signature){
            parameter.print();
        }
        System.out.println(localVariable.toString());
    }
    public void addParameterInfo(String id, String typ){
        this.checkAndInsert(id, typ);
    }
    public void checkAndInsert(String id, String type){
        ParameterInfo tmp = new ParameterInfo(id, type);
        for(ParameterInfo current : this.signature){
            if(tmp == current){
                System.out.println("Type error");
                System.exit(0);
            }
        }
        this.signature.add(new ParameterInfo(id, type));
    }
    public boolean commonAncestor(String a, String b, HashMap<String, SymbolTable> table){
        String firstExpressionType = a;
        String secondExpressionType = b;
        if(!(table.containsKey(firstExpressionType)) || !(table.containsKey(secondExpressionType))){
            System.out.println("Type error");
            System.exit(0);
         }
         String secondStart = secondExpressionType;

         while(firstExpressionType != null){
            secondExpressionType = secondStart;
            while(secondExpressionType != null){
               if(firstExpressionType.equals(secondExpressionType)){
                  return true;
               }
               secondExpressionType = table.get(secondExpressionType).parentClass;
            }
            firstExpressionType = table.get(firstExpressionType).parentClass;
         }

         System.out.println("Type error");
         System.exit(0);
         return false;
        }

    public boolean equals(HashMap<String, SymbolTable> table, MethodInfo e){
        if(!this.accessType.equals(e.accessType)) return false;
        if(!this.returnType.equals(e.returnType)){
            return false;
        }
        int i;
        for(i=0;i<this.signature.size();i++){
            if(i >= e.signature.size()){
                return false;
            }
            if(!((this.signature.get(i)).type.equals(e.signature.get(i).type))){
                return false;
            }
        }
        if(i != e.signature.size()){
            return false;
        }
        return true;
    }

    public boolean equalParameters(List<String> e){
        int i;
        for(i=0;i<this.signature.size();i++){
            if(i >= e.size()){
                return false;
            }
            if(!((this.signature.get(i)).type.equals(e.get(i)))){
                return false;
            }
        }
        if(i != e.size()){
            return false;
        }
        return true;
    }
}
