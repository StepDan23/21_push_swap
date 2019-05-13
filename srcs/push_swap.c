/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:53 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/05 13:17:35 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		pusw_ins_remake(t_list **ins)
{
	t_list	*next;
	t_list	*begin;

	begin = *ins;
	if ((!(*ins)) || (!(*ins)->next) || (!(*ins)->next->next))
		return ;
	while (((*ins)->next->next) && ((*ins) = (*ins)->next))
		if (!ft_memcmp((*ins)->next->content, "rra", 3) &&
				!ft_memcmp((*ins)->next->next->content, "ra", 2))
		{
			next = (*ins)->next->next->next;
			ft_lstdelone(&((*ins)->next->next), del_content);
			ft_lstdelone(&((*ins)->next), del_content);
			(*ins)->next = next;
			(*ins) = begin;
		}
		else if (!ft_memcmp((*ins)->next->content, "sa", 2) &&
				!ft_memcmp((*ins)->next->next->content, "sb", 2))
		{
			next = (*ins)->next->next->next;
			ft_lstdelone(&((*ins)->next->next), del_content);
			((char*)(*ins)->next->content)[1] = 's';
			(*ins)->next->next = next;
		}
	*ins = begin;
}

int				main(int argc, char **argv)
{
	t_list	*args;
	t_list	*lst_b;
	t_list	*ins;
	int		size;

	lst_b = 0;
	ins = 0;
	args = pusw_read_arg(argc, argv);
	size = ft_lstsize(args) / 4;
	pusw_sort_quick_a(&args, &lst_b, &ins, size);
	pusw_ins_remake(&ins);
	ft_lstprint(ins);
	pusw_clean(&args, &lst_b, &ins);
	return (1);
}
