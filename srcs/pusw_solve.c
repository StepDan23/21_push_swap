/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:40:12 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/27 14:28:14 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			pusw_make_solve(t_list **lst_a, t_list **lst_b, char *ins)
{
	if (ins[0] == 's' && ins[1] == 's')
	{
		pusw_swap(lst_a);
		pusw_swap(lst_b);
	}
	else if (ins[0] == 's')
		(ins[1] == 'a') ? pusw_swap(lst_a) : pusw_swap(lst_b);
	else if (ins[0] == 'p')
		(ins[1] == 'a') ? pusw_push(lst_b, lst_a) : pusw_push(lst_a, lst_b);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'r')
	{
		pusw_revrot(lst_a);
		pusw_revrot(lst_b);
	}
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2])
		(ins[2] == 'a') ? pusw_revrot(lst_a) : pusw_revrot(lst_b);
	else if (ins[0] == 'r' && ins[1] == 'r')
	{
		pusw_rot(lst_a);
		pusw_rot(lst_b);
	}
	else if (ins[0] == 'r')
		(ins[1] == 'a') ? pusw_rot(lst_a) : pusw_rot(lst_b);
}
