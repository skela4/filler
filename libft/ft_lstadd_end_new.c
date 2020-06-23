/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:47:57 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/30 14:23:42 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lst_append(t_list **head_ref, void *content,
size_t content_size)
{
	t_list		*last;
	t_list		*new_node;

	last = *head_ref;
	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(content_size);
	if (!new_node->content)
	{
		free(new_node);
		new_node = NULL;
		return ;
	}
	ft_memcpy(new_node->content, content, content_size);
	new_node->content_size = content_size;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
