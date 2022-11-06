void generate_function_for_struct_pointer_array(const char * const struct_type_name)
{
	/* header */
	printf("void jout_%s_pointer_array(char ** const post_data_temp_ptr, const char key[], %s * const * const pointer_array, const unsigned int pointer_array_count, const unsigned int pointer_array_size, int * const precede_by_comma) {\n",
		   struct_type_name,
		   struct_type_name);
	printf("\tchar * const post_data_temp_ptr_in = *post_data_temp_ptr;\n");
	printf("\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr, \"%%s%%s%%s%%s%%s[\", (1 == *precede_by_comma)?\",\":\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?key:\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?\":\":\"\");\n");
	printf("\tint precede_by_comma_local = 0;\n\n");

	/* array members */
	printf("\tfor(unsigned int i=0;((i < pointer_array_count) && (i < pointer_array_size)); i++) {\n");
	printf("\t\tjout_%s(post_data_temp_ptr, NULL, pointer_array[i], &precede_by_comma_local);\n",
		   struct_type_name);
	printf("\t}\n");


	/* footer */
	printf("\n\tif(1 == precede_by_comma_local) {\n");
	printf("\t\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,\"]\");\n");
	printf("\t\t*precede_by_comma = 1;\n");
	printf("\t}\n");
	printf("\telse {\n");
	printf("\t\t*post_data_temp_ptr = post_data_temp_ptr_in;\n");
	printf("\t\t**post_data_temp_ptr = '\\0';\n");
	printf("\t}\n");
	printf("}\n\n");
}

void generate_function_for_struct_array(const char * const struct_type_name)
{
	/* header */
	printf("void jout_%s_array(char ** const post_data_temp_ptr, const char key[], const %s value_array[], const unsigned int array_count, const unsigned int array_size, int * const precede_by_comma) {\n",
		   struct_type_name,
		   struct_type_name);
	printf("\tchar * const post_data_temp_ptr_in = *post_data_temp_ptr;\n");
	printf("\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr, \"%%s%%s%%s%%s%%s[\", (1 == *precede_by_comma)?\",\":\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?key:\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?\":\":\"\");\n");
	printf("\tint precede_by_comma_local = 0;\n\n");

	/* array members */
	printf("\tfor(unsigned int i=0;((i < array_count) && (i < array_size)); i++) {\n");
	printf("\t\tjout_%s(post_data_temp_ptr, NULL, &value_array[i], &precede_by_comma_local);\n",
		   struct_type_name);
	printf("\t}\n");


	/* footer */
	printf("\n\tif(1 == precede_by_comma_local) {\n");
	printf("\t\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,\"]\");\n");
	printf("\t\t*precede_by_comma = 1;\n");
	printf("\t}\n");
	printf("\telse {\n");
	printf("\t\t*post_data_temp_ptr = post_data_temp_ptr_in;\n");
	printf("\t\t**post_data_temp_ptr = '\\0';\n");
	printf("\t}\n");
	printf("}\n\n");
}

void generate_function_header_for_struct(const char * const struct_type_name)
{
	printf("void jout_%s(char ** const post_data_temp_ptr, const char key[], const %s * const value, int * const precede_by_comma) {\n",
		   struct_type_name,
		   struct_type_name);
	printf("\tif(NULL == value) {\n");
	printf("\t\t return;\n");
	printf("\t}\n");
	printf("\tchar * const post_data_temp_ptr_in = *post_data_temp_ptr;\n");
	printf("\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr, \"%%s%%s%%s%%s%%s{\", (1 == *precede_by_comma)?\",\":\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?key:\"\", (NULL != key)?\"\\\"\":\"\", (NULL != key)?\":\":\"\");\n");
	printf("\tint precede_by_comma_local = 0;\n\n");
}

void generate_function_footer_for_struct()
{
	printf("\n\tif(1 == precede_by_comma_local) {\n");
	printf("\t\t(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr, \"}\");\n");
	printf("\t\t*precede_by_comma = 1;\n");
	printf("\t}\n");
	printf("\telse {\n");
	printf("\t\t*post_data_temp_ptr = post_data_temp_ptr_in;\n");
	printf("\t\t**post_data_temp_ptr = '\\0';\n");
	printf("\t}\n");
	printf("}\n\n");
}

void generate_function_add_member_for_struct(const char * const member_type,
											 const char * const member_name,
											 const char * const json_key,
											 const char * const format_specifier)
{
	if('\0' == format_specifier[0]) {
		printf("\tjout_%s(post_data_temp_ptr, \"%s\", &(value->%s), &precede_by_comma_local);\n",
			   member_type,
			   json_key,
			   member_name);
	}
	else {
		printf("\tjout_%s(post_data_temp_ptr, \"%s\", \"%s\", &(value->%s), &precede_by_comma_local);\n",
			   member_type,
			   json_key,
			   format_specifier,
			   member_name);
	}
}

void generate_function_add_pointer_member_for_struct(const char * const member_type,
													 const char * const member_name,
													 const char * const json_key,
													 const char * const format_specifier)
{
	if('\0' == format_specifier[0]) {
		printf("\tjout_%s(post_data_temp_ptr, \"%s\", value->%s, &precede_by_comma_local);\n",
			   member_type,
			   json_key,
			   member_name);
	}
	else {
		printf("\tjout_%s(post_data_temp_ptr, \"%s\", \"%s\", value->%s, &precede_by_comma_local);\n",
			   member_type,
			   json_key,
			   format_specifier,
			   member_name);
	}
}


void generate_function_add_member_unsigned_for_struct(const char * const member_type,
													  const char * const member_name,
													  const char * const json_key)
{
	printf("\tjout_u%s(post_data_temp_ptr, \"%s\", &(value->%s), &precede_by_comma_local);\n",
		   member_type,
		   json_key,
		   member_name);
}

void generate_function_add_pointer_member_unsigned_for_struct(const char * const member_type,
															  const char * const member_name,
															  const char * const json_key)
{
	printf("\tjout_u%s(post_data_temp_ptr, \"%s\", value->%s, &precede_by_comma_local);\n",
		   member_type,
		   json_key,
		   member_name);
}


void generate_function_add_array_member_for_struct(const char * const array_type,
												   const char * const array_name,
												   const int array_size,
												   const char * const json_key,
												   const char * const format_specifier)
{
	if('\0' == format_specifier[0]) {
		printf("\tjout_%s_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
			   array_type,
			   json_key,
			   array_name,
			   array_name,
			   array_size);
	}
	else {
		printf("\tjout_%s_array(post_data_temp_ptr, \"%s\", \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
			   array_type,
			   json_key,
			   format_specifier,
			   array_name,
			   array_name,
			   array_size);
	}
}

void generate_function_add_array_member_unsigned_for_struct(const char * const array_type,
															const char * const array_name,
															const int array_size,
															const char * const json_key)
{
	printf("\tjout_u%s_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
		   array_type,
		   json_key,
		   array_name,
		   array_name,
		   array_size);
}

void generate_function_add_string_member_for_struct(const char * const string_member_name,
													const unsigned int string_member_size,
													const char * const json_key)
{
	printf("\tjout_string(post_data_temp_ptr, \"%s\", value->%s, %u, &precede_by_comma_local);\n",
		   json_key,
		   string_member_name,
		   string_member_size);
}

void generate_function_add_string_array_member_for_struct(const char * const string_array_member_name,
														  const unsigned int max_strings,
														  const unsigned int string_size,
														  const char * const json_key)
{
	printf("\tjout_string_array(post_data_temp_ptr, \"%s\", %u, %u, value->%s, value->%s_count, &precede_by_comma_local);\n",
		   json_key,
		   max_strings,
		   string_size,
		   string_array_member_name,
		   string_array_member_name);
}


void generate_function_add_boolean_member_for_struct(const char * const member_name,
													 const char * const json_key)
{
	printf("\tjout_boolean(post_data_temp_ptr, \"%s\", &(value->%s), &precede_by_comma_local);\n",
		   json_key,
		   member_name);
}

void generate_function_add_boolean_pointer_member_for_struct(const char * const member_name,
															 const char * const json_key)
{
	printf("\tjout_boolean(post_data_temp_ptr, \"%s\", value->%s, &precede_by_comma_local);\n",
		   json_key,
		   member_name);
}

void generate_function_add_boolean_array_member_for_struct(const char * const array_name,
														   const int array_size,
														   const char * const json_key)
{
	printf("\tjout_boolean_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
		   json_key,
		   array_name,
		   array_name,
		   array_size);
}

void generate_function_add_boolean_pointer_array_member_for_struct(const char * const pointer_array_name,
																   const int pointer_array_size,
																   const char * const json_key)
{
	printf("\tjout_boolean_pointer_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
		   json_key,
		   pointer_array_name,
		   pointer_array_name,
		   pointer_array_size);
}

void generate_function_add_pointer_array_member_for_struct(const char * const pointer_array_type,
														   const char * const pointer_array_name,
														   const int pointer_array_size,
														   const char * const json_key,
														   const char * const format_specifier)
{
	if('\0' == format_specifier[0]) {
		printf("\tjout_%s_pointer_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
			   pointer_array_type,
			   json_key,
			   pointer_array_name,
			   pointer_array_name,
			   pointer_array_size);
	}
	else {
		printf("\tjout_%s_pointer_array(post_data_temp_ptr, \"%s\", \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
			   pointer_array_type,
			   json_key,
			   format_specifier,
			   pointer_array_name,
			   pointer_array_name,
			   pointer_array_size);
	}
}

void generate_function_add_pointer_array_member_unsigned_for_struct(const char * const pointer_array_type,
																	const char * const pointer_array_name,
																	const int pointer_array_size,
																	const char * const json_key)
{

	printf("\tjout_u%s_pointer_array(post_data_temp_ptr, \"%s\", value->%s, value->%s_count, %d, &precede_by_comma_local);\n",
		   pointer_array_type,
		   json_key,
		   pointer_array_name,
		   pointer_array_name,
		   pointer_array_size);
}


void generate_function_add_string_pointer_array_member_for_struct(const char * const string_array_member_name,
																  const unsigned int max_strings,
																  const unsigned int string_size,
																  const char * const json_key)
{
	printf("\tjout_string_pointer_array(post_data_temp_ptr, \"%s\", %u, %u, value->%s, value->%s_count, &precede_by_comma_local);\n",
		   json_key,
		   max_strings,
		   string_size,
		   string_array_member_name,
		   string_array_member_name);
}
