/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:36:30 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	t_pt		*create_map(int cols, int rows, int map_style)
{
	int				y;
	int				x;
	size_t			size;
	t_pt			*pts;
	char			*line;

	if ((size = cols * rows) <= 0
	|| !(pts = ft_memalloc(sizeof(*pts) * size)))
		return (NULL);
	y = -1;
	while (++y < cols)
	{
		x = -1;
		if (!(line = ft_read_fd(0)))
			return (ft_delete_line(&line));
		while (++x < rows)
		{
			pts[y * rows + x] = (t_pt){y, x, line[x + map_style]};
			pts[y * rows + x].y = y;
			pts[y * rows + x].x = x;
			pts[y * rows + x].token = line[x + map_style];
		}
		(line) ? ft_strdel(&line) : 0;
	}
	return (pts);
}

t_pt				*parse_map(t_map *ptr, int map_style)
{
	char			*line;
	char			*nums;

	if (!(line = ft_read_fd(0)))
		return (NULL);
	if (ft_strstr(line, "Plateau") || ft_strstr(line, "Piece"))
	{
		if (ft_strlen(line) < 6 || !(nums = ft_strrchr(line, ' ')))
		{
			if (line)
				ft_strdel(&line);
			return (NULL);
		}
		ptr->size.cols = (map_style) ? ft_atoi(line + 8) : ft_atoi(line + 6);
		if (!(nums = ft_strrchr(line, ' ') + 1))
		{
			if (line)
				ft_strdel(&line);
			return (NULL);
		}
		ptr->size.rows = ft_atoi(nums);
		(line) ? ft_strdel(&line) : 0;
		(map_style) ? ft_jump_line(0) : 0;
	}
	return (create_map(ptr->size.cols, ptr->size.rows, map_style));
}
