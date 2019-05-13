/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:58 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/04 11:49:49 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		pusw_val_inst(char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		return (1);
	else if (!ft_strcmp(inst, "sb"))
		return (1);
	else if (!ft_strcmp(inst, "ss"))
		return (1);
	else if (!ft_strcmp(inst, "pa"))
		return (1);
	else if (!ft_strcmp(inst, "pb"))
		return (1);
	else if (!ft_strcmp(inst, "ra"))
		return (1);
	else if (!ft_strcmp(inst, "rb"))
		return (1);
	else if (!ft_strcmp(inst, "rr"))
		return (1);
	else if (!ft_strcmp(inst, "rra"))
		return (1);
	else if (!ft_strcmp(inst, "rrb"))
		return (1);
	else if (!ft_strcmp(inst, "rrr"))
		return (1);
	return (0);
}

void	pusw_swap(t_list **lst)
{
	t_list	*tmp;
	int		*buf;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	if (tmp->next)
	{
		buf = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = buf;
	}
}

void	pusw_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*tmp;

	if (!lst_from || !lst_to)
		return ;
	tmp = *lst_from;
	if (tmp)
	{
		*lst_from = (*lst_from)->next;
		tmp->next = *lst_to;
		*lst_to = tmp;
	}
}

void	pusw_rot(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	if (tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *lst;
		*lst = (*lst)->next;
		tmp->next->next = NULL;
	}
}

void	pusw_revrot(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst)
		return ;
	last = *lst;
	if (!last)
		return ;
	if (last->next)
	{
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		last->next = *lst;
		*lst = last;
	}
}
