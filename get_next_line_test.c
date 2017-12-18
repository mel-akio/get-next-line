/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_test.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 11:40:33 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 20:10:45 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 10000

typedef struct	s_mfd
{
	char		*res;
	int			l;
} 				t_mfd;

int get_next_line(const int fd, char **line)
{
	int j;
	static t_mfd multi_fd;
	int ret;

	ret = 0;
	j = 0;
	if (!(multi_fd.l))
		multi_fd.res = malloc(BUF_SIZE + 1);
	while (read(fd, *line, BUF_SIZE))
	{
		if (multi_fd.l < ft_strlen(*line))
			multi_fd.res = ft_strjoin(multi_fd.res, *line);
		multi_fd.l = 0;
	}
	while (multi_fd.res[multi_fd.l] == '\n')
		multi_fd.l++;
	j = multi_fd.l;
	while (multi_fd.res[multi_fd.l] != '\n' && multi_fd.res[multi_fd.l] != '\0')
	{
		multi_fd.l++;
		ret = 1;
	}
	*line = ft_strndup(&multi_fd.res[j], multi_fd.l - j);
	return (ret);
}

int main()
{
	int fd;
	int len;
	char **line;
	int i = 0;
	line = malloc(100);
	line[0] = malloc(1000);

	fd = open("sample2", O_RDONLY, BUF_SIZE);

	while (get_next_line(fd, line))
	{
		printf(" %d %s",i++, *line);
	};
	free(line);
	free(line[0]);
}
