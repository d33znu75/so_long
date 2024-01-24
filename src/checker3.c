/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:42:43 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/20 15:44:19 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] != 'r' || av[i - 2] != 'e' || \
		av[i - 3] != 'b' || av[i - 4] != '.')
	{
		write(2, "Error Map Name\n", 15);
		exit(0);
	}
}

void	check_1(char *av)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] != '1' && line[j] != '0' && line[j] != 'C' && \
				line[j] != 'E' && line[j] != 'P' && line[j] != '\n')
				(write(2, "Error Extra Element\n", 21), exit(0));
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
