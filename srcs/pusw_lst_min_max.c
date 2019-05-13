/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_lst_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:41:18 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/27 17:48:13 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			pusw_findmin(t_list *lst, int size)
{
	int		*min;
	int		*pos;

	if (!lst)
		return (0);
	min = lst->content;
	while (--size)
	{
		pos = lst->next->content;
		if (*pos < *min)
			min = pos;
		lst = lst->next;
	}
	return (*min);
}

int			pusw_findmax(t_list *lst, int size)
{
	int		*max;
	int		*pos;

	if (!lst)
		return (0);
	max = lst->content;
	while (--size)
	{
		pos = lst->next->content;
		if (*pos > *max)
			max = pos;
		lst = lst->next;
	}
	return (*max);
}
