/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iosypenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:31:39 by iosypenk          #+#    #+#             */
/*   Updated: 2018/02/06 15:31:41 by iosypenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_intlen(int nb)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void		id_figure(char *line)
{
	int		i;
	int		len;

	g_s.figure_h = ft_atoi(line + 6);
	len = ft_intlen(g_s.figure_h);
	g_s.figure_w = ft_atoi(line + 6 + len);
	g_s.fig = (char**)malloc(sizeof(char *) * g_s.figure_h);
	i = 0;
	while (i < g_s.figure_h)
	{
		get_next_line(0, &line);
		g_s.fig[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	place_figure();
}

static void		id_map(char *line)
{
	int		i;
	int		len;

	g_s.map_h = ft_atoi(line + 8);
	len = ft_intlen(g_s.map_h);
	g_s.map_w = ft_atoi(line + 8 + len);
	g_s.map = (char**)malloc(sizeof(char *) * g_s.map_h);
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	while (i < g_s.map_h)
	{
		get_next_line(0, &line);
		g_s.map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	if (g_s.have_target == 0)
	{
		find_target();
		g_s.have_target = 1;
	}
}

static void		check_player_nbr(char *line, char *argv)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, (argv + 2)))
	{
		g_s.m = 'o';
		g_s.mb = 'O';
		g_s.e = 'x';
		g_s.eb = 'X';
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, (argv + 2)))
	{
		g_s.m = 'x';
		g_s.mb = 'X';
		g_s.e = 'o';
		g_s.eb = 'O';
	}
}

int				main(int arc, char **arv)
{
	char		*line;

	line = NULL;
	g_s.have_target = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (arc >= 1 && ft_strstr(line, "$$$"))
			check_player_nbr(line, arv[0]);
		if (!ft_strncmp(line, "Plateau", 7))
			id_map(line);
		else if (!ft_strncmp(line, "Piece", 5))
			id_figure(line);
		ft_strdel(&line);
	}
	return (0);
}
