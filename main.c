/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 20:02:15 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:19:38 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	int fd2;
	int len;
	int i = 0;
	char *line;
	line = malloc(100);

	fd2 = open("sample", O_RDONLY, BUFF_SIZE);
	fd = open("one_big_fat_line.txt", O_RDONLY, BUFF_SIZE);

	while (get_next_line(fd2, &line))
	{
		ft_putendl(line);
	}
	ft_strdel(&line);
}