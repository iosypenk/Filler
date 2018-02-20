/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iosypenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:39:12 by iosypenk          #+#    #+#             */
/*   Updated: 2018/02/12 15:39:16 by iosypenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_target(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_s.map_h)
	{
		j = 0;
		while (j < g_s.map_w)
		{
			if ((g_s.map[i][j] == g_s.e || g_s.map[i][j] == g_s.eb) &&
				g_s.have_target == 0)
			{
				g_s.target_h = i;
				g_s.target_w = j;
			}
			if (g_s.map[i][j] == g_s.e && g_s.have_target == 1)
			{
				g_s.target_h = i;
				g_s.target_w = j;
			}
			j++;
		}
		i++;
	}
}

static void		clear_arr(char **arr, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

static void		find_best(void)
{
	int					bad;
	int					tmp_1;
	int					tmp_2;

	if (g_s.first_place == 0)
	{
		tmp_1 = g_s.target_w - g_s.g_pl_w;
		(tmp_1 < 0) ? tmp_1 *= -1 : 0;
		tmp_2 = g_s.target_h - g_s.g_pl_h;
		(tmp_2 < 0) ? tmp_2 *= -1 : 0;
		g_s.good = tmp_1 + tmp_2;
	}
	g_s.first_place = 1;
	tmp_1 = g_s.target_w - g_s.g_pl_w;
	(tmp_1 < 0) ? tmp_1 *= -1 : 0;
	tmp_2 = g_s.target_h - g_s.g_pl_h;
	(tmp_2 < 0) ? tmp_2 *= -1 : 0;
	bad = tmp_1 + tmp_2;
	if (g_s.good >= bad)
	{
		g_s.b_pl_h = g_s.g_pl_h;
		g_s.b_pl_w = g_s.g_pl_w;
		g_s.good = tmp_1 + tmp_2;
	}
	find_target();
}

static int		check_figure(int i, int j)
{
	int		w;
	int		h;
	int		count;

	count = 0;
	h = -1;
	while (++h < g_s.figure_h)
	{
		w = -1;
		while (++w < g_s.figure_w)
		{
			if ((g_s.fig[h][w] == '*' && (g_s.map[i + h][j + w] == g_s.m ||
				g_s.map[i + h][j + w] == g_s.mb)))
			{
				g_s.g_pl_h = i;
				g_s.g_pl_w = j;
				count++;
			}
			else if ((g_s.fig[h][w] == '*' && (g_s.map[i + h][j + w] == g_s.e ||
				g_s.map[i + h][j + w] == g_s.eb)))
				return (0);
		}
	}
	return (count == 1 ? 1 : 0);
}

void			place_figure(void)
{
	int		i;
	int		j;

	i = 0;
	g_s.first_place = 0;
	g_s.good = 0;
	while (i <= (g_s.map_h - g_s.figure_h))
	{
		j = 0;
		while (j <= (g_s.map_w - g_s.figure_w))
		{
			if (check_figure(i, j) == 1)
				find_best();
			j++;
		}
		i++;
	}
	clear_arr(g_s.map, g_s.map_h);
	clear_arr(g_s.fig, g_s.figure_h);
	g_s.map_w = 0;
	g_s.map_h = 0;
	g_s.figure_h = 0;
	g_s.figure_w = 0;
	ft_printf("%d %d\n", g_s.b_pl_h, g_s.b_pl_w);
}
