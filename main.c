/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 20:02:15 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/23 16:05:24 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	int len;
	int i = 0;
	char *line;
	line = malloc(100);

	fd = open("sample3", O_RDONLY, BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);	
	}
		ft_strdel(&line);
}