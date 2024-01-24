/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:54:30 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/16 18:15:21 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_first_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ret = malloc(sizeof(char) * i + (check_line(str) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ret[i] = str[i];
		i++;
	}
	return (ret[i] = '\0', ret);
}

void	remove_first_line(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		buffer[0] = '\0';
	else
	{
		j = 0;
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			j++;
			i++;
		}
		buffer[j] = '\0';
	}
}

char	*ft_gnl(int fd, char *buffer, int readvalue, char *result)
{
	char	*temp;
	char	*final;

	readvalue = 1;
	while (readvalue > 0)
	{
		readvalue = read(fd, buffer, BUFFER_SIZE);
		buffer[readvalue] = '\0';
		temp = ft_strjoin(result, buffer);
		free(result);
		result = temp;
		if (check_line(buffer) == 1)
		{
			remove_first_line(buffer);
			break ;
		}
	}
	final = get_first_line(result);
	free(result);
	return (final);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			readvalue;

	if (fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (buffer[0] = '\0', NULL);
	if (buffer[0] == '\0')
	{
		readvalue = read(fd, buffer, BUFFER_SIZE);
		if (readvalue <= 0)
			return (NULL);
		buffer[readvalue] = '\0';
	}
	if (check_line(buffer) == 1)
	{
		result = get_first_line(buffer);
		remove_first_line(buffer);
		return (result);
	}
	result = ft_strdup(buffer);
	if (result == NULL)
		return (NULL);
	return (ft_gnl(fd, buffer, readvalue, result));
}
