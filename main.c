/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 20:02:15 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 20:32:12 by mel-akio    ###    #+. /#+    ###.fr     */
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

	fd = open("sample", O_RDONLY, BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		ft_putnbr(++i);
		ft_putchar(' ');
		ft_putendl(line);	
	}
		ft_strdel(&line);
}