%option yylineno

%{
	#include"y.tab.h"
	int yyerror(const char *errormsg);
%}

%%
"//".*							{;/*comments*/}
"/*"[^\-].*[^\-]"*/"			{;/*comments*/}
"unsigned"						{return UNSIGNED_TOK;}
"int"							{yylval.string = strdup(yytext);return FIXED_POINT_NUMBER_TYPE_TOK;}
"float"							{yylval.string = strdup(yytext);return FLOATING_POINT_NUMBER_TYPE_TOK;}
"char"							{return CHAR_TYPE_TOK;}
"struct"						{return STRUCT_TOK;}
"typedef"						{return TYPEDEF_TOK;}
"json_key"						{return JSON_KEY_TOK;}
"json_type"						{return JSON_TYPE_TOK;}
"boolean"						{return BOOLEAN_TOK;}
"format_specifier"				{return FORMAT_SPECIFIER_TOK;}
"slice"							{return SLICE_TOK;}
"%"("."[0-9]*)?[efg]			{yylval.string = strdup(yytext);return FORMAT_SPECIFIER_VALUE_TOK;}
"MAX_"[a-zA-Z_][a-zA-Z_0-9]*|"MAX_"[a-zA-Z_][a-zA-Z_0-9]*"+1"|"MAX_"[a-zA-Z_][a-zA-Z_0-9]*" + 1" {yylval.number = -1; return NUMBER_TOK;}
[a-zA-Z_][a-zA-Z_0-9]*"_count"	{return ID_COUNT_TOK;}
[a-zA-Z_][a-zA-Z_0-9]*			{yylval.string = strdup(yytext);return ID_TOK;}
"\/*-"							{return COMMENT_OPEN_TOK;};
"-*\/"							{return COMMENT_CLOSE_TOK;};
";"|"{"|"}"|"["|"]"|"\""|":"	{return yytext[0];}
","|"("|")"						{return yytext[0];}
"*"								{return POINTER_TOK;}
[1-9][0-9]*						{yylval.number = atoi(yytext);return NUMBER_TOK;}
[ \t\n]							;
.								{ yyerror("Unknow char");  }
%%

int yywrap(void)
{
    return 1;
}

extern int yylineno;
int yyerror(const char *msg)
{

	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	return 0;
}
