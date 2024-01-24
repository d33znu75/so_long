/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:53:42 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/24 23:28:22 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	data->map = malloc(sizeof(char *) * ((data->win_height / 32) + 1));
	if (!data->map)
		(write(2, "Error\n", 6), exit(0));
	while (line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void	copy_map(t_data *data)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	data->map_copy = malloc(sizeof(char *) * ((data->win_height / 32) + 1));
	if (!data->map_copy)
		(write(2, "Error\n", 6), exit(0));
	fd = open(data->relative_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->map_copy[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map_copy[i] = NULL;
	close(fd);
}

void	data_image2(t_data *data, int img_width, int img_height)
{
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./xpm/player.xpm", \
		&img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->player_right_img = mlx_xpm_file_to_image(data->mlx, \
		"./xpm/player_right.xpm", &img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->door_closed_img = mlx_xpm_file_to_image(data->mlx, \
		"./xpm/door_closed.xpm", &img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->door_open_img = mlx_xpm_file_to_image(data->mlx, \
		"./xpm/door_open.xpm", &img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "./xpm/enemy.xpm", \
		&img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
}

void	data_image(t_data *data)
{
	int	img_width;
	int	img_height;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_width, \
		data->win_height, "so_long");
	data->border_img = mlx_xpm_file_to_image(data->mlx, "./xpm/border.xpm", \
		&img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->land_img = mlx_xpm_file_to_image(data->mlx, "./xpm/land.xpm", \
		&img_width, &img_height);
	if (img_height != 32 && img_width != 32)
		(write(2, "Error image size\n", 18), exit(0));
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "./xpm/coin.xpm", \
		&img_width, &img_height);
	data_image2(data, img_width, img_height);
}

void	free_d(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	i = 0;
	while (data->map_copy[i])
	{
		free(data->map_copy[i]);
		i++;
	}
}
