#include <sys/types.h>
#include <fcntl.h>
#include "libft/libft.h"

#define BUF_SIZE 4

size_t search_nl(char *str)
{
	size_t i;

	i = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return i;
}

int get_next_line(const int fd, char **line)
{
	static char *temp = NULL;
	size_t len;
	char *end;
	int size = BUF_SIZE;

	end = ft_memalloc(BUF_SIZE + 1);
	if (!temp)
		temp = ft_memalloc(BUF_SIZE + 1);
	while ((!(ft_strchr(temp, '\n'))))
	{
		size = read(fd, end, BUF_SIZE);
		if (size != BUF_SIZE)
		{
			end = ft_strndup(end, size);
			temp = ft_strjoin(temp, end);
			break;
		}
		temp = ft_strjoin(temp, end);
	}
	len = search_nl(temp);
	*line = ft_strndup(temp, len);
	temp = ft_strsub(temp, len + 1, ft_strlen(temp) - len);
	ft_strdel(&end);
	return (ft_strlen(*line));
}

int main()
{
	int fd;
	int len;
	int i = 0;
	char *line;
	line = malloc(100);

	fd = open("sample", O_RDONLY, BUF_SIZE);
	while (get_next_line(fd, &line))
	{
		printf("ligne %d : %s\n", i++, line);
		
	}
		ft_strdel(&line);
}