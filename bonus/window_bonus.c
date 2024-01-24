/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:37:55 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/24 17:14:26 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_window_size(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
			data->win_width = (ft_strlen(line) - 1) * 32;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->win_height = i * 32;
	close(fd);
}

void	fill_win(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			mlx_put_image_to_window(data->mlx, data->win, \
				data->land_img, j * 32, i * 32);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	fill_gnl(t_data *data, char *line, int i, int j)
{
	if (line[j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->border_img, j * 32, i * 32);
	if (line[j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->coin_img, j * 32, i * 32);
	if (line[j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->door_closed_img, j * 32, i * 32);
	if (line[j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->player_img, j * 32, i * 32);
	if (line[j] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->enemy_img, j * 32, i * 32);
}

void	fill_border(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			fill_gnl(data, line, i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	bordering(t_data *data)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(data->relative_path, O_RDONLY);
	line = get_next_line(fd);
	while (line[j] != '\n')
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->border_img, j * 32, 0);
		j++;
	}
	free(line);
	close(fd);
}
