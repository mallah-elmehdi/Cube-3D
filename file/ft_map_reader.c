/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:19:04 by emallah           #+#    #+#             */
/*   Updated: 2020/10/23 12:12:11 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_is_map_has_empty_line(void)
{
	int			i;

	i = 0;
	while (i < g_map_height)
	{
		if (!g_map[i][0])
			return (ft_err("ERROR\nmap error: empty line"));
		i++;
	}
	return (0);
}

int		ft_map_errors(void)
{
	g_map_height--;
	if (!g_map_height)
		return (ft_err("ERROR\nmap error: no map in the file"));
	while (g_map[g_map_height][0] == 0)
	{
		free_it(&g_map[g_map_height]);
		g_map_height--;
	}
	if (ft_is_map_has_empty_line())
		return (ERR);
	if (ft_check_map())
		return (ERR);
	return (0);
}

int		ft_map_syntax(char *line)
{
	int			i;
	static int	player;

	i = 0;
	while (ft_is_whitespace(line[i]))
		i++;
	while (line[i] != 0)
	{
		if (!ft_is_map(line[i]) && !ft_is_whitespace(line[i])
		&& !ft_is_player(line[i]))
			return (ft_err("ERROR\nmap error: syntax error"));
		if (ft_is_player(line[i]))
			player++;
		i++;
	}
	if (player > 1)
		return (ft_err("ERROR\nplayer error: more than one player"));
	if (g_gnl == 2 && player == 0)
		return (ft_err("ERROR\nplayer error: no player in the map"));
	return (0);
}

int		ft_map_reader(char *line)
{
	static int	i;

	ft_strtrim_one_side(&line);
	if (ft_map_syntax(line))
		return (ERR);
	if (line[0] == 0 && i == 0)
	{
		g_map_height--;
		return (0);
	}
	if (i < g_map_height)
	{
		g_map[i] = (char *)ft_calloc(sizeof(char), g_map_width + 1);
		ft_fill_map(&g_map[i], line);
		i++;
	}
	return (0);
}
