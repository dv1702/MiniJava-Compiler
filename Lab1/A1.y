%{
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char prg[100000];
bool isParsed = true;

typedef struct Node{
    char* text;
    struct Node* next;
} Node; 

typedef struct List{
    Node* head;
    Node* tail;
} List;

void MakeNull(List *l){
    l = (List*)malloc(sizeof(List));
    l->head = (Node*)malloc(sizeof(Node));
    l->tail = l->head;
    l->head->next = NULL;
}

void Insert(List *l, char* val)
{
    l->tail->next = (Node*)malloc(sizeof(Node));
    l->tail = l->tail->next;
    l->tail->text = val;
}

List *Concatenate(List *l1, List *l2)
{
    l2->head = l2->head->next;
    l1->tail->next = l2->head;
    l1->tail = l2->tail;
    return l1;
}

void PrintList(List *l1){
    Node* tmp = l1->head;
    while(tmp->next){
        puts(tmp->next->text);
        tmp = tmp->next;
    }
}

void Free(List *l){
    Node* tmp = l->head;
    while(tmp->next){
        Node* tmpLol = tmp->next;
        free(tmp);
        tmpLol = tmp;
    }
    free(tmp);
}

%}


%union {
    char *string;
    struct Node *node;
    struct List *list;
}


// Define Exoressions And Statement
%token DEFINE_EXPR DEFINE_EXPR_0 DEFINE_EXPR_1 DEFINE_EXPR_2
%token DEFINE_STMT DEFINE_STMT_0 DEFINE_STMT_1 DEFINE_STMT_2

// Brackets
%token LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET
%token LEFT_SQR_BRACKET RIGHT_SQR_BRACKET
%token LEFT_CURL_BRACKET RIGHT_CURL_BRACKET

%token IDENTIFIER INTEGER_LITERAL
%token TRUE FALSE
%token THIS NEW INT NOT BOOLEAN
%token OPERATOR DOT COMMA LENGTH
%token SEMI_COLON ASSIGN IF ELSE WHILE RETURN 
%token SYSTEM_OUT_PRINTLN CLASS  
%token PUBLIC_STATIC_VOID_MAIN STRING PUBLIC EXTENDS

%type<string> INTEGER_LITERAL
%type<string> IDENTIFIER
%type<string> OPERATOR

%type<list> Goal
%type<list> MainClass Class 
%type<list> MacroDefinition MacroDefExpression MacroDefStatement
%type<list> DefineExpr DefineExpr0 DefineExpr1 DefineExpr2
%type<list> DefineStmt DefineStmt0 DefineStmt1 DefineStmt2
%type<list> SysOut If Else While Int Assign Return
%type<list> MoreArgs Semicolon Extends Public
%type<list> Expression PrimaryExpression Statement
%type<list> Operation Dot String PublicMain ElsePart
%type<list> Identifier Comma Integer Boolean Length Type IdentifierStatement
%type<list> This BoolVal New Not MainFuntion MainFunctionStatement
%type<list> LRbracket RRbracket LCbracket RCbracket LSbracket RSbracket IntBrackets
%type<list> ThreeArgs TwoArgs OneArg PositiveExpression SubExpression MultipleTypeArgs MoreTypeArgs NonZeroExpression
%type<list> MultipleTypeDeclaration WithExtends MultipleType MoreType MultipleMethod MultipleTypeArgsStatement

%start Goal

%%

Goal :  MacroDefinition MainClass MultipleTypeDeclaration {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
    PrintList($$);
    Free($$);
};

MainClass : Class Identifier LCbracket MainFuntion RCbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate ($3, Concatenate($4, $5)))));
};
Class     : CLASS { 
    MakeNull($$);
    Insert($$, "class ");
}

MainFuntion : PublicMain LRbracket String LSbracket RSbracket Identifier RRbracket LCbracket MainFunctionStatement RCbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, Concatenate($8, Concatenate($9, $10))))))))));
};
PublicMain : PUBLIC_STATIC_VOID_MAIN  { 
    MakeNull($$);
    Insert($$, "public static void main ");
 }
String     : STRING  { 
    MakeNull($$);
    Insert($$, "String ");
} 

MainFunctionStatement : SysOut LRbracket Expression RRbracket Semicolon {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, $5)))));
};

MultipleTypeDeclaration : Class Identifier WithExtends {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}
                        |  { 
                           MakeNull($$);
                        };

WithExtends : Extends Identifier LCbracket MultipleType MultipleMethod RCbracket MultipleTypeDeclaration {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, $7)))))));
}
            | LCbracket MultipleType MultipleMethod RCbracket MultipleTypeDeclaration {
                MakeNull($$);
                Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, $5))))); 
            };

Extends : EXTENDS  { 
    MakeNull($$);
    Insert($$, "extends ");
 }

MultipleType : Type Identifier Semicolon MultipleType {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
} | { 
    MakeNull($$);
};
MoreType     : Type Identifier MoreType { 
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}| { 
    MakeNull($$;
};

MultipleMethod : Public Type Identifier LRbracket MultipleTypeArgs RRbracket LCbracket MultipleTypeArgsStatement Return Expression Semicolon RCbracket MultipleMethod {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, Concatenate($8, Concatenate($9, Concatenate($10, Concatenate($11, Concatenate($12, $13)))))))))))));
}
               | {
                   MakeNull($$);
                };

MultipleTypeArgsStatement : Type Identifier Semicolon MultipleTypeArgsStatement {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
}
                          | Statement {
                              MakeNull($$);
                              Concatenate($$, $1);
                          };

Public : PUBLIC  { 
    MakeNull($$);
    Insert($$, "public ");
}; 
MultipleTypeArgs : Type Identifier MoreTypeArgs {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}
                 | { 
                     MakeNull($$); };
MoreTypeArgs : Comma Type Identifier MoreTypeArgs {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
} | { 
    MakeNull($$);
};
Return : RETURN  { 
    MakeNull($$);
    Insert($$, "return ");
}; 

Type : Int IntBrackets {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
}
     | Boolean {
         MakeNull($$);
         Concatenate($$, $1);
     }
     | Identifier {
         MakeNull($$);
         Concatenate($$, $1);
     };
     
IntBrackets : LSbracket RSbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
}
            | { MakeNull($$);};
    

MacroDefinition : MacroDefExpression MacroDefinition {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
} 
                | MacroDefStatement MacroDefinition {
                    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
                }
                | { 
                    MakeNull($$);};

MacroDefStatement : DefineStmt Identifier LRbracket ThreeArgs RRbracket LCbracket Statement RCbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
}
                   | DefineStmt0 Identifier LRbracket RRbracket LCbracket Statement RCbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, $7)))))));
                   }
                   | DefineStmt1 Identifier LRbracket OneArg RRbracket LCbracket Statement RCbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
                   }
                   | DefineStmt2 Identifier LRbracket TwoArgs RRbracket LCbracket Statement RCbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
                   };

DefineStmt  : DEFINE_STMT  { 
    MakeNull($$);
    Insert($$, "#defineStmt ");
 };
DefineStmt0 : DEFINE_STMT_0 { 
    MakeNull($$);
    Insert($$, "#defineStmt0 ");
};
DefineStmt1 : DEFINE_STMT_1  { 
    MakeNull($$);
    Insert($$, "#defineStmt1 ");};
DefineStmt2 : DEFINE_STMT_2  { 
    MakeNull($$);
    Insert($$, "#defineStmt2 ");
};

Statement :  LCbracket Statement RCbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}
           | SysOut LRbracket Expression RRbracket Semicolon Statement {
               MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, $6))))));
           }
           | If LRbracket Expression RRbracket Statement ElsePart {
               MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, $6))))));
           }
           | Identifier IdentifierStatement {
               MakeNull($$);
               Concatenate($$, Concatenate($1, $2));
           }
           | While LRbracket Expression RRbracket Statement Statement {
               MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, $6))))));
           }
           | { MakeNull($$);};

IdentifierStatement : Assign Expression Semicolon Statement {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
}
                    | LSbracket Expression RSbracket Assign Expression Semicolon Statement {
                        MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, $7)))))));
                    }
                    | LRbracket NonZeroExpression RRbracket Semicolon {
                        MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
                    };

ElsePart : Else Statement Statement {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}

SysOut : SYSTEM_OUT_PRINTLN  { 
    MakeNull($$);
    Insert($$, "System.out.println");
}
Semicolon : SEMI_COLON  { 
    MakeNull($$);
    Insert($$, ";\n");
 }
Assign    : ASSIGN  { 
    MakeNull($$);
    Insert($$, "=");
}
If        : IF  { 
    MakeNull($$);
    Insert($$, "if");
}
Else      : ELSE  { 
    MakeNull($$);
    Insert($$, "else");
}
While     : WHILE { 
    MakeNull($$);
    Insert($$, "while");
}



MacroDefExpression : DefineExpr Identifier LRbracket ThreeArgs RRbracket LRbracket Expression RRbracket {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
}
                   | DefineExpr0 Identifier LRbracket RRbracket LRbracket Expression RRbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6,$7)))))));
                   }
                   | DefineExpr1 Identifier LRbracket OneArg RRbracket LRbracket Expression RRbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
                   }
                   | DefineExpr2 Identifier LRbracket TwoArgs RRbracket LRbracket Expression RRbracket {
                       MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, Concatenate($6, Concatenate($7, $8))))))));
                   };

DefineExpr  : DEFINE_EXPR   { 
    MakeNull($$);
    Insert($$, "#defineExpr ");
 }
DefineExpr0 : DEFINE_EXPR_0   { 
    MakeNull($$);
    Insert($$, "#defineExpr0 ");
}
DefineExpr1 : DEFINE_EXPR_1   { 
    MakeNull($$);
    Insert($$, "#defineExpr1 ");
}
DefineExpr2 : DEFINE_EXPR_2  { 
    MakeNull($$);
    Insert($$, "#defineExpr2 ");
}

Expression : PrimaryExpression SubExpression {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
}
           | Identifier LRbracket NonZeroExpression RRbracket {
               MakeNull($$);
               Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
           }; 

SubExpression : Operation PrimaryExpression {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
}
              | LSbracket PrimaryExpression RSbracket {
                  MakeNull($$);
                  Concatenate($$, Concatenate($1, Concatenate($2, $3)));
              }
              | Length {
                  MakeNull($$);
                  Concatenate($$, $1);
              }
              | Dot Identifier LRbracket NonZeroExpression RRbracket {
                  MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4,$5)))));
              }
              | { MakeNull($$);};

NonZeroExpression : Expression PositiveExpression {
    MakeNull($$);
    Concatenate($$, Concatenate($1, $2));
}
                  | { MakeNull($$); };
PositiveExpression : Comma Expression PositiveExpression {
                        MakeNull($$);
                        Concatenate($$, Concatenate($1, Concatenate($2, $3)));
                    }
                  | { MakeNull($$); };

Operation  : OPERATOR {
    MakeNull($$);
    Insert($$, $1);
            };

PrimaryExpression : Integer {
    MakeNull($$);
    Concatenate($$, $1);
}
                  | BoolVal {
                      MakeNull($$);
    Concatenate($$, $1);
                  }
                  | Identifier {
                      MakeNull($$);
    Concatenate($$, $1);
                  }
                  | This {
                      MakeNull($$);
    Concatenate($$, $1);
                  }
                  | New Int LSbracket Expression RSbracket {
                      MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, $5)))));
                  }
                  | New Identifier LRbracket RRbracket {
                      MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, $4))));
                  }
                  | Not Expression {
                      MakeNull($$);
                      Concatenate($$, Concatenate($1, $2));
                  }
                  | LRbracket Expression RRbracket {
                      MakeNull($$);
                      Concatenate($$, Concatenate($1, Concatenate($2, $3)));
                  };

BoolVal : TRUE {
            MakeNull($$);
            Insert($$, "true ");
        }
        | FALSE {
           MakeNull($$);
           Insert($$, "false ");
        };

This : THIS  { 
    MakeNull($$);
    Insert($$, "this");
 };
Length : LENGTH  { 
    MakeNull($$);
    Insert($$, ".length ");
};
New : NEW  { 
    MakeNull($$);
    Insert($$, "new ");
 };
Int : INT  { 
    MakeNull($$);
    Insert($$, "int ");
 };
Not : NOT  { 
    MakeNull($$);
    Insert($$, "!");
 };
Dot : DOT { 
    MakeNull($$);
    Insert($$, ".");
 };
Boolean : BOOLEAN { 
    MakeNull($$);
    Insert($$, "boolean ");
};

ThreeArgs : Identifier Comma Identifier Comma Identifier MoreArgs {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, Concatenate($3, Concatenate($4, Concatenate($5, $6))))));
};


MoreArgs  : Comma Identifier MoreArgs {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
}
          | {
    MakeNull($$);
};

TwoArgs   : Identifier Comma Identifier {
    MakeNull($$);
    Concatenate($$, Concatenate($1, Concatenate($2, $3)));
};

OneArg    : Identifier {
    MakeNull($$);
    Concatenate($$, $1);
};

Integer : INTEGER_LITERAL {
               MakeNull($$);
               Insert($$, $1);
            }
Identifier : IDENTIFIER {
               MakeNull($$);
               Insert($$, $1);
            };
LRbracket : LEFT_ROUND_BRACKET {
                MakeNull($$);
                Insert($$, "( ");
            };
RRbracket : RIGHT_ROUND_BRACKET {
                MakeNull($$);
                Insert($$, ") ");
            }
LSbracket : LEFT_SQR_BRACKET {
                MakeNull($$);
                Insert($$, "[ ");
            }
RSbracket : RIGHT_SQR_BRACKET {
                MakeNull($$);
                Insert($$, "] ");
            }
LCbracket : LEFT_CURL_BRACKET {
                MakeNull($$);
                Insert($$, "\n{\n");
            }
RCbracket : RIGHT_CURL_BRACKET {
                MakeNull($$);
                Insert($$, "\n}\n");
            }
Comma     : COMMA {
                MakeNull($$);
                Insert($$, ", ");
            }            
%%





int yyerror()
{
    printf("//Failed to parse input code\n");
    return 0;  
}

int main()
{
    // #ifdef YYDEBUG
    // yydebug = 1;  
    // #endif
    yyparse();
    return 0;
}