/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:07:51 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/05 14:11:11 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static float	pusw_findpiv(t_list *lst, int size, float out)
{
	t_list	*begin;
	int		tmp;
	int		left;
	int		right;

	tmp = size;
	begin = lst;
	left = 0;
	right = 0;
	while (size)
	{
		if (*((int*)lst->content) != out)
			((*((int*)lst->content) > out)) ? right++ : left++;
		lst = lst->next;
		size--;
		if (!size && right != left)
		{
			out += (right > left) ? 0.5 : -0.5;
			lst = begin;
			size = tmp;
			left = 0;
			right = 0;
		}
	}
	return (out);
}

static void		pusw_piv_revrot(t_list **lst, t_list **ins, int size, int side)
{
	while (size--)
	{
		pusw_revrot(lst);
		ft_lstpushback(ins, (side == 1) ? "rra\n" : "rrb\n", 5);
	}
}

void			pusw_pivot_a(t_list **lst_a, t_list **lst_b,
										t_list **ins, int size)
{
	float	pivot;
	int		coun;
	int		limit;

	coun = 0;
	limit = 0;
	pivot = pusw_findpiv(*lst_a, size,
			(pusw_findmin(*lst_a, size) + pusw_findmax(*lst_a, size)) / 2);
	while (coun < size / 2)
		if ((*((int*)(*lst_a)->content) >= pivot))
		{
			pusw_rot(lst_a);
			ft_lstpushback(ins, "ra\n", 4);
			limit++;
		}
		else
		{
			pusw_push(lst_a, lst_b);
			ft_lstpushback(ins, "pb\n", 4);
			coun++;
		}
	if ((int)(ft_lstsize(*lst_a) / 4) > (size / 2 + size % 2))
		pusw_piv_revrot(lst_a, ins, limit, 1);
}

void			pusw_pivot_b(t_list **lst_a, t_list **lst_b,
										t_list **ins, int size)
{
	float	pivot;
	int		coun;
	int		limit;

	coun = 0;
	limit = 0;
	pivot = pusw_findpiv(*lst_b, size,
			(pusw_findmin(*lst_b, size) + pusw_findmax(*lst_b, size)) / 2);
	while (coun < size / 2 + size % 2)
		if ((*((int*)(*lst_b)->content) < pivot) && ++limit)
		{
			pusw_rot(lst_b);
			ft_lstpushback(ins, "rb\n", 4);
		}
		else if (++coun)
		{
			pusw_push(lst_b, lst_a);
			ft_lstpushback(ins, "pa\n", 4);
		}
	if ((int)(ft_lstsize(*lst_b) / 4) > size / 2)
		pusw_piv_revrot(lst_b, ins, limit, 0);
}
