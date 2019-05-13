/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:45:09 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/05 13:24:25 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/includes/libft.h"

t_list	*pusw_read_arg(int argc, char **argv);
void	pusw_make_solve(t_list **lst_a, t_list **lst_b, char *ins);
int		pusw_sort_quick_a(t_list **lst_a, t_list **lst_b,
													t_list **ins, int size);
/*
** pusw_instr.c
*/
int		pusw_val_inst(char *inst);
void	pusw_swap(t_list **list);
void	pusw_push(t_list **l_from, t_list **l_to);
void	pusw_revrot(t_list **list);
void	pusw_rot(t_list **list);
/*
** pusw_lst_min_max.c
*/
int		pusw_findmax(t_list *lst, int size);
int		pusw_findmin(t_list *lst, int size);
/*
** pusw_lstoper.c
*/
void	del_content(void *content, size_t size);
void	pusw_clean(t_list **l_a, t_list **l_b, t_list **l_c);
int		pusw_issort(t_list *lst_a, int size);
int		pusw_isrevsort(t_list *lst_a, int size);
/*
** pusw_pivot.c
*/
void	pusw_pivot_a(t_list **lst_a, t_list **lst_b, t_list **ins, int size);
void	pusw_pivot_b(t_list **lst_a, t_list **lst_b, t_list **ins, int size);
#endif
