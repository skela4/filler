/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:34:56 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

static	void		display_pos(t_pt pt)
{
	ft_putnbr_fd(pt.y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(pt.x, 1);
	ft_putchar_fd('\n', 1);
}

static	void		delete_list(t_list **head_ref)
{
	t_list			*current;
	t_list			*next;

	current = *head_ref;
	if (!head_ref)
		return ;
	if (!*head_ref)
		return ;
	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		current->content = NULL;
		free(current);
		current = NULL;
		current = next;
	}
	*head_ref = NULL;
}

static	int			condi_valid(t_pt bpt, t_game *st_g, int start, int end)
{
	int				ry;
	int				rx;
	int				token_used;

	token_used = 0;
	while (start < end)
	{
		ry = bpt.y + (st_g->piece.points[start].y - st_g->piece.fpts.y);
		rx = bpt.x + (st_g->piece.points[start].x - st_g->piece.fpts.x);
		if (((ry < 0 || ry >= st_g->board.size.cols)
		|| (rx < 0 || rx >= st_g->board.size.rows))
		&& st_g->piece.points[start].token != '.')
			return (0);
		if (ry * st_g->board.size.rows + rx >=
		st_g->board.size.rows * st_g->board.size.cols)
			return (0);
		if (st_g->board.points[ry * st_g->board.size.rows + rx].token
		== st_g->enemy_token && st_g->piece.points[start].token == '*')
			return (0);
		if (st_g->board.points[ry * st_g->board.size.rows + rx].token
		== st_g->player_token && st_g->piece.points[start].token == '*')
			++token_used;
		++start;
	}
	return ((token_used != 1) ? 0 : 1);
}

static	int			is_placeable(t_pt bpt, t_game *st_game)
{
	int				i;
	int				t;

	if (st_game->player_token == 'O')
		st_game->enemy_token = 'X';
	else
		st_game->enemy_token = 'O';
	st_game->piece.fpts.y = 0;
	st_game->piece.fpts.x = 0;
	i = 0;
	t = st_game->piece.size.cols * st_game->piece.size.rows;
	while (i < t - 1 && st_game->piece.points[i].token != '*')
		++i;
	if (st_game->piece.points[i].token == '*')
	{
		st_game->piece.fpts.y = st_game->piece.points[i].y;
		st_game->piece.fpts.x = st_game->piece.points[i].x;
		if (condi_valid(bpt, st_game, i, t))
			return (1);
	}
	return (0);
}

void				send_pos(t_game *st_game, t_list **list_piece)
{
	t_pt			bpt;
	t_pt			rbpt;

	bpt.y = -1;
	while (++bpt.y < st_game->board.size.cols)
	{
		bpt.x = -1;
		while (++bpt.x < st_game->board.size.rows)
		{
			if (is_placeable(bpt, st_game) == 1)
			{
				rbpt.y = bpt.y - st_game->piece.fpts.y;
				rbpt.x = bpt.x - st_game->piece.fpts.x;
				ft_lst_append(&(*list_piece), (void *)&rbpt, sizeof(rbpt));
			}
		}
	}
	if (list_piece && *list_piece)
	{
		rbpt = get_closest_point(st_game, *list_piece, 10000, (t_pt[4]){0});
		display_pos(rbpt);
		delete_list(&(*list_piece));
		return ;
	}
	display_pos(bpt);
}
