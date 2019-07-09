/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_lstoper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:41:18 by mmcclure          #+#    #+#             */
/*   Updated: 2019/07/09 13:46:28 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		del_content(void *content, size_t size)
{
	if (content != NULL)
		ft_memdel(&content);
	size = 0;
}

void		pusw_clean(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	if (lst_a)
		ft_lstdel(lst_a, &del_content);
	if (lst_b)
		ft_lstdel(lst_b, &del_content);
	if (lst_c)
		ft_lstdel(lst_c, &del_content);
}

int			pusw_issort(t_list *lst_a, int size)
{
	int		*a;
	int		*b;

	if (!lst_a)
		return (0);
	while (--size)
	{
		a = lst_a->content;
		b = lst_a->next->content;
		if (*a > *b)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

int			pusw_isrevsort(t_list *lst_a, int size)
{
	int		*a;
	int		*b;

	if ((!lst_a) || (!lst_a->next))
		return (1);
	while ((lst_a) && --size)
	{
		a = lst_a->content;
		b = lst_a->next->content;
		if (*a < *b)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}
