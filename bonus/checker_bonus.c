/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:53:56 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/24 15:53:18 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_border_2(int i, char *av)
{
	int		x;
	int		j;
	int		fd;
	char	*line;

	x = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (x == (i - 1))
		{
			j = 0;
			while (line[j] != '\0')
			{
				if (line[j] != '1')
					(write(2, "Error Map Borders\n", 19), exit(0));
				j++;
			}
		}
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
}

void	check_border_3(char *av)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(av, O_RDONLY);
	x = 0;
	line = get_next_line(fd);
	if (line == NULL)
		(write(2, "Error Empty Map\n", 17), exit(0));
	while (line)
	{
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			(write(2, "Error Map Borders\n", 19), exit(0));
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
}

size_t	ft_strlen2(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (str[i - 1] == '\n')
		return (i - 1);
	return (i);
}

void	check_shape(char *av)
{
	int		fd;
	char	*line;
	size_t	line_len;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	line_len = ft_strlen2(line);
	while (line)
	{
		if (ft_strlen2(line) != line_len)
			(write(2, "Error Map Shape\n", 17), exit(0));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_border(char *av)
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
		if (i == 0)
		{
			j = 0;
			while (line[j])
			{
				if (line[j] != '1' && line[j] != '\n')
					(write(2, "Error Map Borders\n", 19), exit(0));
				j++;
			}
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	(close(fd), check_border_2(i, av), check_border_3(av));
}
