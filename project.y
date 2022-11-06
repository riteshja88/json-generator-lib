%{
	#include<stdio.h>
	#include "json_prereq.h"
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	extern int yylineno;
	extern char* yytext;
%}

%union {
    char *string;
	int number;
}
%token STRUCT_TOK TYPEDEF_TOK UNSIGNED_TOK ID_COUNT_TOK POINTER_TOK COMMENT_OPEN_TOK COMMENT_CLOSE_TOK JSON_KEY_TOK FORMAT_SPECIFIER_TOK CHAR_TYPE_TOK JSON_TYPE_TOK BOOLEAN_TOK SLICE_TOK
%token <string> ID_TOK
%token <string> FIXED_POINT_NUMBER_TYPE_TOK
%token <string> FLOATING_POINT_NUMBER_TYPE_TOK
%token <number> NUMBER_TOK
%token <string> FORMAT_SPECIFIER_VALUE_TOK
						
%define parse.error verbose
%start program_unit
%%
program_unit:
				{printf("#include \"helpers.h\"\n");printf("#include \"inp.h\"\n");printf("#include <stdio.h>\n");} translation_unit
				;

translation_unit:
				struct_decl
				| translation_unit struct_decl
				;

struct_decl:
				struct_decl_start struct_member_decls struct_decl_end
				;

struct_decl_start:
				TYPEDEF_TOK STRUCT_TOK ID_TOK '{' {
					generate_function_header_for_struct($3);
				}
				;

struct_decl_end:
				'}' ID_TOK ';' {
					generate_function_footer_for_struct();
					generate_function_for_struct_array($2);
					generate_function_for_struct_pointer_array($2);
				}
				;

struct_member_decls:
				struct_member_decl
				| struct_member_decls struct_member_decl
				;

struct_member_decl:
				FIXED_POINT_NUMBER_TYPE_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_member_for_struct($1,$2,$8,"");
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_member_unsigned_for_struct($2,$3,$9);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$2,$4,$11,"");
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_unsigned_for_struct($2,$3,$5,$12);
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK ID_COUNT_TOK ';' {
					/* ignore member variables with "_count" suffix */;
				}
				| ID_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_member_for_struct($1,$2,$8,"");
				}
				| ID_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$2,$4,$11,"");
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_member_for_struct($1,$3,$9,"");
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' SLICE_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$3,-1 /* infinite size */,$9,"");
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_member_unsigned_for_struct($2,$4,$10);
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' SLICE_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_unsigned_for_struct($2,$4,-1 /* infinite size */,$10);
				}
				| ID_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_member_for_struct($1,$3,$9,"");
				}
				| ID_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' SLICE_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$3,-1 /* infinite size */,$9,"");
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' COMMENT_CLOSE_TOK {
					generate_function_add_member_for_struct($1,$2,$8,$14);
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$2,$4,$11,$17);
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' COMMENT_CLOSE_TOK {
					generate_function_add_pointer_member_for_struct($1,$3,$9,$15);
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' ',' SLICE_TOK COMMENT_CLOSE_TOK {
					generate_function_add_array_member_for_struct($1,$3,-1 /* infinite size */,$9,$15);
				}
				| CHAR_TYPE_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_string_member_for_struct($2,$4,$11);
				}
				| CHAR_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_string_member_for_struct($3,0,$9);
				}
				| CHAR_TYPE_TOK ID_TOK '[' NUMBER_TOK ']''[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_string_array_member_for_struct($2,$4,$7,$14);
				}
				| CHAR_TYPE_TOK '(' POINTER_TOK ID_TOK ')' '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' SLICE_TOK   COMMENT_CLOSE_TOK {
					generate_function_add_string_array_member_for_struct($4,-1 /* infinite size */,$7,$14);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_member_for_struct($2,$8);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_array_member_for_struct($2,$4,$11);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_pointer_member_for_struct($3,$9);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK ',' SLICE_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_array_member_for_struct($3,-1 /* infinite size */,$9);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$3,$5,$12,"");
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$4,-1 /* infinite size */,$10,"");
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_unsigned_for_struct($2,$4,$6,$13);
				}
				| UNSIGNED_TOK FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_unsigned_for_struct($2,$5,-1 /* infinite size */,$11);
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$3,$5,$12,$18);
				}
				| FLOATING_POINT_NUMBER_TYPE_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' FORMAT_SPECIFIER_TOK ':' '\"' FORMAT_SPECIFIER_VALUE_TOK '\"' COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$4,-1 /* infinite size */,$10,$16);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_pointer_array_member_for_struct($3,$5,$12);
				}
				| FIXED_POINT_NUMBER_TYPE_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"' ',' JSON_TYPE_TOK ':' BOOLEAN_TOK  COMMENT_CLOSE_TOK {
					generate_function_add_boolean_pointer_array_member_for_struct($4,-1 /* infinite size */,$10);
				}
				| ID_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$3,$5,$12,"");
				}
				| ID_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_pointer_array_member_for_struct($1,$4,-1 /* infinite size */,$10,"");
				}
				| CHAR_TYPE_TOK POINTER_TOK ID_TOK '[' NUMBER_TOK ']' ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_string_pointer_array_member_for_struct($3,$5,-1 /* infinite size */,$12);
				}
				| CHAR_TYPE_TOK POINTER_TOK POINTER_TOK ID_TOK ';' COMMENT_OPEN_TOK JSON_KEY_TOK ':' '\"' ID_TOK  '\"'  COMMENT_CLOSE_TOK {
					generate_function_add_string_pointer_array_member_for_struct($4,-1 /* infinite size */,-1 /* infinite size */,$10);
				}
				;

%%

int main()
{
    yyparse();
	/*
    if(success)
    	printf("Parsing Successful\n");
	*/
    return 0;
}
