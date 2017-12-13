#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define BUF_SIZE 1000

int get_next_line(const int fd, char **line)
{
	int j;
	static char *res;
	static int l = 0;
	int ret;
	int size;

	ret = 0;
	j = 0;
	if (!(l))
		res = malloc(1000);
	while (size = read(fd, *line, BUF_SIZE))
	{
		while (l < size)
			res[j++] = (*line)[l++];
			l = 0;
	}
	while (res[l] == '\n')
		l++;
	while (res[l] != '\n' && res[l] != '\0')
	{
		putchar(res[l++]);
		ret = 1;
	}
	return ret;
}

int main()
{
	int fd;
	int len;
	char **line;
	line = malloc(100);
	line[0] = malloc(1000);

	fd = open("sample", O_RDONLY, BUF_SIZE);

	while (get_next_line(fd, line))
		;
	free(line);
	free(line[0]);
}