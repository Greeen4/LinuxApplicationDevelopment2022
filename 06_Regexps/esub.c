#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>
#include <string.h>


char* help_string = "Use like sed";

void error(int status, regex_t *r)
{
	char str[128];
	regerror(status, r, str, 128);
	fprintf(stderr, "%s\n", str);

	regfree(r);
	exit(1);
}


int check_args(int argc, char **argv) 
{
	if (argc != 4){
		printf("%s\n", help_string);
		return 1;
	}
	return 0;
}

void do_sub(char* substitution, char* string, regmatch_t* pm) 
{

	int length = strlen(substitution);
	char* processed_subst = (char*) malloc(length * sizeof(char));
	int i, slash = 0;
	char *p, *p_proc;

	p_proc = processed_subst;
	for (p = substitution; *p; p++) {
		if (*p == '\\') {
			if (!slash) {
				*p_proc = *p;
				p_proc++;
			}
			slash = 1 - slash;
		}
		else {
			*p_proc = *p;
			p_proc++;
			slash = 0;
		}
	}
	*p_proc = '\0';

	if (slash) {
		fprintf(stderr, "Unclosed sequence with \\ "
				"symbol in substitution string\n");
		exit(1);
	}

	slash = 0;
	for (p = processed_subst; *p; p++) {
		if (*p == '\\') slash = 1 - slash;
		else if (isdigit(*p) && slash) {
			int pocket_num = *p - '0';
			int start_point = (int) pm[pocket_num].rm_so;
			if (start_point < 0) {
				fprintf(stderr, "Not enough pockets in "
						"regular expression for pocket %d value\n",
						pocket_num);

				free(processed_subst);
				exit(1);
			}
			slash = 0;
		}
		else slash = 0;
	}

	int start = (int) pm[0].rm_so;
	for (i = 0; i < start; ++i) putchar(string[i]);
	slash = 0;
	for (p = processed_subst; *p; p++) {
		if (*p == '\\') {
			if (slash) putchar(*p);
			slash = 1 - slash;
		}
		else if (isdigit(*p)) {
			int pocket_num = *p - '0';
			int start_point = (int) pm[pocket_num].rm_so;
			int end_point = (int) pm[pocket_num].rm_eo;
			for (i = start_point; i < end_point; ++i) putchar(string[i]);
			slash = 0;
		}
		else {
			putchar(*p);
			slash = 0;
		}
	}
	printf("%s\n", string + pm[0].rm_eo);

	free(processed_subst);

}


void seddd(int argc, char **argv)
{
	check_args(argc, argv);

	char* reg = argv[1], *subs = argv[2], *string = argv[3];

	regex_t r;
	int status = regcomp(&r, reg, REG_EXTENDED);

	if (status) error(status, &r);

	regmatch_t p[10];

	status = regexec(&r, string, 10, p, 0);

	if (!status){
		do_sub(subs, string, p);	
		regfree(&r);
	} else if (status == REG_NOMATCH){
		printf("%s\n", string);
	}else error(status, &p);

}


int main(int argc, char **argv) 
{
	seddd(argc, argv);

	return 0;
}

