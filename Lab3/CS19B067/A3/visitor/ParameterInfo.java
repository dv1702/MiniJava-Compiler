package visitor;

public class ParameterInfo{
    public String identifier;
    public String type;
    public ParameterInfo(String id, String typ){
        this.identifier = id;
        this.type = typ;
    }
    public void print(){
        System.out.println(this.identifier + " " + this.type);
    }
}