package visitor;


public class TempData {
    int index;
    String type;
    boolean isPointer;
    
    TempData(){
        
    }

    TempData(int i, String t, boolean flag){
        this.index = i;
        this.type = t;
        this.isPointer = flag;
    }
}
