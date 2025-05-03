#include "main.h"

static	char	*validate_file(char *filename, char *operation) 
{
	int		fd = 0;
	char	*buffer = NULL;

	// OPENING FILE
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("File not found");
	
	// CHECKING IN CASE OF DECODE
	if (strcmp(operation, "encode") == 0) {
		
		// DEFINING BUFFER
		buffer = safe_calloc(1,BUFFER_SIZE);

		// IF CANT READ FILE
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			exit_error("Error while reading file");
		
		// IF THERE IS ANYTHING ELSE THAN 0 OR 1 OR NEWLINE OR IS EMPTY
		int i = 0;
		for (i = 0; buffer[i]; i++) {
			if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '\n')
				exit_error("File must contain only 0 and 1");
		}
		if (i == 0)
			exit_error("File is empty");
		close(fd);

		// RETURNING BUFFER
		return (buffer);
	}
}

void	parse(char **argv) 
{
	t_screen	*screen = NULL;
	char		*operation = argv[1];
	char		*buffer = NULL;

	// IF OPERATION IS NOT ENCODE OR DECODE
	if (strcmp(operation,"decode") && strcmp(operation,"encode"))
		exit_error("Operation name must [decode] or [encode]");
	
	// VALIDATING FILE DEPENDS ON OPERATION
	buffer = validate_file(argv[2], operation);

	screen = safe_malloc(sizeof(t_screen));
	screen->operation = operation;

	// IN CASE OF DECODE WEE NEED TO HAVE IMAGE TO PARSE
	if (strcmp(operation, "decode") == 0) {
		screen->image_to_parse = argv[2];
		decode(screen);
		exit(0);
	}
	
	screen->width = 800;
	screen->height = 600;
	screen->bin_data = buffer;

	// INITIALIZING MLX
	init_screen(screen);
	
	// IF OPERATION IS ENCODE
	if (strcmp(operation, "encode") == 0) 
		encode(screen);
	else
		decode(screen);
	mlx_loop(screen->mlx);
}