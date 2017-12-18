/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 19:59:16 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 20:40:47 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t search_nl(char *str)
{
	size_t i;

	i = 0;
	if (str[0] == '\n')
		return 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return i + 1;
}

int get_next_line(const int fd, char **line)
{
	static char *temp = "";
	size_t len;
	char *end;
	int size;

	while ((!(ft_strchr(temp, '\n'))))
	{
		end = ft_strnew(BUFF_SIZE);
		size = read(fd, end, BUFF_SIZE);
		if (size != BUFF_SIZE)
		{
			end = ft_strsub_free(end, 0, size);
			temp = ft_strjoin_free(temp, end, 3);
			break;
		}
		temp = ft_strjoin_free(temp, end, 2);
	}
	len = search_nl(temp);
	*line = ft_strsub(temp, 0, len);
	temp = ft_strsub_free(temp, len, ft_strlen(temp));
	len = ft_strlen(*line);
	if ((*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	return (len);
}
