/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:36:26 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		dist(t_pt p, t_pt q)
{
	int			v;

	v = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
	return (v);
}

t_pt			get_closest_point(t_game *game, t_list *lst, int m_dist,
t_pt min_pts[4])
{
	int			y;
	int			x;

	while (lst)
	{
		y = -1;
		while (++y < game->board.size.cols)
		{
			x = -1;
			while (++x < game->board.size.rows)
			{
				min_pts[0] = *((t_pt *)(lst->content));
				min_pts[0].token = game->player_token;
				min_pts[1] = game->board.points[y * game->board.size.rows + x];
				if (min_pts[1].token == game->enemy_token
				&& dist(min_pts[0], min_pts[1]) < m_dist)
				{
					m_dist = dist(min_pts[0], min_pts[1]);
					min_pts[2] = min_pts[0];
				}
			}
		}
		lst = lst->next;
	}
	return (min_pts[2]);
}
