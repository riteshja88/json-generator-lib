all:
	rm -f ./a.out;./run_project.sh  > inc.c && gcc -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0   -lasan -Wextra -Werror -c inc.c && gcc -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0  main.c inc.o -lasan && ./a.out |jq

clean:
	rm -f  a.out inc.c inc.o lex.yy.c y.output y.tab.h y.tab.c
