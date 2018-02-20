/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iosypenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:31:50 by iosypenk          #+#    #+#             */
/*   Updated: 2018/02/06 15:33:16 by iosypenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft/libft.h"

typedef struct	s_filller_struct
{
	char		m;
	char		mb;
	char		e;
	char		eb;

	int			map_h;
	int			map_w;
	int			figure_h;
	int			figure_w;

	int			g_pl_h;
	int			g_pl_w;
	int			b_pl_h;
	int			b_pl_w;

	char		**map;
	char		**fig;

	int			my_h;
	int			my_w;

	int			target_h;
	int			target_w;

	int			good;
	int			first_place;
	int			have_target;
}				t_filler_struct;

t_filler_struct		g_s;

void			place_figure(void);
void			find_target(void);

#endif
