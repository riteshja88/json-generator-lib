# json-generator-lib

```
json-generator-lib $ make
rm -f ./a.out;./run_project.sh  > inc.c && gcc -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0   -lasan -Wextra -Werror -c inc.c && gcc -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0  main.c inc.o -lasan && ./a.out |jq -c
{"x_":-101,"y_":101,"z1_":[-11011,-22022],"z2_":[110011,220022],"s1_":{"s1_1_":-9876,"s1_2_":{"s0_1_":0}},"s2_":[{"s1_1_":-1111,"s1_2_":{"s0_1_":0}},{"s1_1_":-2222,"s1_2_":{"s0_1_":0}}],"ptr1_":-1234,"ptr2_":4321,"sptr_":{"s1_1_":-9876,"s1_2_":{"s0_1_":0}},"f1_":1.12,"f2_":[1.123,2.122],"f3_":3.1235,"str_":"abc","str2_":"pqr\b\f\n\r\t/\\\"\u001f","str3_":["aaa111","bbb222"],"b1_":true,"b2_":true,"b3_":[false,true],"sliceptr1_":[-11011,-22022],"sliceptr2_":[110011,220022],"sliceptr3_":[{"s1_1_":-1111,"s1_2_":{"s0_1_":0}},{"s1_1_":-2222,"s1_2_":{"s0_1_":0}}],"sliceptr4_":[false,true],"sliceptr5_":[1.12345,2.122345],"sliceptr6_":["aaa111","bbb222"],"aop_i_":[-11011,-22022],"dp_i_":[-11011,-22022],"aop_ui_":[110011,220022],"dp_ui_":[110011,220022],"aop_f_":[1.12345,2.122345],"dp_f_":[1.12345,2.12234],"aop_b_":[false,true],"dp_b_":[false,true],"aop_struct_":[{"s1_1_":-1111,"s1_2_":{"s0_1_":0}},{"s1_1_":-2222,"s1_2_":{"s0_1_":0}}],"dp_struct_":[{"s1_1_":-1111,"s1_2_":{"s0_1_":0}},{"s1_1_":-2222,"s1_2_":{"s0_1_":0}}],"aop_string_":["aaa111","bbb222"],"dp_string_":["aaa111","bbb222"]}
```


```
#perf test
ritesh@ritesh-lappi:~/json-generator-lib$make test;for ((i=0;i<30;i++));do ./a.out |awk '{sum+=$1} END {print sum/NR}';done|awk '{sum+=$1} END {print sum/NR}'
rm -f ./a.out;./run_project_test.sh  > inc_test.c && gcc -g -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0   -lasan -Wextra -Werror -c inc_test.c && gcc -g -fsanitize=address -fsanitize-recover=address -fstack-protector-all -fstack-check --param asan-stack=0  main_test.c inc_test.o -lasan && ./a.out |jq
7568
parse error: Invalid numeric literal at line 2, column 0
Makefile:5: recipe for target 'test' failed
make: *** [test] Error 4
7514.18
```


| test description                | values              | number of iterations | time taken (usecs) - json-generator-lib | time taken (usecs) - jsonc | latency gain |
| ------------------------------- | ------------------- | -------------------- | --------------------------------------- | -------------------------- | ------------ |
| 1000 int                        | random              | 900                  | 1243                                    | 2550                       | 2.1x         |
| 1000 int[50]                    | random, 50 elements | 900                  | 51523                                   | 105000                     | 2.0x         |
| 1000 float (%g)                 | random              | 900                  | 1882                                    | 4472                       | 2.4x         |
| 1000 float[50] (%g)             | random, 50 elements | 900                  | 94499                                   | 215000                     | 2.3x         |
| 1000 char[50]                   | random              | 900                  | 3720                                    | 5443                       | 1.5x         |
| 1000 char[50][50]               | random, 50 elements | 900                  | 186744                                  | 365000                     | 2.0x         |
| 1000 char[50] - 2 level objects | random              | 900                  | 7588                                    | 10886                      | 1.4x         |
|                                 |                     |                      |                                         |                            |              |
| 1000 float (%g)                 | random              | 900                  | 1882                                    |                            |              |
| 1000 float (%.2g)               | random              | 900                  | 1757                                    |                            |              |
| 1000 float (%f)                 | random              | 900                  | 2403                                    |                            |              |
| 1000 float (%.2f)               | random              | 900                  | 2294                                    |                            |              |
