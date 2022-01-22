package visitor;
import java.util.*;

public class OffsetTable {
    public HashMap<String, Integer> variableOffset;
    public HashMap<String, Integer> methodOffset;

    public OffsetTable(){
        this.variableOffset = new HashMap<String, Integer> ();
        this.methodOffset = new HashMap<String, Integer> ();
    }
}
