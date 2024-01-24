/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:14:48 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/22 23:13:12 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

//---> data structure <---//

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*relative_path;
	int		win_width;
	int		win_height;
	void	*land_img;
	void	*coin_img;
	void	*border_img;
	void	*player_img;
	void	*door_closed_img;
	void	*door_open_img;
	int		coin;
	int		player_x;
	int		player_y;
	char	**map;
	int		door_x;
	int		door_y;
	char	**map_copy;
	int		moves;
}	t_data;

//---> get_next_line <---//

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		check_line(char *str);
void	ft_putnbr_fd(int n, int fd);

//---> checkers <---//

void	check_border_2(int i, char *av);
void	check_border_3(char *av);
void	check_shape(char *av);
void	check_border(char *av);
void	check_map_name(char *av);
void	check_1(char *av);
void	check_elements(t_data *data, char *av);
void	check_elements2(t_data *data, char *av);
void	check_elements3(t_data *data, char *av);

//---> Key moves <---//

void	handle_press(int keycode, t_data *data);

//---> path <---//

void	check_path(t_data *data);

//---> window <---//

void	get_window_size(t_data *data, char *file);
void	fill_win(t_data *data, char *file);
void	fill_border(t_data *data, char *file);

//---> map <---//

void	copy_map(t_data *data);
void	fill_map(t_data *data, char *file);
void	data_image(t_data *data);
void	free_d(t_data *data);

//---> init <---//

void	checkers(t_data *data, char *av);
int		endgame(t_data *data);
int		key_hook(int keycode, t_data *data);

#endif