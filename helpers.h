#include <stdio.h>
#include <string.h>

void jout_int(char ** const post_data_temp_ptr,
			  const char key[],
			  const int * const value,
			  int * const precede_by_comma)
{
	if(NULL == value) {
		return;
	}
	const char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s%d",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"",
									 *value);

	if(post_data_temp_ptr_in != *post_data_temp_ptr) {
		*precede_by_comma = 1;
	}
}

void jout_uint(char ** const post_data_temp_ptr,
			   const char key[],
			   const unsigned int * const value,
			   int * const precede_by_comma)
{
	if(NULL == value) {
		return;
	}
	const char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s%u",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"",
									 *value);

	if(post_data_temp_ptr_in != *post_data_temp_ptr) {
		*precede_by_comma = 1;
	}
}

void jout_int_array(char ** const post_data_temp_ptr,
					const char key[],
					const int value_array[],
					const unsigned int array_count,
					const unsigned int array_size,
					int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < array_count) && (i < array_size)); i++) {
		jout_int(post_data_temp_ptr,
				 NULL,
				 &value_array[i],
				 &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_int_pointer_array(char ** const post_data_temp_ptr,
							const char key[],
							int * const * const pointer_array,
							const unsigned int pointer_array_count,
							const unsigned int pointer_array_size,
							int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < pointer_array_count) && (i < pointer_array_size)); i++) {
		jout_int(post_data_temp_ptr,
				 NULL,
				 pointer_array[i],
				 &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_uint_pointer_array(char ** const post_data_temp_ptr,
							 const char key[],
							 unsigned int * const * const pointer_array,
							 const unsigned int pointer_array_count,
							 const unsigned int pointer_array_size,
							 int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < pointer_array_count) && (i < pointer_array_size)); i++) {
		jout_uint(post_data_temp_ptr,
				  NULL,
				  pointer_array[i],
				  &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_uint_array(char ** const post_data_temp_ptr,
					 const char key[],
					 const unsigned int value_array[],
					 const unsigned int array_count,
					 const unsigned int array_size,
					 int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < array_count) && (i < array_size)); i++) {
		jout_uint(post_data_temp_ptr,
				  NULL,
				  &value_array[i],
				  &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}


void jout_float(char ** const post_data_temp_ptr,
				const char key[],
				const char value_format_specifier[],
				const float * const value,
				int * const precede_by_comma)
{
	if(NULL == value) {
		return;
	}
	const char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	char format_specifier[100] = "%s%s%s%s%s";
	strcat(format_specifier,
		   value_format_specifier);

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 format_specifier,
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"",
									 *value);

	if(post_data_temp_ptr_in != *post_data_temp_ptr) {
		*precede_by_comma = 1;
	}
}

void jout_float_array(char ** const post_data_temp_ptr,
					  const char key[],
					  const char value_format_specifier[],
					  const float value_array[],
					  const unsigned int array_count,
					  const unsigned int array_size,
					  int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < array_count) && (i < array_size)); i++) {
		jout_float(post_data_temp_ptr,
				   NULL,
				   value_format_specifier,
				   &value_array[i],
				   &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_float_pointer_array(char ** const post_data_temp_ptr,
							  const char key[],
							  const char value_format_specifier[],
							  float * const * const pointer_array,
							  const unsigned int pointer_array_count,
							  const unsigned int pointer_array_size,
							  int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < pointer_array_count) && (i < pointer_array_size)); i++) {
		jout_float(post_data_temp_ptr,
				   NULL,
				   value_format_specifier,
				   pointer_array[i],
				   &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_string(char ** const post_data_temp_ptr,
				  const char key[],
				  const char string_value[],
				  const unsigned int string_size,
				  int * const precede_by_comma)
{
	(void) string_size;
	if(NULL == string_value ||
	   '\0' == string_value[0]) {
		return;
	}
	const char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s\"",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	unsigned int chars_parsed_count = 0;
	const char *ptr = string_value;
	while((chars_parsed_count < (string_size - 1)) &&
		  '\0' != *ptr ) {
		char escape_char = '\0';
		switch(*ptr) {
			case '\"':
				escape_char = '\"';
				break;
			case '\\':
				escape_char = '\\';
				break;
			case '/': /* 0x2f */
				//escape_char = '/';
				break;
			case '\b':
				escape_char = 'b';
				break;
			case '\f':
				escape_char = 'f';
				break;
			case '\n':
				escape_char = 'n';
				break;
			case '\r':
				escape_char = 'r';
				break;
			case '\t':
				escape_char = 't';
				break;
		}
		if('\0' == escape_char) {
			if((*ptr) >= 0x20) {
				(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
												 "%c",
												 *ptr);
			}
			else {
				(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
												 "\\u00%c%c",
												 "0123456789abcdef"[(((*ptr)>>4) & 0xf)],
												 "0123456789abcdef"[((*ptr) & 0xf)]);
			}
		}
		else{
			(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
											 "\\%c",
											 escape_char); // add escape charcter
		}
		chars_parsed_count++;
		ptr++;
	}
	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "\"");

	if(post_data_temp_ptr_in != *post_data_temp_ptr) {
		*precede_by_comma = 1;
	}
}

void jout_string_array(char ** const post_data_temp_ptr,
					   const char key[],
					   const unsigned int max_strings,
					   const unsigned int string_size,
					   const char string_value_array[][string_size],
					   const unsigned int string_count,
					   int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < string_count) && (i < max_strings)); i++) {
		jout_string(post_data_temp_ptr,
					NULL,
					&string_value_array[i][0],
					string_size,
					&precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}

void jout_boolean(char ** const post_data_temp_ptr,
				  const char key[],
				  const int * const value,
				  int * const precede_by_comma)
{
	if(NULL == value) {
		return;
	}
	const char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s%s",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"",
									 (*value)?"true":"false");

	if(post_data_temp_ptr_in != *post_data_temp_ptr) {
		*precede_by_comma = 1;
	}
}

void jout_boolean_array(char ** const post_data_temp_ptr,
						const char key[],
						const int value_array[],
						const unsigned int array_count,
						const unsigned int array_size,
						int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < array_count) && (i < array_size)); i++) {
		jout_boolean(post_data_temp_ptr,
					 NULL,
					 &value_array[i],
					 &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}



void jout_boolean_pointer_array(char ** const post_data_temp_ptr,
								const char key[],
								int * const * const pointer_array,
								const unsigned int pointer_array_count,
								const unsigned int pointer_array_size,
								int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < pointer_array_count) && (i < pointer_array_size)); i++) {
		jout_boolean(post_data_temp_ptr,
					 NULL,
					 pointer_array[i],
					 &precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}


void jout_string_pointer_array(char ** const post_data_temp_ptr,
							   const char key[],
							   const unsigned int max_strings,
							   const unsigned int string_size,
							   char * const * const string_pointer_array,
							   const unsigned int string_pointer_array_count,
							   int * const precede_by_comma)
{
	char * const post_data_temp_ptr_in = *post_data_temp_ptr;

	(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
									 "%s%s%s%s%s[",
									 (1 == *precede_by_comma)?",":"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?key:"",
									 (NULL != key)?"\"":"",
									 (NULL != key)?":":"");

	int precede_by_comma_local = 0;
	for(unsigned int i=0;((i < string_pointer_array_count) && (i < max_strings)); i++) {
		jout_string(post_data_temp_ptr,
					NULL,
					string_pointer_array[i],
					string_size,
					&precede_by_comma_local);
	}

	if(1 == precede_by_comma_local) {
		(*post_data_temp_ptr) += sprintf(*post_data_temp_ptr,
										 "]");
		*precede_by_comma = 1;
	}
	else {
		*post_data_temp_ptr = post_data_temp_ptr_in;
		**post_data_temp_ptr = '\0';
	}
}
