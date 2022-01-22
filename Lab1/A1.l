%{
#include <stdio.h>
#include "A1.tab.h"
#include <string.h>

%}

%%

"#defineExpr" { return DEFINE_EXPR; }
"#defineExpr0" { return DEFINE_EXPR_0; }
"#defineExpr1" { return DEFINE_EXPR_1; }
"#defineExpr2" { return DEFINE_EXPR_2; }

"#defineStmt" { return DEFINE_STMT; }
"#defineStmt0" { return DEFINE_STMT_0; }
"#defineStmt1" { return DEFINE_STMT_1; }
"#defineStmt2" { return DEFINE_STMT_2; }
"//".*

"(" { return LEFT_ROUND_BRACKET; }
")" { return RIGHT_ROUND_BRACKET; }
"{" { return LEFT_CURL_BRACKET; }
"}" { return RIGHT_CURL_BRACKET; }
"[" { return LEFT_SQR_BRACKET; } 
"]" { return RIGHT_SQR_BRACKET;} 
"." { return DOT; }
"," { return COMMA; }
"!" { return NOT; }
";" { return SEMI_COLON;}
"=" { return ASSIGN;}
"if" { return IF;}
"else" { return ELSE;}
"while" { return WHILE;}

"true"  { return TRUE; }
"false" { return FALSE; }
"this"  { return THIS; }
"new"   { return NEW; }
"int"   { return INT; }
"System.out.println" { return SYSTEM_OUT_PRINTLN; }
"public" { return PUBLIC;}
"class" { return CLASS; }
"public static void main" { return PUBLIC_STATIC_VOID_MAIN;}
"String" { return STRING;}
".length" { return LENGTH;}
"boolean" { return BOOLEAN;}
"return" { return RETURN;}
"extends" {return EXTENDS;}

0|[1-9][0-9]* {
    int length = strlen(yytext);
    yylval.string = (char *)malloc((length + 1)* sizeof(char));
    yylval.string[0] = '\0';
    strcat(yylval.string, yytext); 
    return INTEGER_LITERAL; 
}
[a-zA-Z][0-9a-zA-Z_$]* {
    int length = strlen(yytext);
    yylval.string = (char *)malloc((length + 1)* sizeof(char));
    yylval.string[0] = '\0';
    strcat(yylval.string, yytext); 
    return IDENTIFIER; 
}

"+"|"-"|"/"|"*"|"&&"|"||"|"!="|"<=" { 
    int length = strlen(yytext);
    yylval.string = (char *)malloc((length + 1)* sizeof(char));
    yylval.string[0] = '\0';
    strcat(yylval.string, yytext); 
    return OPERATOR; 
}


[ \t\n\f] {
}
. { printf("//Failed to parse input code\n");}
%%
