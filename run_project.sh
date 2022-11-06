yacc -d -v project.y && flex project.l && gcc -Wextra -Werror -o a.out y.tab.c lex.yy.c -lfl -lm && ./a.out < inp.h
