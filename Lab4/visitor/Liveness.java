package visitor;
import java.util.*;
import java.lang.Comparable;

public class Liveness implements Comparator<Liveness>, Comparable<Liveness>{
    int start;
    int end;
    int temp;
    public int compare(Liveness l1, Liveness l2){
        if(l1.start == l2.start){
            if(l1.end == l2.end) return 0;
            else if(l1.end < l2.end) return -1;
            else return 1;
        }
        else if(l1.start < l2.start) return -1;
        else return 1;
    }
    public int compareTo(Liveness l){
        if(this.start == l.start){
            if(this.end == l.end) return 0;
            else if(this.end < l.end) return -1;
            else return 1;
        }
        else if(this.start < l.start) return -1;
        else return 1;
    }
}
