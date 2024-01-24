/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:41 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/22 23:26:38 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checkers(t_data *data, char *av)
{
	int	fd;

	check_map_name(av);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		(write(2, "Map Not Found\n", 15), exit(0));
	check_border(av);
	check_shape(av);
	check_1(av);
	check_elements(data, av);
	check_elements2(data, av);
	check_elements3(data, av);
}

int	endgame(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_d(data);
	write(1, "GoodBye\n", 9);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode != 53 && keycode != 13 && keycode != 0 && keycode != 1 && \
		keycode != 2)
		return (0);
	else if (keycode == 53)
		endgame(data);
	else
		handle_press(keycode, data);
	return (0);
}
