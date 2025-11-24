#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (perror("wrong args\n"), 1);

    int fd = open(argv[1], O_RDONLY);
    char *line;

    if (fd < 0)
    	return (perror("open"), 1);
	
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}
