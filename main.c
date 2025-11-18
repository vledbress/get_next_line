#include "get_next_line.h"
#include <fcntl.h>


int main()
{
	int fd = open("test", O_RDONLY);
	get_next_line(fd);
	close(fd);
}