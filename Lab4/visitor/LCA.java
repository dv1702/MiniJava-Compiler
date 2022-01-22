package visitor;
import java.util.*;

public class LCA {
    static int regS_Allocated   = 0;
    static int regT_Allocated   = 0;
    static int spilled_Allocated = 0;

    static void expireOldIntervals(List<Liveness> liverange,int i,List<Liveness> active,HashMap<Integer, RegisterAllocationDetails> regAlloc,List<String> registerpool){
        int j;
        for(j=0;j<active.size();j++){
            if(active.get(j).end>=liverange.get(i).start)
                return;
            registerpool.add(regAlloc.get(active.get(j).temp).register);
            active.remove(j);
            j--;
        }
    }

    static void spillAtInterval(List<Liveness> liverange,int i,List<Liveness> active,HashMap<Integer, RegisterAllocationDetails> regAlloc,List<String> registerpool){
        int j;
        
        Liveness spill=active.get(active.size()-1);
        if( spill.end>liverange.get(i).end){
                RegisterAllocationDetails temp=new RegisterAllocationDetails ();
                temp.spillNumber=spilled_Allocated++;
                temp.isSpilled=-1;
                regAlloc.put(liverange.get(i).temp,regAlloc.get(spill.temp));
                regAlloc.put(spill.temp, temp);
                active.remove(spill);
                for(j=0;j<active.size();j++){
                    if(active.get(j).end>liverange.get(i).end)
                        break;
                        
                }
                active.add(j,liverange.get(i));
        }
        else{
            RegisterAllocationDetails temp=new RegisterAllocationDetails ();
                temp.spillNumber=spilled_Allocated++;
                temp.isSpilled=-1;
                regAlloc.put(liverange.get(i).temp,temp);
                
        }
    }
    
    public static int linearScan(List<Liveness> liverange,int size, HashMap<Integer, RegisterAllocationDetails> regAlloc){
        Integer numspilled=0;
        List<String> registerpool=new ArrayList<String> ();
        int i;
        int j;
        int Rnum=10+8-regS_Allocated;
    
        for(i=regS_Allocated;i<8;i++)
            registerpool.add("s"+i);
        for(i=0;i<10;i++)
            registerpool.add("t"+i);
        List<Liveness> active=new ArrayList<Liveness> ();
        for(i=0;i<size;i++){
            expireOldIntervals(liverange,i,active,regAlloc,registerpool);
            if(active.size()== Rnum ){
                numspilled++;
                spillAtInterval(liverange,i,active,regAlloc,registerpool);
            }
            else{
                RegisterAllocationDetails temp=new RegisterAllocationDetails();
                temp.register=registerpool.get(0);
                registerpool.remove(0);
                temp.isSpilled=1;
                regAlloc.put(liverange.get(i).temp, temp);
            
                for(j=0;j<active.size();j++){
                    if(active.get(j).end>liverange.get(i).end)
                        break;
                    
                }
                active.add(j,liverange.get(i));
            }
        }
    
        return numspilled;	 
    }

    
}
