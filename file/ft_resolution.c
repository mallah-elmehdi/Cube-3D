/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:27:35 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 11:57:17 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_resolution_syntax(char *line)
{
	int		i;

	i = 2;
	if (!ft_is_whitespace(line[1]))
		return (ft_err("ERROR\nresolution error: syntax error"));
	while (line[i] != 0)
	{
		if (!ft_is_int(line[i]) && !ft_is_whitespace(line[i]))
			return (ft_err("ERROR\nresolution error: syntax error"));
		i++;
	}
	return (0);
}

int		ft_resolution_errors(char *line)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (line[i] != 0)
	{
		if (ft_is_int(line[i]))
		{
			a++;
			while (ft_is_int(line[i]))
			{
				if (!(line[i + 1] >= 48 && line[i + 1] <= 57))
					break ;
				i++;
			}
		}
		i++;
	}
	if (a != 2)
		return (ft_err("ERROR\nresolution error: arguments error"));
	return (0);
}

void	ft_dimension(char *line, int *x, int *y)
{
	int		i;

	i = 1;
	while (line[i] != 0 && ft_is_whitespace(line[i]))
		i++;
	while (*x < 99999 && line[i] != 0 && ft_is_int(line[i]))
		*x = (*x * 10) + (line[i++] - 48);
	while (line[i] != 0 && ft_is_int(line[i]))
		i++;
	while (line[i] != 0 && ft_is_whitespace(line[i]))
		i++;
	while (*y < 99999 && line[i] != 0 && ft_is_int(line[i]))
		*y = (*y * 10) + (line[i++] - 48);
}

int		ft_resolution_add(char *line)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_dimension(line, &x, &y);
	if (x > 2560)
		x = 2560;
	if (y > 1440)
		y = 1440;
	g_info.rsl[0] = x;
	g_info.rsl[1] = y;
	return (0);
}

int		ft_resolution(char *line)
{
	if (g_info.rsl[0] != -1 && g_info.rsl[1] != -1)
		return (ft_err("ERROR\nresolution error: doubled argument"));
	if (ft_resolution_syntax(line))
		return (ERR);
	if (ft_resolution_errors(line))
		return (ERR);
	if (ft_resolution_add(line))
		return (ERR);
	if (g_info.rsl[0] < 100 || g_info.rsl[1] < 100)
		return (ft_err("ERROR\nresolution error: min res is 100px"));
	return (0);
}
