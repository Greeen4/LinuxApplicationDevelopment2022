#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SIZE 1024


int arg_parse(int argc)
{
	if (argc != 3) return 1;
	
	return 0;
}



int move(char** argv)
{

	FILE* infile = fopen(argv[1], "r");
	if (!infile){
		perror("Error: Can't open infile");
		printf("%d", errno);
		return errno;
	}

	FILE* outfile = fopen(argv[2], "wb");

	if (!outfile){
		perror("Error: Can't open outfile");
		int	first_errno = errno;
		fclose(infile);
		return first_errno;
	}


	char buf[BUF_SIZE];
	int num_read = 0;

	while(1)
	{
		if ((num_read = fread(buf, 1, sizeof(buf), infile)) != sizeof(buf) &&
			!feof(infile))
		{
			perror("Error: read file");
			return errno;
		}

		if (fwrite(buf, 1, num_read, outfile) != num_read){
			perror("Error: write in outfile");
			return errno;
		}

		if (feof(infile)) break;
	}

	if (fclose(outfile)){
		int first_errno = errno;
		perror("Error: close outfile");
		remove(argv[2]);
		fclose(infile);
		return first_errno;
	}

	if (fclose(infile)){
		perror("Error: close infile");
		return errno;
	}

	if (remove(argv[1])){
		perror("Error: delete infile");
		remove(argv[2]);
		return errno;
	}

	return 0;
}


int main(int argc, char** argv)
{
	if (arg_parse(argc)) return 0;

	int ret = move(argv);

	if (errno && errno != ret) perror("Error: undefined error in move function");

	return ret;

}
