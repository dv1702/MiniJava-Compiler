package visitor;
import java.util.*;

public class Analysis {
    int spillToBeReported;
	HashMap<String,Integer> maxArgCall;
	HashMap<String,Integer> maxNumCall;
	HashMap<String,HashMap<Integer, RegisterAllocationDetails> > registerAllocation;
	HashMap<String,Integer> spillAllocation;
}
