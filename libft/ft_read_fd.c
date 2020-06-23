/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:21:39 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/28 07:04:24 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_read_fd(int fd)
{
	char	*line;

	line = NULL;
	if (get_next_line(fd, &line) < 0)
	{
		if (line)
			ft_strdel(&line);
	}
	return (line);
}
