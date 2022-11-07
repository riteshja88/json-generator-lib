typedef struct struct0_t {
	int s0_1;					/*- json_key:"s0_1_" -*/
} struct0_t;

typedef struct struct1_t {
	int *s1_1;					/*- json_key:"s1_1_" -*/
	struct0_t s1_2;  			/*- json_key:"s1_2_" -*/
} struct1_t;

typedef struct struct2_t {
	int x;						 /*- json_key:"x_" -*/ //this comment will be ignored.
	unsigned int y; 			 /*- json_key:"y_" -*/ /* this comment will also be ignored */
	unsigned int z1_count;
	int z1[3];					 /*- json_key:"z1_" -*/
	unsigned int z2_count;
	unsigned int z2[3];			 /*- json_key:"z2_" -*/
	struct1_t s1;  				 /*- json_key:"s1_" -*/
	unsigned int s2_count;
	struct1_t s2[10];  			 /*- json_key:"s2_" -*/
	int *ptr1; 					 /*- json_key:"ptr1_" -*/
	unsigned int *ptr2; 		 /*- json_key:"ptr2_" -*/
	struct1_t *sptr;			 /*- json_key:"sptr_" -*/
	float f1;					 /*- json_key:"f1_",format_specifier:"%.2f" -*/
	unsigned int f2_count;
	float f2[10];				 /*- json_key:"f2_",format_specifier:"%.3f" -*/
	float *f3;					 /*- json_key:"f3_",format_specifier:"%.4f" -*/
	char str[12];	 		 	 /*- json_key:"str_" -*/
	char *str2;					 /*- json_key:"str2_" -*/
	unsigned int str3_count;
	char str3[3][12]; 		 	 /*- json_key:"str3_" -*/
	int b1;						 /*- json_key:"b1_",json_type:boolean -*/
	int *b2;					 /*- json_key:"b2_",json_type:boolean -*/
	unsigned int b3_count;
	int b3[3];					 /*- json_key:"b3_",json_type:boolean -*/
	unsigned int sliceptr1_count;
	int *sliceptr1; 			 /*- json_key:"sliceptr1_",slice -*/
	unsigned int sliceptr2_count;
	unsigned int *sliceptr2;	/*- json_key:"sliceptr2_",slice -*/
	unsigned int sliceptr3_count;
	struct1_t *sliceptr3; 	    /*- json_key:"sliceptr3_",slice -*/
	unsigned int sliceptr4_count;
	int *sliceptr4;				/*- json_key:"sliceptr4_",json_type:boolean,slice -*/
	unsigned int sliceptr5_count;
	float *sliceptr5;			/*- json_key:"sliceptr5_",format_specifier:"%e",slice -*/
	unsigned int sliceptr6_count;
	char (*sliceptr6)[12];		/*- json_key:"sliceptr6_",slice -*/
	unsigned int aop_i_count;
	int *aop_i[10];				/*- json_key:"aop_i_" -*/
	unsigned int dp_i_count;
	int **dp_i;					/*- json_key:"dp_i_" -*/
	unsigned int aop_ui_count;
	unsigned int *aop_ui[10];	/*- json_key:"aop_ui_" -*/
	unsigned int dp_ui_count;
	unsigned int **dp_ui;		/*- json_key:"dp_ui_" -*/
	unsigned int aop_f_count;
	float *aop_f[10];			/*- json_key:"aop_f_",format_specifier:"%f"-*/
	unsigned int  dp_f_count;
	float **dp_f;				/*- json_key:"dp_f_",format_specifier:"%g" -*/
	unsigned int aop_b_count;
	int *aop_b[10];				/*- json_key:"aop_b_",json_type:boolean -*/
	unsigned int dp_b_count;
	int **dp_b;					/*- json_key:"dp_b_",json_type:boolean -*/
	unsigned int aop_struct_count;
	struct1_t *aop_struct[10];		/*- json_key:"aop_struct_" -*/
	unsigned int dp_struct_count;
	struct1_t **dp_struct;			/*- json_key:"dp_struct_" -*/
	unsigned int aop_string_count;
	char *aop_string[10];		/*- json_key:"aop_string_" -*/
	unsigned int dp_string_count;
	char **dp_string;			/*- json_key:"dp_string_" -*/

	unsigned int intarray_count;
	int intarray[MAX_INTS];					 /*- json_key:"intarray_" -*/
	unsigned int strarray_count;
	char strarray[MAX_STRS][201];		 /*- json_key:"strarray_" -*/
} struct2_t;
