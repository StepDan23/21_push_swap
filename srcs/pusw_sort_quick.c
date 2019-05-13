/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_sort_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:42:53 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/05 13:54:49 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char		*pusw_soft_size_a(t_list **lst_a, int size)
{
	int		min;
	int		max;
	char	*out;

	min = pusw_findmin(*lst_a, size);
	max = pusw_findmax(*lst_a, size);
	out = ft_strnew(6);
	if (out == NULL)
		return (NULL);
	if (min == *((int*)(*lst_a)->content))
		out = ft_strcpy(out, "sa\nra\n");
	else if (min == *((int*)((*lst_a)->next)->content))
		out = ft_strcpy(out,
				(max == *(int*)(*lst_a)->content) ? "ra\n" : "sa\n");
	else if (max == *((int*)((*lst_a)->next)->content))
		out = ft_strcpy(out, "rra\n");
	else
		out = ft_strcpy(out, "ra\nsa\n");
	return (out);
}

static char		*pusw_size_a(t_list **lst_a, int size)
{
	int		min;
	int		max;
	char	*out;

	min = pusw_findmin(*lst_a, size);
	max = pusw_findmax(*lst_a, size);
	out = ft_strnew(16);
	if (out == NULL)
		return (NULL);
	if (min == *((int*)(*lst_a)->content))
		out = ft_strcpy(out, "ra\nsa\nrra\n");
	else if (min == *((int*)((*lst_a)->next)->content))
		out = ft_strcpy(out, (max == *(int*)(*lst_a)->content) ?
									"sa\nra\nsa\nrra\n" : "sa\n");
	else if (max == *((int*)((*lst_a)->next)->content))
		out = ft_strcpy(out, "ra\nsa\nrra\nsa\n");
	else
		out = ft_strcpy(out, "sa\nra\nsa\nrra\nsa\n");
	return (out);
}

static void		pusw_sol_size(t_list **lst_a, t_list **ins, int soft)
{
	char	*sol;
	char	*tmp;
	int		st;
	int		i;

	if (soft == 1)
		sol = pusw_soft_size_a(lst_a, 3);
	else
		sol = pusw_size_a(lst_a, 3);
	if (sol == NULL)
		return ;
	tmp = sol;
	st = 0;
	i = 0;
	while (sol[st])
	{
		while (sol[i] != '\n')
			i++;
		i++;
		ft_lstpushback(ins, &sol[st], i + 1 - st);
		pusw_make_solve(lst_a, NULL, &sol[st]);
		st = i;
	}
	free(sol);
	sol = NULL;
}

static int		pusw_sort_quick_b(t_list **lst_a,
								t_list **lst_b, t_list **ins, int size)
{
	if (size <= 2 || pusw_isrevsort(*lst_b, size))
	{
		if (!pusw_isrevsort(*lst_b, size))
		{
			pusw_swap(lst_b);
			ft_lstpushback(ins, "sb\n", 4);
		}
		while (size--)
		{
			pusw_push(lst_b, lst_a);
			ft_lstpushback(ins, "pa\n", 4);
		}
		return (1);
	}
	pusw_pivot_b(lst_a, lst_b, ins, size);
	pusw_sort_quick_a(lst_a, lst_b, ins, size / 2 + size % 2);
	pusw_sort_quick_b(lst_a, lst_b, ins, size / 2);
	return (0);
}

int				pusw_sort_quick_a(t_list **lst_a,
								t_list **lst_b, t_list **ins, int size)
{
	if (size <= 3 || pusw_issort(*lst_a, size))
	{
		if (!pusw_issort(*lst_a, size) && size == 3)
		{
			if (ft_lstsize(*lst_a) / 4 == 3)
				pusw_sol_size(lst_a, ins, 1);
			else
				pusw_sol_size(lst_a, ins, 0);
		}
		if (!pusw_issort(*lst_a, size) && size == 2)
		{
			pusw_swap(lst_a);
			ft_lstpushback(ins, "sa\n", 4);
		}
		return (1);
	}
	pusw_pivot_a(lst_a, lst_b, ins, size);
	pusw_sort_quick_a(lst_a, lst_b, ins, size / 2 + size % 2);
	pusw_sort_quick_b(lst_a, lst_b, ins, size / 2);
	return (0);
}
