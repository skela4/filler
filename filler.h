/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:16 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:34:54 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef enum			e_game_state
{
	E_GAME_STATE_OFF,
	E_GAME_STATE_ON
}						t_game_state;

typedef	struct			s_coord
{
	int					cols;
	int					rows;
}						t_coord;

typedef	struct			s_pt
{
	int					y;
	int					x;
	char				token;
}						t_pt;

typedef	struct			s_map
{
	t_coord				size;
	t_pt				*points;
	t_pt				fpts;
}						t_map;

typedef struct			s_game
{
	t_map				board;
	t_map				piece;
	int					status;
	char				player_token;
	char				enemy_token;
}						t_game;

t_pt					*parse_map(t_map *ptr, int map_style);
void					send_pos(t_game *st_game, t_list **list_piece);
t_pt					get_closest_point(t_game *game, t_list *lst,
int min_dist, t_pt min_pts[4]);

#endif
