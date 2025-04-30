#include "main.h"

void	*safe_malloc(size_t size) 
{
	void	*ptr = malloc(size);
	if (!ptr) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	return ptr;
}

void	*safe_calloc(size_t count, size_t size) 
{
	void	*ptr = calloc(count, size);
	if (!ptr) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	return ptr;
}

void	exit_error(const char *err) {
	fprintf(stderr,"%s",err);
	exit(1);
}