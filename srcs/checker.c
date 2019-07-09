/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:48:34 by mmcclure          #+#    #+#             */
/*   Updated: 2019/07/09 13:41:12 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			pusw_lst_d_print(t_list *lst_a, t_list *lst_b)
{
	int	*a;
	int	*b;

	ft_printf("________________________\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			a = lst_a->content;
			lst_a = lst_a->next;
		}
		else
			a = NULL;
		if (lst_b)
		{
			b = lst_b->content;
			lst_b = lst_b->next;
		}
		else
			b = NULL;
		(a == NULL) ? ft_printf("%-12s", "-") : ft_printf("%-12d", *a);
		(b == NULL) ? ft_printf("%12s\n", "-") : ft_printf("%+12d\n", *b);
	}
	ft_printf("%s\n%-12s%12s\n\n", "________________________", "a", "b");
}

static t_list		*pusw_read_ins(t_list **list_a, t_list **list_b, char *flag)
{
	char	*ln;
	t_list	*ins;

	ins = 0;
	ln = 0;
	while ((get_next_line(0, &ln) == 1))
	{
		if (ft_strstr(flag, "v") && pusw_val_inst(ln))
		{
			pusw_make_solve(list_a, list_b, ln);
			pusw_lst_d_print(*list_a, *list_b);
		}
		else if (pusw_val_inst(ln))
			ft_lstpushback(&ins, ln, ft_strlen(ln) + 1);
		else
		{
			write(2, "Error\n", 6);
			pusw_clean(&ins, list_a, list_b);
			exit(0);
		}
		if (ft_strstr(flag, "c"))
			ft_printf("The operation is - \033[0;32m%s\e[0m\n", ln);
		free(ln);
	}
	return (ins);
}

int					main(int argc, char **argv)
{
	t_list	*args;
	t_list	*list_b;
	t_list	*ins;
	t_list	*tmp;
	char	*flag;

	ins = 0;
	list_b = 0;
	while ((ft_strstr(argv[1], "v") || ft_strstr(argv[1], "c")) && (argc-- > 1))
	{
		flag = argv[1];
		argv = &argv[1];
	}
	if (argc == 1)
		return (0);
	args = pusw_read_arg(argc, argv);
	ins = pusw_read_ins(&args, &list_b, flag);
	ft_lstpushfront(&ins, 0, 4);
	tmp = ins;
	while ((tmp = tmp->next))
		pusw_make_solve(&args, &list_b, ((char*)tmp->content));
	write(1, ((!list_b) && pusw_issort(args, ft_lstsize(args) / 4))
													? "OK\n" : "KO\n", 3);
	pusw_clean(&ins, &args, &list_b);
	return (1);
}
