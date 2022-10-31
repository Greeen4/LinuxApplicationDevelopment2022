#include <stdio.h>
#include <stdlib.h>


char* help_string = "Usage:\n"
			   "- input 1 arg N to get sequence [0, 1, ... N-1]\n"
			   "- input 2 arg M, N to get sequence [M, M+1, ... N-1]\n"
			   "- input 3 arg M, N, S to get sequence "
			   "[M, M+S,... N-1]\n";


typedef struct {
	int begin;
	int end;
	int step;
} range;


void parse_arg(int argc, char** argv, int* begin, int* end, int* step)
{
	if (argc == 1) {printf("%s", help_string);}

	if (argc == 2){
		*end = atoi(argv[1]);
		*begin = 0;
		*step = 1;
	}

	if (argc == 3){
		*end = atoi(argv[2]);
		*begin = atoi(argv[1]);
		*step = 1;
	}

	if (argc == 4){
		*end = atoi(argv[2]);
		*begin = atoi(argv[1]);
		*step = atoi(argv[3]);
	}
		
}


void print_range(range *I)
{
	int i = 0;
	int begin = I-> begin;

	for (i = begin; i < I->end; i = i + I->step)
	{
		printf("%d\n", i);
	}
}

int main(int argc, char** argv)
{
	range I;
	parse_arg(argc, argv, &I.begin, &I.end, &I.step);
	print_range(&I);

	return 0;
}
