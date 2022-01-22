//
// Generated by JTB 1.3.2
//

package visitor;
import syntaxtree.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class LivenessLCA<R,A> implements GJVisitor<R,A> {
   //
   // Auto class visitors--probably don't need to be overridden.
   //
   Integer statement = 0;

   int spillToBeReported = 0;
   int maxArgCallCount;
   int maxNumCallCount;
	HashMap<String,Integer> maxArgCall = new HashMap<String, Integer> ();
	HashMap<String,Integer> maxNumCall = new HashMap<String, Integer> ();
	HashMap<String,HashMap<Integer, RegisterAllocationDetails>> registerAllocation = new HashMap<String, HashMap<Integer, RegisterAllocationDetails>> ();
	HashMap<String,Integer> spillAllocation = new HashMap<String, Integer> ();

   HashMap<String,Integer> labelMap;
   HashMap<Integer,Set<Integer>> succesorBlocks = new HashMap<Integer,Set<Integer>>();
   HashMap<Integer,Set<Integer>> def = new HashMap <Integer,Set<Integer>> ();
   HashMap<Integer,Set<Integer>> use = new HashMap <Integer,Set<Integer>> ();
   HashMap<String,HashMap<Integer, Set<Integer>>> livein = new HashMap <String,HashMap<Integer, Set<Integer>>>();
   HashMap<String,HashMap<Integer, Set<Integer>>> liveout = new HashMap <String,HashMap<Integer, Set<Integer>>>();


   public class PairUseDef
   {
      Set<Integer> use;
      Set<Integer> def;
      PairUseDef(Set<Integer> u, Set<Integer> d){
         this.use = u;
         this.def = d;
      }
      PairUseDef(){

      }
   }

   public R visit(NodeList n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeListOptional n, A argu) {
      if ( n.present() ) {
         R _ret=null;
         int _count=0;
         LinkedList<R> l = new LinkedList<R> ();
         for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            l.add(e.nextElement().accept(this,argu));
            _count++;
         }
         return (R)l;
      }
      else
         return null;
   }

   public R visit(NodeOptional n, A argu) {
      if ( n.present() )
         return n.node.accept(this,argu);
      else
         return null;
   }

   public R visit(NodeSequence n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeToken n, A argu) { return null; }

   //
   // User-generated visitor methods below
   //

   void LivenessAnalysisHelper(String methodName, Integer parameterCount,HashMap<Integer, RegisterAllocationDetails> regAlloc, Integer start, Integer end, boolean isMain){

      HashMap<Integer, Set<Integer>> hin=new HashMap<Integer, Set<Integer>>();
      HashMap<Integer, Set<Integer>> hout=new HashMap<Integer, Set<Integer>>();
      Integer node;
        for(node=start;node<=end;node++){
            hin.put(node,new HashSet<Integer>());
            hout.put(node,new HashSet<Integer>());
        }
        int flag=1;
        int ctin=1,cthout=0;
        while(ctin!=0 || cthout!=0 ){
        	   ctin=0;cthout=0;
            for(Integer nu=start;node<=end;nu++){
                
               cthout += hout.get(nu).size();
               ctin += hin.get(nu).size();
            	Set<Integer> temp=new HashSet<Integer> (hout.get(nu));
               temp.removeAll(def.get(nu));
               temp.addAll(use.get(nu));
               hin.put(nu,temp);
               Set<Integer> temp2=new HashSet<Integer> ();
               for(Integer i : succesorBlocks.get(nu))
                  if(i!=-1)
                     temp2.addAll(hin.get(i));
               hout.put(nu,temp2);
               ctin-=hin.get(nu).size();
               cthout-=hout.get(nu).size();
            }
         }
      livein.put(methodName,hin);
      liveout.put(methodName,hout); 
      
      HashMap<Integer,Integer> liverangestart=new HashMap<Integer,Integer>();
      HashMap<Integer,Integer> liverangeend=new HashMap<Integer,Integer>();
      for(int i=start;i<=end;i++){
    	  
    	  Set<Integer> st1=def.get(i);
    	  for(Integer j : st1){
  	  		if(!liverangestart.containsKey(j)){
  	  			liverangestart.put(j,i);
  	  			liverangeend.put(j,i);
  	  		}
  	  		else
  	  			if(liverangeend.get(j)<i){
  	  				liverangeend.put(j, i);
  	  		}
    	  
    	  	for(Integer k : hin.get(i)){
    	  			if(!liverangeend.containsKey(k)){
    	  					liverangeend.put(k,i);
    	  			}
    	  			else
    	  				if(liverangeend.get(k)<i)
    	  					liverangeend.put(k,i);
    	  	
    	  	}
    	  } 	
    
      }
    LCA.regS_Allocated = 0;
    LCA.regT_Allocated = 0; 
    LCA.spilled_Allocated = 0;
    for(int i=0;i<parameterCount;i++){
    	if(i<3){
    		RegisterAllocationDetails temp=new RegisterAllocationDetails();
    		temp.register="s"+LCA.regS_Allocated;
    		temp.isSpilled=1;
    		regAlloc.put(i, temp);
    		LCA.regS_Allocated++;
    	}
    	else{
    		RegisterAllocationDetails temp2=new RegisterAllocationDetails();
    		temp2.spillNumber= LCA.spilled_Allocated++;
    		temp2.isSpilled=-1;
    		regAlloc.put(i,temp2);
    		
    	}
    	liverangestart.remove(i);liverangeend.remove(i);
       
    }

    if(!isMain){
       LCA.spilled_Allocated += 18;
    }
    Set<Integer> alltempnumbers=liverangestart.keySet();
    List<Liveness> liverange=new ArrayList<Liveness>();
    int m=0;
    for(Integer l : alltempnumbers){
    	Liveness b=new Liveness();
    	b.start=liverangestart.get(l);
    	b.end=liverangeend.get(l);
    	b.temp=l;
    	liverange.add(b);
    	
    	
    }
    
    int siz=alltempnumbers.size();
    Collections.sort(liverange);
    spillToBeReported+= LCA.linearScan(liverange,siz,regAlloc);  
    registerAllocation.put(methodName, regAlloc);
    spillAllocation.put(methodName, LCA.spilled_Allocated);

}

   /**
    * f0 -> "MAIN"
    * f1 -> StmtList()
    * f2 -> "END"
    * f3 -> ( Procedure() )*
    * f4 -> <EOF>
    */
   public R visit(Goal n, A argu) {
      R _ret=null;
      maxArgCallCount = 0;
      maxNumCallCount = 0;
      statement = 0;
      Integer statementStart = 1;
      String methodName = "MAIN";
      Integer parameterCount = 0;
      labelMap = (HashMap<String, Integer>)argu;
      HashMap<Integer, RegisterAllocationDetails> regAlloc = new HashMap<Integer, RegisterAllocationDetails>();

      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      maxArgCall.put(methodName, maxArgCallCount);
      maxNumCall.put(methodName, maxNumCallCount);

      Integer statementEnd = statement;
      Set<Integer> t = succesorBlocks.get(statement);
      t.remove(statement+1);
      t.add(-1);
      LivenessAnalysisHelper(methodName, parameterCount, regAlloc, statementStart, statementEnd, true);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);

      Analysis analysis = new Analysis();
      analysis.spillToBeReported = spillToBeReported;
      analysis.maxArgCall = maxArgCall;
      analysis.maxNumCall = maxNumCall;
      analysis.registerAllocation = registerAllocation;
      analysis.spillAllocation = spillAllocation;
      return (R)analysis;
   }

   /**
    * f0 -> ( ( Label() )? Stmt() )*
    */
   public R visit(StmtList n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Label()
    * f1 -> "["
    * f2 -> IntegerLiteral()
    * f3 -> "]"
    * f4 -> StmtExp()
    */
   public R visit(Procedure n, A argu) {
      R _ret=null;
      maxArgCallCount = 0;
      maxNumCallCount = 0;
      HashMap<Integer, RegisterAllocationDetails> regAlloc = new HashMap<Integer, RegisterAllocationDetails>();
      statement++;
      Integer statementStart = statement;
      Set<Integer> nextBlock = new HashSet<Integer>();
      nextBlock.add(statement+1);
      succesorBlocks.put(statement, nextBlock);

      Set<Integer> useAtCurrentStatement = new HashSet<Integer>();
      Set<Integer> defAtCurrentStatement = new HashSet<Integer>();
      use.put(statement, useAtCurrentStatement);
      def.put(statement, defAtCurrentStatement);

      String methodName = (String)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      String IntStr = (String)n.f2.accept(this, argu);
      Integer parameterCount = (Integer.parseInt(IntStr));
      for(Integer i=0; i<parameterCount;i++){ 
         defAtCurrentStatement.add(i);
      }
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      maxArgCall.put(methodName, maxArgCallCount);
      maxNumCall.put(methodName, maxNumCallCount);
      Integer statementEnd = statement;
      LivenessAnalysisHelper(methodName, parameterCount, regAlloc, statementStart, statementEnd, false);
      return _ret;
   }

   /**
    * f0 -> NoOpStmt()
    *       | ErrorStmt()
    *       | CJumpStmt()
    *       | JumpStmt()
    *       | HStoreStmt()
    *       | HLoadStmt()
    *       | MoveStmt()
    *       | PrintStmt()
    */
   public R visit(Stmt n, A argu) {
      R _ret=null;
      statement++;
      Set<Integer> useAtCurrentStatement = new HashSet<Integer>();
      Set<Integer> defAtCurrentStatement = new HashSet<Integer>();
      use.put(statement, useAtCurrentStatement);
      def.put(statement, defAtCurrentStatement);
      PairUseDef nodeInfo = new PairUseDef(useAtCurrentStatement, defAtCurrentStatement);
      argu = (A)nodeInfo;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "NOOP"
    */
   public R visit(NoOpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      return _ret;
   }

   /**
    * f0 -> "ERROR"
    */
   public R visit(ErrorStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      return _ret;
   }

   /**
    * f0 -> "CJUMP"
    * f1 -> Temp()
    * f2 -> Label()
    */
   public R visit(CJumpStmt n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      n.f0.accept(this, argu);
      String tempIndex = (String)n.f1.accept(this, argu);
      String label = (String)n.f2.accept(this, argu);
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      nextNode.add(labelMap.get(label));
      succesorBlocks.put(statement, nextNode);
      nodeInfo.use.add(Integer.parseInt(tempIndex));
      return _ret;
   }

   /**
    * f0 -> "JUMP"
    * f1 -> Label()
    */
   public R visit(JumpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String label = (String)n.f1.accept(this, argu);
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(labelMap.get(label));
      succesorBlocks.put(statement, nextNode);
      return _ret;
   }

   /**
    * f0 -> "HSTORE"
    * f1 -> Temp()
    * f2 -> IntegerLiteral()
    * f3 -> Temp()
    */
   public R visit(HStoreStmt n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      n.f0.accept(this, argu);
      String tempIndex1 = (String)n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      String tempIndex2 = (String)n.f3.accept(this, argu);
      nodeInfo.use.add(Integer.parseInt(tempIndex1));
      nodeInfo.use.add(Integer.parseInt(tempIndex2));
      return _ret;
   }

   /**
    * f0 -> "HLOAD"
    * f1 -> Temp()
    * f2 -> Temp()
    * f3 -> IntegerLiteral()
    */
   public R visit(HLoadStmt n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      
      n.f0.accept(this, argu);
      String defIndex = (String)n.f1.accept(this, argu);
      String useIndex = (String)n.f2.accept(this, argu);
      nodeInfo.def.add(Integer.parseInt(defIndex));
      nodeInfo.use.add(Integer.parseInt(useIndex));
      n.f3.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "MOVE"
    * f1 -> Temp()
    * f2 -> Exp()
    */
   public R visit(MoveStmt n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      n.f0.accept(this, argu);
      String defIndex = (String)n.f1.accept(this, argu);
      
      nodeInfo.def.add(Integer.parseInt(defIndex));
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "PRINT"
    * f1 -> SimpleExp()
    */
   public R visit(PrintStmt n, A argu) {
      R _ret=null;
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(statement+1);
      succesorBlocks.put(statement, nextNode);
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Call()
    *       | HAllocate()
    *       | BinOp()
    *       | SimpleExp()
    */
   public R visit(Exp n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "BEGIN"
    * f1 -> StmtList()
    * f2 -> "RETURN"
    * f3 -> SimpleExp()
    * f4 -> "END"
    */
   public R visit(StmtExp n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      statement++;
      Set<Integer> nextNode = new HashSet<Integer>();
      nextNode.add(-1);
      succesorBlocks.put(statement, nextNode);

      Set<Integer> useAtCurrentStatement = new HashSet<Integer>();
      Set<Integer> defAtCurrentStatement = new HashSet<Integer>();
      use.put(statement, useAtCurrentStatement);
      def.put(statement, defAtCurrentStatement);
      PairUseDef nodeInfo = new PairUseDef(useAtCurrentStatement, defAtCurrentStatement);
      argu = (A)nodeInfo;
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "CALL"
    * f1 -> SimpleExp()
    * f2 -> "("
    * f3 -> ( Temp() )*
    * f4 -> ")"
    */
   public R visit(Call n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      LinkedList<String> parameterList= (LinkedList<String>)n.f3.accept(this, argu);
      maxNumCallCount++;
      if(parameterList != null){
         if(parameterList.size() > maxArgCallCount){
            maxArgCallCount = parameterList.size();
         }

         Iterator<String> itr = parameterList.iterator();
         while(itr.hasNext()){
            nodeInfo.use.add(Integer.parseInt((String)itr.next()));
         }
      }
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "HALLOCATE"
    * f1 -> SimpleExp()
    */
   public R visit(HAllocate n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Operator()
    * f1 -> Temp()
    * f2 -> SimpleExp()
    */
   public R visit(BinOp n, A argu) {
      R _ret=null;
      PairUseDef nodeInfo = (PairUseDef)argu;
      n.f0.accept(this, argu);
      String useIndex = (String)n.f1.accept(this, argu);
      nodeInfo.use.add(Integer.parseInt(useIndex));
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "LE"
    *       | "NE"
    *       | "PLUS"
    *       | "MINUS"
    *       | "TIMES"
    *       | "DIV"
    */
   public R visit(Operator n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Temp()
    *       | IntegerLiteral()
    *       | Label()
    */
   public R visit(SimpleExp n, A argu) {
      R _ret=null;
      R val = n.f0.accept(this, argu);
      if(n.f0.which == 0){
         PairUseDef nodeInfo = (PairUseDef)argu;
         nodeInfo.use.add(Integer.parseInt((String)val));
         return val;
      }
      if(n.f0.which == 2){
         return val;
      }
      return _ret;
   }

   /**
    * f0 -> "TEMP"
    * f1 -> IntegerLiteral()
    */
   public R visit(Temp n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return n.f1.accept(this, argu);
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    */
   public R visit(IntegerLiteral n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return (R)n.f0.toString();
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public R visit(Label n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return (R)n.f0.toString();
   }

}
