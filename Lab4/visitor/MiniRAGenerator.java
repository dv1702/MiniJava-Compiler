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
public class MiniRAGenerator<R,A> implements GJVisitor<R,A> {
   //
   // Auto class visitors--probably don't need to be overridden.
   //
   int statement;
   String currentMethodName;
   Analysis analysis;

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
         LinkedList<R> l = new LinkedList<R>();
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
      if ( n.present() ){
         String label = (String)n.node.accept(this,argu);
         System.out.println(label);
         return (R)label;
      }
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

   /**
    * f0 -> "MAIN"
    * f1 -> StmtList()
    * f2 -> "END"
    * f3 -> ( Procedure() )*
    * f4 -> <EOF>
    */
   public R visit(Goal n, A argu) {
      R _ret=null;
      statement = 0;
      analysis = (Analysis)argu;
      currentMethodName = "MAIN";
      System.out.println("MAIN [0] ["+ (analysis.spillAllocation.get(currentMethodName)+ analysis.maxArgCall.get(currentMethodName) + 2) +"] [" + analysis.maxArgCall.get(currentMethodName) + "]");
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      System.out.println("END");

      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
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
      statement++;
      currentMethodName = (String)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      Integer parameterCount = Integer.parseInt((String)n.f2.accept(this, argu));
      System.out.println(currentMethodName+" ["+ parameterCount +"] ["+ 
      (analysis.spillAllocation.get(currentMethodName)+ analysis.maxArgCall.get(currentMethodName) + 2) +
      "] [" + analysis.maxArgCall.get(currentMethodName) + "]");

      int remaining = 0;
      if(parameterCount > 4){
         remaining = parameterCount - 4;
      }

      for(int i=0;i<8;i++){
         System.out.println("ASTORE SPILLEDARG "+ (i+remaining) + " s"+i);
      }

      for(int i=0;i<10;i++){
         System.out.println("ASTORE SPILLEDARG "+ (i+remaining+8)+ " t"+i);
      }

      for(int i=0;i<4 && i<parameterCount; i++){
         System.out.println("MOVE s"+i+" a"+i);
      }
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);

      for(int i=0;i<8;i++){
         System.out.println("ALOAD s"+i+" SPILLEDARG "+(i+remaining));
      }
      for(int i=0;i<10;i++){
         System.out.println("ALOAD t"+i+" SPILLEDARG "+(i+remaining+8));
      }
      System.out.println("END");
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
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "NOOP"
    */
   public R visit(NoOpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      System.out.println("NOOP");
      return _ret;
   }

   /**
    * f0 -> "ERROR"
    */
   public R visit(ErrorStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      System.out.println("ERROR");
      return _ret;
   }

   /**
    * f0 -> "CJUMP"
    * f1 -> Temp()
    * f2 -> Label()
    */
   public R visit(CJumpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String tempIndex = (String)n.f1.accept(this, argu);
      String label = (String)n.f2.accept(this, argu);
      int [] spill = {0};
      int [] spNum = {-1};
      System.out.println("CJUMP "+ getregister(Integer.parseInt(tempIndex), 1, spill, spNum)+" "+label);
      return _ret;
   }

   String getregister(Integer t,int flag,int[] spill,int[] spnum){
	   RegisterAllocationDetails b=analysis.registerAllocation.get(currentMethodName).get(t);
	   if(b.isSpilled==1)
		   return b.register;
	   spill[0]=1;
	   spnum[0]=b.spillNumber;
	   if(flag!=-1)
		   System.out.println("ALOAD v"+flag+" SPILLEDARG "+b.spillNumber);
	   return "v"+flag;
	   
}

   /**
    * f0 -> "JUMP"
    * f1 -> Label()
    */
   public R visit(JumpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String label = (String)n.f1.accept(this, argu);
      System.out.println("JUMP "+label);
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
      n.f0.accept(this, argu);
      String IntStr = (String)n.f1.accept(this, argu);
      Integer tempIndex1 = Integer.parseInt(IntStr);
      String literal = (String)n.f2.accept(this, argu);
      IntStr =(String)n.f3.accept(this, argu);
      Integer tempIndex2 = Integer.parseInt(IntStr);
      int[] spill1 = {0}, spill2 = {0};
      int[] spNum1 = {-1}, spNum2 ={-1};
      System.out.println("HSTORE "+getregister(tempIndex1, 0, spill1, spNum1)+" "+literal+" "+getregister(tempIndex2, 1, spill2, spNum2));
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
      n.f0.accept(this, argu);
      String IntStr= (String)n.f1.accept(this, argu);
      Integer tempIndex1 = Integer.parseInt(IntStr);
      IntStr = (String)n.f2.accept(this, argu);
      Integer tempIndex2 = Integer.parseInt(IntStr);
      String literal = (String)n.f3.accept(this, argu);
      int[] spill1 = {0}, spill2 = {0};
      int[] spNum1 = {-1}, spNum2 ={-1};

      String r1 = getregister(tempIndex1, 0, spill1, spNum1);
      String r2 = getregister(tempIndex2, 1, spill2, spNum2);

      System.out.println("HLOAD "+r1+" "+r2+" "+literal);
      if(spill1[0]==1){
         System.out.println("ASTORE SPILLEDARG "+spNum1[0]+" "+r1);
      }
      return _ret;
   }

   /**
    * f0 -> "MOVE"
    * f1 -> Temp()
    * f2 -> Exp()
    */
   public R visit(MoveStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String IntStr = (String)n.f1.accept(this, argu);
      Integer tempIndex = Integer.parseInt(IntStr);
      argu = (A)tempIndex;
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "PRINT"
    * f1 -> SimpleExp()
    */
   public R visit(PrintStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String print = (String)n.f1.accept(this, argu);
      System.out.println("PRINT "+print);
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
      _ret=n.f0.accept(this, argu);
      if(n.f0.which==3){
    	  String b=(String)_ret;
    	  int[] spill={0},spnum={-1};
    	  String c=getregister((Integer)argu,-1,spill,spnum);
    	  if(spill[0]==1)
    		  System.out.println("ASTORE SPILLEDARG "+spnum[0]+" "+b);
    	  
    	  else
    		  System.out.println("MOVE "+c+" "+b);
      }
      if(n.f0.which==1){
    	  String b=(String)_ret;
    	  int[] spill={0},spnum={-1};
    	  String c=getregister((Integer)argu,0,spill,spnum);
    	  System.out.println("MOVE "+c+" HALLOCATE "+b);
    	  if(spill[0]==1)
    		  System.out.println("ASTORE SPILLEDARG "+spnum[0]+ " "+c);
      }
      if(n.f0.which==0){
    	  
    	  int[] spill={0},spnum={-1};
    	  String c=getregister((Integer)argu,-1,spill,spnum);
    	  if(spill[0]==1)
    		  System.out.println("ASTORE SPILLEDARG "+spnum[0]+" v0");
    	  else
    		  System.out.println("MOVE "+c+" v0");
    	  
      }
    	
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
      String returnExp = (String)n.f3.accept(this, argu);
      System.out.println("MOVE v0 "+returnExp);
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
      n.f0.accept(this, argu);
      String s=(String)n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      LinkedList<R> l=(LinkedList)n.f3.accept(this, argu);
      if(l != null){
      Iterator<R> iter=l.iterator();
      int[] spill={0},spnum={-1};
      String c;
      int ct=0;
      while(iter.hasNext()){
    	  
    	  spill[0]=0;spnum[0]=-1;
    	  c=getregister(Integer.parseInt((String)iter.next()),0,spill,spnum);
    	  if(ct<=3){
    		 
    			  System.out.println("MOVE a"+ct+" "+c);
    		  }
    	  else
    	  {
    		  System.out.println("PASSARG "+(ct-3)+" "+c);
    		  
    	  }
    	  ct++;
    	  
      }
   }
      System.out.println("CALL "+s);
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
      return n.f1.accept(this, argu);
   }

   /**
    * f0 -> Operator()
    * f1 -> Temp()
    * f2 -> SimpleExp()
    */
   public R visit(BinOp n, A argu) {
      R _ret=null;
      String op=(String)n.f0.accept(this, argu);
      String temp=(String)n.f1.accept(this, argu);
      
      String s=(String)n.f2.accept(this, argu);
      int[] spill={0},spnum={-1};
      String c=getregister(Integer.parseInt(temp),0,spill,spnum);
      spill[0]=0;spnum[0]=-1;
      String d=getregister((Integer)argu,-1,spill,spnum);
      if(spill[0]==1){
    	  System.out.println("MOVE v0 "+op+" "+c+" "+s);
        System.out.println("ASTORE SPILLEDARG "+spnum[0]+" v0");
      }
      else{
    	  System.out.println("MOVE "+d+" "+op+" "+c+" "+s);
      }
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
      String str = "";
      n.f0.accept(this, argu);
      switch(n.f0.which){
         case 0:str=" LE ";break;
         case 1:str=" NE ";break;
         case 2:str=" PLUS ";break;
         case 3:str=" MINUS ";break;
         case 4:str=" TIMES ";break;
         case 5:str=" DIV ";break;
         }
      return (R)str;
   }

   /**
    * f0 -> Temp()
    *       | IntegerLiteral()
    *       | Label()
    */
   public R visit(SimpleExp n, A argu) {
      R _ret=null;
      R val = n.f0.accept(this, argu);
      if(n.f0.which==0){
         int[] spill = {0};
         int[] spNum = {-1};
         return (R)getregister(Integer.parseInt((String)val), 1, spill, spNum);
      }
      else if(n.f0.which==1){
         System.out.println("MOVE v1 " + ((String)val));
         return (R)"v1";
      }
      return val;
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
