/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:44 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/20 16:45:26 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(t_data *data, char *av)
{
	int		fd;
	char	*line;
	int		j;
	int		c;

	c = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == 'C')
				c++;
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (c == 0)
		(write(2, "Error No Collectables\n", 23), exit(0));
	data->coin = c;
}

int	elements1_gnl(t_data *data, char *line, int fd)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == 'E')
			{
				data->door_x = j;
				data->door_y = i;
				e++;
			}
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (e);
}

void	check_elements2(t_data *data, char *av)
{
	int		fd;
	char	*line;
	int		e;

	e = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	e = elements1_gnl(data, line, fd);
	close(fd);
	if (e != 1)
		(write(2, "Error Exit\n", 12), exit(0));
}

int	elements3_gnl(t_data *data, char *line, int fd)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				p++;
			}
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (p);
}

void	check_elements3(t_data *data, char *av)
{
	int		fd;
	char	*line;
	int		p;

	p = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	p = elements3_gnl(data, line, fd);
	close(fd);
	if (p != 1)
		(write(2, "Error Player\n", 14), exit(0));
}
