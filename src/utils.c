# include "main.h"


void	*safe_malloc(size_t size) 
{
	void	*ptr = malloc(size);
	if (!ptr) {
		exit_error("Memory allocation failed\n");
	}
	return ptr;
}

void	*safe_calloc(size_t count, size_t size) 
{
	void	*ptr = calloc(count, size);
	if (!ptr) {
		exit_error("Memory allocation failed\n");
	}
	return ptr;
}

void	safe_free(void *ptr) 
{
	if (ptr) {
		free(ptr);
	}
}


void	exit_error(const char *err) {
	fprintf(stderr,"%s",err);
	exit(1);
}

int	chunks_total(char *data) 
{
	int c = 0;
	for (int i = 0; i < strlen(data); i++)
	{
		if (data[i] != '\n')
			c++;
	}
	return c;
}