/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:40:10 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_game		init_struct(void)
{
	t_game			game;

	game.board.points = NULL;
	game.board.size.cols = 0;
	game.board.size.rows = 0;
	game.piece.points = NULL;
	game.piece.size.cols = 0;
	game.piece.size.rows = 0;
	game.status = E_GAME_STATE_OFF;
	game.player_token = 0;
	return (game);
}

static	void		delete_map(t_map **obj, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (obj[i]->points)
			ft_memdel((void*)&(obj[i]->points));
		i++;
	}
}

static	char		set_token_player(void)
{
	char			*line;
	char			*token_p;
	char			token;

	if (!(line = ft_read_fd(0)))
		return (0);
	if (!(token_p = ft_strchr(line, 'p')))
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	if (*(token_p++) != 'p')
		return (0);
	token = *token_p;
	if (line)
		ft_strdel(&line);
	if (token != '1' && token != '2')
		return (0);
	return ((token == '1') ? 'O' : 'X');
}

static	void		launch_game(t_game *st_game)
{
	t_list			*list_piece;

	list_piece = NULL;
	st_game->status = E_GAME_STATE_ON;
	while (st_game->status)
	{
		if (!(st_game->board.points = parse_map(&st_game->board, 4)))
			st_game->status = E_GAME_STATE_OFF;
		if (st_game->status
		&& !(st_game->piece.points = parse_map(&st_game->piece, 0)))
		{
			ft_memdel((void *)&(st_game->board.points));
			st_game->status = E_GAME_STATE_OFF;
		}
		if (st_game->status)
			send_pos(st_game, &list_piece);
		delete_map((t_map *[]){&st_game->board, &st_game->piece}, 2);
	}
}

int					main(void)
{
	t_game			st_game;

	st_game = init_struct();
	if (!(st_game.player_token = set_token_player()))
		return (0);
	launch_game(&st_game);
	return (0);
}
