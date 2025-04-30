# include "main.h"

int main(int argc, char **argv) 
{
	if (argc >= 3) {
		parse(argv);
	}
	else
		exit_error("Few arguments: ./solver-ed [operation] [filename]");
	return 0;
}