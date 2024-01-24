/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:54:20 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/21 21:09:09 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(int keycode, t_data *data)
{
	if (keycode == 13 && data->map[data->player_y - 1][data->player_x] != '1')
	{
		if (data->map[data->player_y - 1][data->player_x] == 'C')
		{
			data->coin--;
			data->map[data->player_y - 1][data->player_x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, (data->player_y - 1) * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->door_closed_img, \
			data->door_x * 32, data->door_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, \
			data->player_x * 32, (data->player_y - 1) * 32);
		data->player_y--;
		write(1, "You did ", 9);
		ft_putnbr_fd(data->moves, 1);
		write(1, " moves\n", 8);
		data->moves++;
	}
}

void	a_key(int keycode, t_data *data)
{
	if (keycode == 0 && data->map[data->player_y][data->player_x - 1] != '1')
	{
		if (data->map[data->player_y][data->player_x - 1] == 'C')
		{
			data->coin--;
			data->map[data->player_y][data->player_x - 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			(data->player_x - 1) * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->door_closed_img, \
			data->door_x * 32, data->door_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, \
			(data->player_x - 1) * 32, data->player_y * 32);
		data->player_x--;
		write(1, "You did ", 9);
		ft_putnbr_fd(data->moves, 1);
		write(1, " moves\n", 8);
		data->moves++;
	}
}

void	s_key(int keycode, t_data *data)
{
	if (keycode == 1 && data->map[data->player_y + 1][data->player_x] != '1')
	{
		if (data->map[data->player_y + 1][data->player_x] == 'C')
		{
			data->coin--;
			data->map[data->player_y + 1][data->player_x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, (data->player_y + 1) * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->door_closed_img, \
			data->door_x * 32, data->door_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, \
			data->player_x * 32, (data->player_y + 1) * 32);
		data->player_y++;
		write(1, "You did ", 9);
		ft_putnbr_fd(data->moves, 1);
		write(1, " moves\n", 8);
		data->moves++;
	}
}

void	d_key(int keycode, t_data *data)
{
	if (keycode == 2 && data->map[data->player_y][data->player_x + 1] != '1')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'C')
		{
			data->coin--;
			data->map[data->player_y][data->player_x + 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			data->player_x * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->land_img, \
			(data->player_x + 1) * 32, data->player_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->door_closed_img, \
			data->door_x * 32, data->door_y * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, \
			(data->player_x + 1) * 32, data->player_y * 32);
		data->player_x++;
		write(1, "You did ", 9);
		ft_putnbr_fd(data->moves, 1);
		write(1, " moves\n", 8);
		data->moves++;
	}
}

void	handle_press(int keycode, t_data *data)
{
	w_key(keycode, data);
	a_key(keycode, data);
	s_key(keycode, data);
	d_key(keycode, data);
	if (data->coin == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->door_open_img, \
			data->door_x * 32, data->door_y * 32);
		data->map[data->door_y][data->door_x] = 'X';
		if (data->map[data->player_y][data->player_x] == 'X')
			(write(1, "You Win\n", 8), exit(0));
	}
}
