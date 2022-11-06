#include "inp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void jout_struct2_t_array(char ** const post_data_temp_ptr, const char key[], const struct2_t value_array[], const int array_count, const int array_size, int * const precede_by_comma);

void jout_struct2_t(char ** const post_data_temp_ptr, const char key[], const struct2_t * const value, int * const precede_by_comma);


void jout_struct1_t(char ** const post_data_temp_ptr, const char key[], const struct1_t * const value, int * const precede_by_comma);

void jout_struct1_t_array(char ** const post_data_temp_ptr, const char key[], const struct1_t value_array[], const int array_count, const int array_size, int * const precede_by_comma);

int main()
{
	char post_data[10000];
	char *post_temp_ptr = post_data;
	static struct2_t s;
	s.x=-101;
	s.y=101;
	s.z1_count = 2;
	s.z1[0]=-11011;
	s.z1[1]=-22022;;
	s.z2_count = 2;
	s.z2[0]=110011;
	s.z2[1]=220022;
	int l = -9999;
	s.s1.s1_1 = &l;
	s.s2_count = 2;
	int l1 =-1111;
	s.s2[0].s1_1 = &l1;
	int l2 = -2222;;
	s.s2[1].s1_1 = &l2;
	int precede_by_comma = 0;
	int x = -1234;
	s.ptr1=&x;
	unsigned int y = 4321;
	s.ptr2=&y;
	//s.ptr1 = NULL;
	//s.ptr2 = NULL;
	struct1_t s1;
	l = -9876;
	s1.s1_1 = &l;
	s.sptr = &s1;
	//s.sptr = NULL;

	s.f1 = 1.12345;
	s.f2_count = 2;
	s.f2[0] = 1.12345;
	s.f2[1] = 2.122345;
	float f3 = 3.12345;
	s.f3 = &f3;
	//s.f3= NULL;

	strcpy(s.str, "abc");
	//strcpy(s.str, "");

	s.str2 = strdup("pqr\b\f\n\r\t/\\\"\x1f");
	//s.str2 = NULL;

	s.str3_count = 2;
	strcpy(s.str3[0], "aaa111");
	strcpy(s.str3[1], "bbb222");
	strcpy(s.str3[2], "ccc333");

	s.b1 = -10;
	int b2 = 10;
	s.b2 = &b2;
	//s.b2 = NULL;
	s.b3_count = 2;
	s.b3[0] = 0;
	s.b3[1] = 1;
	s.b3[2] = 0;

	s.sliceptr1_count = 2;
	s.sliceptr1 = s.z1;

	s.sliceptr2_count = 2;
	s.sliceptr2 = s.z2;

	s.sliceptr3_count = 2;
	s.sliceptr3 = s.s2;

	s.sliceptr4_count = 2;
	s.sliceptr4 = s.b3;

	s.sliceptr5_count = 2;
	s.sliceptr5 = s.f2;

	s.sliceptr6_count = 2;
	s.sliceptr6 = s.str3;

	s.aop_i_count = 2;
	s.aop_i[0] = &s.z1[0];
	s.aop_i[1] = &s.z1[1];


	s.dp_i = malloc(sizeof(int *)*10);
	s.dp_i_count = 2;
	s.dp_i[0] = &s.z1[0];
	s.dp_i[1] = &s.z1[1];

	s.aop_ui_count = 2;
	s.aop_ui[0] = &s.z2[0];
	s.aop_ui[1] = &s.z2[1];


	s.dp_ui = malloc(sizeof(unsigned int *)*10);
	s.dp_ui_count = 2;
	s.dp_ui[0] = &s.z2[0];
	s.dp_ui[1] = &s.z2[1];

	s.aop_f_count = 2;
	s.aop_f[0] = &s.f2[0];
	s.aop_f[1] = &s.f2[1];


	s.dp_f = malloc(sizeof(float *)*10);
	s.dp_f_count = 2;
	s.dp_f[0] = &s.f2[0];
	s.dp_f[1] = &s.f2[1];


	s.aop_b_count = 2;
	s.aop_b[0] = &s.b3[0];
	s.aop_b[1] = &s.b3[1];

	s.dp_b = malloc(sizeof(int *)*10);
	s.dp_b_count = 2;
	s.dp_b[0] = &s.b3[0];
	s.dp_b[1] = &s.b3[1];

	s.aop_struct_count = 2;
	s.aop_struct[0] = &s.s2[0];
	s.aop_struct[1] = &s.s2[1];

	s.dp_struct = malloc(sizeof(struct1_t *)*10);
	s.dp_struct_count = 2;
	s.dp_struct[0] = &s.s2[0];
	s.dp_struct[1] = &s.s2[1];

	s.aop_string_count = 2;
	s.aop_string[0] = &s.str3[0][0];
	s.aop_string[1] = &s.str3[1][0];

	s.dp_string = malloc(sizeof(char *)*10);
	s.dp_string_count = 2;
	s.dp_string[0] = &s.str3[0][0];
	s.dp_string[1] = &s.str3[1][0];
	
	jout_struct2_t(&post_temp_ptr,
				   NULL,
				   &s,
				   &precede_by_comma);

	printf("%s\n",post_data);

	free(s.dp_i);
	free(s.dp_ui);
	free(s.dp_f);
	free(s.dp_b);
	free(s.dp_struct);
}
