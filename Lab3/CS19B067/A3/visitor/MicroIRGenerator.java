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
public class MicroIRGenerator<R,A> implements GJVisitor<R,A> {
   //
   // Auto class visitors--probably don't need to be overridden.
   //
   int newVariableIndex;
   int newLabelIndex;
   String CLASSNAME;
   HashMap<String, SymbolTable> table;
   HashMap<String, TempData> localVariables;
   List<TempData> params;

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
         for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this,argu);
            _count++;
         }
         return _ret;
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

   /**
    * f0 -> MainClass()
    * f1 -> ( TypeDeclaration() )*
    * f2 -> <EOF>
    *
    * f0 -> mainClass
    * f1 -> classes
    * 
    * Output : mainClass.code || classes.code
    */


   public R visit(Goal n, A argu) {
      R _ret=null;
      table = (HashMap<String, SymbolTable>)argu;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "{"
    * f3 -> "public"
    * f4 -> "static"
    * f5 -> "void"
    * f6 -> "main"
    * f7 -> "("
    * f8 -> "String"
    * f9 -> "["
    * f10 -> "]"
    * f11 -> Identifier()
    * f12 -> ")"
    * f13 -> "{"
    * f14 -> PrintStatement()
    * f15 -> "}"
    * f16 -> "}"


    ** f14 -> "Main \n" || printStatement.code || "END\n"

    * return printStatement
    */
   public R visit(MainClass n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String className = (String)n.f1.accept(this, argu);
      CLASSNAME = className;
      SymbolTable classTable = table.get(className);
      argu = (A)table.get(className);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      System.out.println("MAIN");
      newVariableIndex = 1;
      newLabelIndex = 1;
      argu = (A)classTable.method.get("main");
      n.f7.accept(this, argu);
      n.f8.accept(this, argu);
      n.f9.accept(this, argu);
      n.f10.accept(this, argu);
      n.f11.accept(this, argu);
      n.f12.accept(this, argu);
      n.f13.accept(this, argu);
      n.f14.accept(this, argu);
      n.f15.accept(this, argu);
      n.f16.accept(this, argu);
      System.out.println("END");
      return _ret;
   }

   /**
    * f0 -> ClassDeclaration()
    *       | ClassExtendsDeclaration()

    * f0 -> classDeclaration

    * return classDeclaration
    */
   public R visit(TypeDeclaration n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "{"
    * f3 -> ( VarDeclaration() )*
    * f4 -> ( MethodDeclaration() )*
    * f5 -> "}"

    * f4 -> methodDeclaration

    *  return f4
    */
   public R visit(ClassDeclaration n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String className = (String)n.f1.accept(this, argu);
      CLASSNAME = className;
      argu  = (A)table.get(className);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "extends"
    * f3 -> Identifier()
    * f4 -> "{"
    * f5 -> ( VarDeclaration() )*
    * f6 -> ( MethodDeclaration() )*
    * f7 -> "}"

    * return f6
    */
   public R visit(ClassExtendsDeclaration n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String className = (String)n.f1.accept(this, argu);
      CLASSNAME = className;
      argu = (A)table.get(className);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      n.f7.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Type()
    * f1 -> Identifier()
    * f2 -> ";"

    * mapping 
    * variable.code = ""
    * return variable
    */
   public R visit(VarDeclaration n, A argu) {
      R _ret=null;
      String type = (String)n.f0.accept(this, argu);
      TempData temp = (TempData)n.f1.accept(this, argu);
      String id = temp.type;
      n.f2.accept(this, argu);
      if(argu instanceof MethodInfo){
        boolean isPointer = true;
        if(type == "int" || type == "boolean"){
            isPointer = false;
        }
        localVariables.put(id, new TempData(newVariableIndex++, type, isPointer)) ;    
      }
      return _ret;
   }

   /**
    * f0 -> AccessType()
    * f1 -> Type()
    * f2 -> Identifier()
    * f3 -> "("
    * f4 -> ( FormalParameterList() )?
    * f5 -> ")"
    * f6 -> "{"
    * f7 -> ( VarDeclaration() )*
    * f8 -> ( Statement() )*
    * f9 -> "return"
    * f10 -> Expression()
    * f11 -> ";"
    * f12 -> "}"

    * label = className || "_" || methodName || " [" || (args.length + 1) || "]\n" || "BEGIN \n"
              || statement.code || "RETURN \n" || expression.code || "END\n"  
    */
   public R visit(MethodDeclaration n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      SymbolTable classTable = (SymbolTable)(argu);
      TempData temp = (TempData)n.f2.accept(this, argu);
      String methodName = temp.type;
      MethodInfo method = classTable.method.get(methodName);
      List<ParameterInfo> params = method.signature;
      argu = (A)method;

      System.out.println(classTable.className + "_" + methodName + " ["  + (params.size() + 1) + "]");
      System.out.println("BEGIN");
      newVariableIndex = 1;
      localVariables = new HashMap<String, TempData> ();
      for(ParameterInfo p : params){
            boolean isPointer = true;
            if(p.type == "int" || p.type == "boolean"){
                isPointer = false;
            }
            localVariables.put(p.identifier, new TempData(newVariableIndex++, p.type, isPointer));
      }
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      n.f7.accept(this, argu);
      n.f8.accept(this, argu);
      n.f9.accept(this, argu);
      TempData tempReturn = (TempData)n.f10.accept(this, argu);
      tempReturn = CheckAndUpdate(tempReturn);
      System.out.print("RETURN ");
      System.out.println("TEMP " + tempReturn.index);
      System.out.println("END");
      n.f11.accept(this, argu);
      n.f12.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> FormalParameter()
    * f1 -> ( FormalParameterRest() )*
    */
   public R visit(FormalParameterList n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Type()
    * f1 -> Identifier()
    */
   public R visit(FormalParameter n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ","
    * f1 -> FormalParameter()
    */
   public R visit(FormalParameterRest n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ArrayType()
    *       | BooleanType()
    *       | IntegerType()
    *       | Identifier()
    */
   public R visit(Type n, A argu) {
      R _ret=null;
      String type = (String)n.f0.accept(this, argu);
      return (R)type;
   }

   /**
    * f0 -> PublicType()
    *       | PrivateType()
    *       | ProtectedType()
    */
   public R visit(AccessType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "int"
    * f1 -> "["
    * f2 -> "]"
    */
   public R visit(ArrayType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return (R)"int[]";
   }

   /**
    * f0 -> "boolean"
    */
   public R visit(BooleanType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return (R)"boolean";
   }

   /**
    * f0 -> "int"
    */
   public R visit(IntegerType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return (R)"int";
   }

   /**
    * f0 -> "public"
    */
   public R visit(PublicType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "private"
    */
   public R visit(PrivateType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "protected"
    */
   public R visit(ProtectedType n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Block()
    *       | AssignmentStatement()
    *       | ArrayAssignmentStatement()
    *       | IfStatement()
    *       | WhileStatement()
    *       | PrintStatement()
    */
   public R visit(Statement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> ( Statement() )*
    * f2 -> "}"
    */
   public R visit(Block n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Identifier()
    * f1 -> "="
    * f2 -> Expression()
    * f3 -> ";"
    */
   public R visit(AssignmentStatement n, A argu) {
      R _ret=null;
      TempData lhs = (TempData)n.f0.accept(this, argu);
      String id = lhs.type;
      if(localVariables.containsKey(id)){
          lhs.index = localVariables.get(id).index;
          n.f1.accept(this, argu);
          TempData rhs = (TempData)n.f2.accept(this, argu);
          rhs  =  CheckAndUpdate(rhs);
          System.out.println("MOVE TEMP " + lhs.index + " TEMP " + rhs.index);
          n.f3.accept(this, argu);
      }
      else{
          n.f1.accept(this, argu);
          TempData rhs = (TempData)n.f2.accept(this, argu);
          rhs  =  CheckAndUpdate(rhs);
          System.out.println("HSTORE TEMP 0 " + table.get(CLASSNAME).variableOffset.get(id) + " TEMP " + rhs.index);
          n.f3.accept(this, argu);
      }

      
      return _ret;
   }

   /**
    * f0 -> Identifier()
    * f1 -> "["
    * f2 -> Expression()
    * f3 -> "]"
    * f4 -> "="
    * f5 -> Expression()
    * f6 -> ";"
    */
   public R visit(ArrayAssignmentStatement n, A argu) {
      R _ret=null;
      TempData base = (TempData)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      String id = base.type;
      int baseIndex = newVariableIndex++;
      if(localVariables.containsKey(id)){
        baseIndex = localVariables.get(id).index;
      }
      else{
        System.out.println("HLOAD TEMP " + (newVariableIndex++) + " TEMP 0 " + table.get(CLASSNAME).variableOffset.get(id));
        baseIndex = newVariableIndex-1;
      }
      TempData offset = (TempData)n.f2.accept(this, argu);
      offset = CheckAndUpdate(offset);
      int size = newVariableIndex++;
      int add = newVariableIndex++;
      int tempOffset = newVariableIndex++;
      System.out.println("MOVE TEMP " + size + " TIMES TEMP " + offset.index +  " 4");
      System.out.println("MOVE TEMP " + tempOffset + " PLUS TEMP " + size +  " 4");
      System.out.println("MOVE TEMP " + add + " PLUS TEMP "  + baseIndex + " TEMP " + tempOffset);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      TempData val = (TempData)n.f5.accept(this, argu);
      val = CheckAndUpdate(val);
      System.out.println("HSTORE TEMP " + add + " 0 TEMP " + val.index );
      n.f6.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> IfthenElseStatement()
    *       | IfthenStatement()
    */
   public R visit(IfStatement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "if"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    */
   public R visit(IfthenStatement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      TempData temp = (TempData)n.f2.accept(this, argu);
      if(temp.index == -1){
          temp = CheckAndUpdate(temp);
      }
      int i1 = newLabelIndex++;
      int i2 = newLabelIndex++;
      System.out.println("CJUMP TEMP " + temp.index + " L" + i2);
      System.out.println("JUMP L" + i1);
      n.f3.accept(this, argu);
      System.out.println("L" + i1);
      n.f4.accept(this, argu);
      System.out.println("L" + i2);
      System.out.println("NOOP");
      return _ret;
   }

   /**
    * f0 -> "if"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    * f5 -> "else"
    * f6 -> Statement()
    */
   public R visit(IfthenElseStatement n, A argu) {
      R _ret=null;
      int i1 = newLabelIndex++;
      int i2 = newLabelIndex++;
      int i3 = newLabelIndex++;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      TempData temp = (TempData)n.f2.accept(this, argu);
      if(temp.index == -1){
          temp = CheckAndUpdate(temp);
      }
      n.f3.accept(this, argu);
      System.out.println("CJUMP TEMP " + temp.index + " L" + i2);
      System.out.println("JUMP L" + i1);
      System.out.println("L" + i1);
      n.f4.accept(this, argu);
      System.out.println("JUMP L" + i3);
      n.f5.accept(this, argu);
      System.out.println("L" + i2);
      n.f6.accept(this, argu);
      System.out.println("L" + i3);
      System.out.println("NOOP");
      return _ret;
   }

   /**
    * f0 -> "while"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    */
   public R visit(WhileStatement n, A argu) {
      R _ret=null;
      int i1 = newLabelIndex++;
      int i2 = newLabelIndex++;
      int i3 = newLabelIndex++;
      System.out.println("L" + i1);
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      TempData temp = (TempData)n.f2.accept(this, argu);
      temp = CheckAndUpdate(temp);
      System.out.println("CJUMP TEMP " + temp.index + " L" + i3);
      System.out.println("JUMP " + "L" + i2);
      n.f3.accept(this, argu);
      System.out.println("L" + i2);
      n.f4.accept(this, argu);
      System.out.println("JUMP " + "L" + i1);
      System.out.println("L" + i3);
      System.out.println("NOOP");
      return _ret;
   }

   /**
    * f0 -> "System.out.println"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> ";"
    */
   public R visit(PrintStatement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      TempData temp = (TempData)n.f2.accept(this, argu);
      temp = CheckAndUpdate(temp);
      System.out.println("PRINT TEMP " + temp.index);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> OrExpression()
    *       | AndExpression()
    *       | CompareExpression()
    *       | neqExpression()
    *       | PlusExpression()
    *       | MinusExpression()
    *       | TimesExpression()
    *       | DivExpression()
    *       | ArrayLookup()
    *       | ArrayLength()
    *       | MessageSend()
    *       | TernaryExpression()
    *       | PrimaryExpression()
    */
   public R visit(Expression n, A argu) {
      R _ret=null;
      R temp = n.f0.accept(this, argu);
      return (R)temp;
   }

   public TempData CheckAndUpdate(TempData t){
       if(t.index == -1){
           if(localVariables.containsKey(t.type)){
               t = localVariables.get(t.type);
               return t;
           }
           else{
           {
               SymbolTable classTable = table.get(CLASSNAME);
               int offset = classTable.variableOffset.get(t.type);
               int dataPointer = newVariableIndex++;
               System.out.println("HLOAD TEMP " + dataPointer + " TEMP 0 " + offset);
               t.index = dataPointer;
               String id = t.type;
               while(!classTable.fieldVariable.containsKey(id)){
                   classTable = table.get(classTable.parentClass);
               }
               t.type = classTable.fieldVariable.get(id);
               t.isPointer = true;
               return t;
           }
       }
   }
   else return t;
}
   /**
    * f0 -> PrimaryExpression()
    * f1 -> "&&"
    * f2 -> PrimaryExpression()
    */
public R visit(AndExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      System.out.println("MOVE TEMP " + result.index + " TIMES TEMP " + first.index + " TEMP " + second.index);
      return (R)((TempData)result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "||"
    * f2 -> PrimaryExpression()
    */
   public R visit(OrExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      int sum = newLabelIndex++;
      int mul = newVariableIndex++;
      System.out.println("MOVE TEMP " + sum + " PLUS TEMP " + first.index + " TEMP " + second.index);
      System.out.println("MOVE TEMP " + mul + " TIMES TEMP " + first.index + " TEMP " + second.index);
      System.out.println("MOVE TEMP " + result.index + " MINUS TEMP "  + sum + " TEMP " + mul );
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "<="
    * f2 -> PrimaryExpression()
    */
   public R visit(CompareExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      System.out.println("MOVE TEMP " + result.index + " LE TEMP " + first.index + " TEMP " + second.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "!="
    * f2 -> PrimaryExpression()
    */
   public R visit(neqExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      first = CheckAndUpdate(first);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      System.out.println("MOVE TEMP " + result.index + " NE TEMP " + first.index + " TEMP " + second.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "+"
    * f2 -> PrimaryExpression()
    */
   public R visit(PlusExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      first = CheckAndUpdate(first);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("MOVE TEMP " + result.index + " PLUS TEMP " + first.index + " TEMP " + second.index);
      //System.out.println(result.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "-"
    * f2 -> PrimaryExpression()
    */
   public R visit(MinusExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("MOVE TEMP " + result.index + " MINUS TEMP " + first.index + " TEMP " + second.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "*"
    * f2 -> PrimaryExpression()
    */
   public R visit(TimesExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("MOVE TEMP " + result.index + " TIMES TEMP " + first.index + " TEMP " + second.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "/"
    * f2 -> PrimaryExpression()
    */
   public R visit(DivExpression n, A argu) {
      R _ret=null;
      TempData first = (TempData)n.f0.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f1.accept(this, argu);
      TempData second = (TempData)n.f2.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("MOVE TEMP " + result.index + " DIV TEMP " + first.index + " TEMP " + second.index);
      return (R)(result);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "["
    * f2 -> PrimaryExpression()
    * f3 -> "]"
    */
   public R visit(ArrayLookup n, A argu) {
      R _ret=null;
      TempData base = (TempData)n.f0.accept(this, argu);
      base = CheckAndUpdate(base);
      n.f1.accept(this, argu);
      TempData offSet = (TempData)n.f2.accept(this, argu);
      offSet = CheckAndUpdate(offSet);
      TempData result = new TempData(newVariableIndex++, "int", false);
      int offSetIndex = newVariableIndex++;
      int mul = newVariableIndex++;
      int tempOffset = newVariableIndex++;
      System.out.println("MOVE TEMP " + mul + " 4");
      System.out.println("MOVE TEMP " + offSetIndex + " TIMES TEMP " + offSet.index + " TEMP " + mul );
      System.out.println("MOVE TEMP " + tempOffset  + " PLUS TEMP " + offSetIndex + " 4");
      int baseIndex = newVariableIndex++;
      System.out.println("MOVE TEMP " + baseIndex + " PLUS TEMP " + base.index + " TEMP " + tempOffset);
      System.out.println("HLOAD TEMP " + result.index + " TEMP "  + baseIndex + " 0");
      n.f3.accept(this, argu);
      return (R)result;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "."
    * f2 -> "length"
    */
   public R visit(ArrayLength n, A argu) {
      R _ret=null;
      TempData temp = (TempData)n.f0.accept(this, argu);
      temp = CheckAndUpdate(temp);
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("HLOAD TEMP " + result.index + " TEMP " + temp.index + " 0");
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return (R)result;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "."
    * f2 -> Identifier()
    * f3 -> "("
    * f4 -> ( ExpressionList() )?
    * f5 -> ")"
    */
   public R visit(MessageSend n, A argu) {
      R _ret=null;
      TempData obj = (TempData)n.f0.accept(this, argu);
      obj = CheckAndUpdate(obj);
      n.f1.accept(this, argu);
      TempData temp= (TempData)n.f2.accept(this, argu);
      String methodName = temp.type;
      n.f3.accept(this, argu);
      params = new LinkedList<TempData>();
      n.f4.accept(this, argu);
      n.f5.accept(this, argu);
      MethodInfo method = table.get(obj.type).method.get(methodName);
      boolean isPointer = true;
      if(method.returnType == "int" || method.returnType == "boolean" ){
          isPointer = false;
      }
      int methodOffset = table.get(obj.type).methodOffset.get(methodName);
      int functiontablePointer = newVariableIndex++;
      int targetInstruction = newVariableIndex++;
      System.out.println("HLOAD TEMP " + functiontablePointer + " TEMP " + obj.index +  " 0");
      System.out.println("HLOAD TEMP " + targetInstruction + " TEMP " + functiontablePointer + " " + methodOffset);
      TempData result = new TempData(newVariableIndex++, method.returnType, isPointer);
      System.out.print("MOVE TEMP " + result.index +  " CALL TEMP " + targetInstruction  + " (");
      System.out.print(" TEMP " + obj.index);
      for(TempData local: params){
          System.out.print(" TEMP " + local.index);
      }
      System.out.println(" )");
      return (R)result;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "?"
    * f2 -> PrimaryExpression()
    * f3 -> ":"
    * f4 -> PrimaryExpression()
    */
   public R visit(TernaryExpression n, A argu) {
      R _ret=null;
      TempData condition = (TempData)n.f0.accept(this, argu);
      condition = CheckAndUpdate(condition);
      n.f1.accept(this, argu);
      TempData first = (TempData)n.f2.accept(this, argu);
      first = CheckAndUpdate(first);
      n.f3.accept(this, argu);
      TempData second = (TempData)n.f4.accept(this, argu);
      second = CheckAndUpdate(second);
      TempData result = new TempData(newVariableIndex++, first.type, first.isPointer);
      int l1 = newLabelIndex++;
      int l2 = newLabelIndex++;
      int l3 = newLabelIndex++;
      System.out.println("CJUMP TEMP " + condition.index + " L" + l2);
      System.out.println("JUMP L" + l1);
      System.out.println("L" + l1);
      System.out.println("MOVE TEMP " + result.index + " TEMP " + first.index);
      System.out.println("JUMP L" + l3);
      System.out.println("L" + l2);
      System.out.println("MOVE TEMP " + result.index + " TEMP " + second.index);
      System.out.println("L" + l3);
      System.out.println("NOOP");
      return (R)result;
   }

   /**
    * f0 -> Expression()
    * f1 -> ( ExpressionRest() )*
    */
   public R visit(ExpressionList n, A argu) {
      R _ret=null;
      TempData temp = (TempData)n.f0.accept(this, argu);
      temp = CheckAndUpdate(temp);
      params.add(temp);
      //System.out.println(temp.index);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ","
    * f1 -> Expression()
    */
   public R visit(ExpressionRest n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      TempData temp  = (TempData)n.f1.accept(this, argu);
      temp = CheckAndUpdate(temp);
      params.add(temp);
      return _ret;
   }

   /**
    * f0 -> IntegerLiteral()
    *       | TrueLiteral()
    *       | FalseLiteral()
    *       | Identifier()
    *       | ThisExpression()
    *       | ArrayAllocationExpression()
    *       | AllocationExpression()
    *       | NotExpression()
    *       | BracketExpression()
    */
   public R visit(PrimaryExpression n, A argu) {
      R _ret=null;
      R tempIndex = n.f0.accept(this, argu);
      return (R)(tempIndex);
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    */
   public R visit(IntegerLiteral n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String num = n.f0.toString();
      TempData result = new TempData(newVariableIndex++, "int", false);
      System.out.println("MOVE TEMP " + result.index + " " + num);
      return (R)(result);
   }

   /**
    * f0 -> "true"
    */
   public R visit(TrueLiteral n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f0.toString();
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      System.out.println("MOVE TEMP " + result.index + " " + 1);
      return (R)(result);
   }

   /**
    * f0 -> "false"
    */
   public R visit(FalseLiteral n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f0.toString();
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      System.out.println("MOVE TEMP " + result.index + " " + 0);
      return (R)(result);
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public R visit(Identifier n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String id = n.f0.toString();
      if(table.containsKey(id)){
          return (R)id;
      }
      else{
          TempData temp = new TempData(-1, id, false);
          return (R)temp;
      }
   }

   /**
    * f0 -> "this"
    */
   public R visit(ThisExpression n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return (R)(new TempData(0, CLASSNAME, true));
   }

   /**
    * f0 -> "new"
    * f1 -> "int"
    * f2 -> "["
    * f3 -> Expression()
    * f4 -> "]"
    */
   public R visit(ArrayAllocationExpression n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      TempData size = (TempData)n.f3.accept(this, argu);
      size = CheckAndUpdate(size);
      TempData result = new TempData(newVariableIndex++, "int[]", true);
      int array = newVariableIndex++;
      int total = newVariableIndex++;
      System.out.println("MOVE TEMP " + array + " PLUS TEMP " + size.index + " 1");    
      System.out.println("MOVE TEMP " + total + " TIMES TEMP " + array  + " 4");
      System.out.println("MOVE TEMP " + result.index + " HALLOCATE TEMP " + total);
      System.out.println("HSTORE TEMP " + result.index + " 0 " + " TEMP " + size.index);
      n.f4.accept(this, argu);
      return (R)result;
   }

   /**
    * f0 -> "new"
    * f1 -> Identifier()
    * f2 -> "("
    * f3 -> ")"
    */
   public R visit(AllocationExpression n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String id = (String)n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      HashMap<String, Integer> variables = table.get(id).variableOffset;
      HashMap<String, Integer> methods = table.get(id).methodOffset;
      SymbolTable classTable = table.get(id);
      int variableSizeIndex = newVariableIndex++;
      int methodSizeIndex = newVariableIndex++;
      int variablePointer = newVariableIndex++;
      int methodPointer = newVariableIndex++;
      System.out.println("MOVE TEMP " + variableSizeIndex + " " + (4*(variables.size()+1)));
      System.out.println("MOVE TEMP " + variablePointer  + " HALLOCATE TEMP " + variableSizeIndex);
      
      System.out.println("MOVE TEMP " + methodSizeIndex + " " + 4*methods.size());
      System.out.println("MOVE TEMP " + methodPointer  + " HALLOCATE TEMP " + methodSizeIndex);

      System.out.println("HSTORE TEMP " + variablePointer + " 0 TEMP " + methodPointer);

      for(String methodName: methods.keySet()){
          int methodOffset = methods.get(methodName);
          int target = newVariableIndex++;
          System.out.println("MOVE TEMP " + target + " " + id + "_" + methodName);
          System.out.println("HSTORE TEMP " + methodPointer + " " + methodOffset + " TEMP " + target);
      }

      TempData temp = new TempData(variablePointer, id, true);
      return (R)temp;
   }

   /**
    * f0 -> "!"
    * f1 -> Expression()
    */
   public R visit(NotExpression n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      TempData temp = (TempData)n.f1.accept(this, argu);
      temp = CheckAndUpdate(temp);
      TempData result = new TempData(newVariableIndex++, "boolean", false);
      int lol = newVariableIndex++;
      System.out.println("MOVE TEMP " + lol + " 1");
      int tempVal = newVariableIndex++;
      System.out.println("MOVE TEMP " + tempVal + " PLUS TEMP " + temp.index + " TEMP " + lol);
      System.out.println("MOVE TEMP " + result.index + " MINUS 2 TEMP " + tempVal);
      return (R)result;
   }

   /**
    * f0 -> "("
    * f1 -> Expression()
    * f2 -> ")"
    */
   public R visit(BracketExpression n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      TempData temp = (TempData)n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return (R)temp;
   }

   /**
    * f0 -> Identifier()
    * f1 -> ( IdentifierRest() )*
    */
   public R visit(IdentifierList n, A argu) {
      R _ret=null;
      int tempIndex = (int)n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ","
    * f1 -> Identifier()
    */
   public R visit(IdentifierRest n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

}
