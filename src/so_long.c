/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:34 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/24 23:24:51 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		(write(1, "Error Arguments\n", 17), exit(0));
	data.relative_path = av[1];
	checkers(&data, av[1]);
	get_window_size(&data, av[1]);
	fill_map(&data, av[1]);
	copy_map(&data);
	check_path(&data);
	data_image(&data);
	if (!data.border_img || !data.land_img || !data.coin_img || \
		!data.player_img || !data.door_closed_img || !data.door_open_img)
		(write(2, "Error Images\n", 13), free_d(&data), exit(0));
	fill_win(&data, av[1]);
	fill_border(&data, av[1]);
	data.moves = 1;
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, endgame, &data);
	mlx_loop(data.mlx);
}
