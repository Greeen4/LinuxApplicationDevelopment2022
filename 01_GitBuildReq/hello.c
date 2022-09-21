#include <stdio.h>
#include <stdlib.h>


char *read_line(){
	char c; int max_len = 10;int cur_len = 0;
	char *s = (char*) malloc(max_len * sizeof(char));

	while ((c = getchar()) != EOF && c != '\n'){
		s[cur_len++] = c;

		if (cur_len >= max_len){
			max_len *= 2;
			s = (char*) realloc(s, max_len * sizeof(char));

		}
	}

	s[cur_len] = 0;

	return s;
}


int main()
{
	char *s = read_line();

	printf("Hello, %s!\n", s);
	free(s);

	return 0;
}
