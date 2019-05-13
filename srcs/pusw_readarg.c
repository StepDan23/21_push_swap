/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_readarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:36:43 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/04 13:00:02 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long int		pusw_atoi(char **str)
{
	long int	out;
	int			check;
	int			flag;

	while ((ft_isspace(**str)))
		*str += 1;
	flag = (**str == '-') ? -1 : 1;
	if ((**str == '-') || (**str == '+'))
		*str += 1;
	out = 0;
	check = 0;
	if (((**str < '0') || (**str > '9')))
		return (-2147483649);
	while ((**str >= '0') && (**str <= '9'))
	{
		check = (check * 10) + (**str - '0');
		out = (out * 10) + (**str - '0');
		if (flag * check != flag * out)
			return (-2147483649);
		*str += 1;
	}
	while ((ft_isspace(**str)))
		*str += 1;
	return (flag * out);
}

t_list				*pusw_read_arg(int argc, char **argv)
{
	t_list		*out;
	int			i;
	long int	a;

	out = 0;
	i = 0;
	while (++i < argc)
		while (*argv[i])
		{
			a = pusw_atoi(&argv[i]);
			if (a == -2147483649 || ft_lstfind(out, &a, 4))
			{
				write(2, "Error\n", 6);
				ft_lstdel(&out, &del_content);
				exit(0);
			}
			ft_lstpushback(&out, &a, 4);
		}
	return (out);
}
