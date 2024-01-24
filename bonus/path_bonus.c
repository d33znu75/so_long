/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:24 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/22 23:25:42 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	loop(t_data *data, int i, int j, int loop_stop)
{
	if (data->map_copy[i][j + 1] != '1' && \
		data->map_copy[i][j + 1] != 'P' && data->map_copy[i][j + 1] != 'X')
	{
		data->map_copy[i][j + 1] = 'P';
		loop_stop = 1;
	}
	if (data->map_copy[i][j - 1] != '1' && \
		data->map_copy[i][j - 1] != 'P' && data->map_copy[i][j - 1] != 'X')
	{
		data->map_copy[i][j - 1] = 'P';
		loop_stop = 1;
	}
	if (data->map_copy[i + 1][j] != '1' && \
		data->map_copy[i + 1][j] != 'P' && data->map_copy[i + 1][j] != 'X')
	{
		data->map_copy[i + 1][j] = 'P';
		loop_stop = 1;
	}
	if (data->map_copy[i - 1][j] != '1' && \
		data->map_copy[i - 1][j] != 'P' && data->map_copy[i - 1][j] != 'X')
	{
		data->map_copy[i - 1][j] = 'P';
		loop_stop = 1;
	}
	return (loop_stop);
}

int	check_path_1(t_data *data)
{
	int	i;
	int	j;
	int	loop_stop;

	i = 0;
	loop_stop = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == 'P')
			{
				loop_stop = loop(data, i, j, loop_stop);
			}
			j++;
		}
		i++;
	}
	return (loop_stop);
}

void	check_path_2(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == 'C' || data->map_copy[i][j] == 'E')
				(write(2, "Error Map Path\n", 16), free_d(data), exit(0));
			j++;
		}
		i++;
	}
}

void	check_path(t_data *data)
{
	int	i;

	i = 0;
	while (check_path_1(data) == 1)
	{
		i++;
	}
	check_path_2(data);
}
