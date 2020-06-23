/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:21:35 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:24:11 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_jump_line(int fd)
{
	char			*line;

	line = NULL;
	if (get_next_line(fd, &line) < 0)
	{
		if (line)
			ft_strdel(&line);
	}
	ft_strdel(&line);
}
