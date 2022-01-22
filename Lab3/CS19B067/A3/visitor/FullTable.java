package visitor;
import java.util.*;

public class FullTable {
    public HashMap<String, SymbolTable> table;

    public FullTable(){
        this.table = new HashMap<String, SymbolTable> ();
    }
}
