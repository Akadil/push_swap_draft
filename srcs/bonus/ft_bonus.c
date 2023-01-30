/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:24:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/01/30 19:08:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	a = NULL;
	b = NULL;
	if (ft_init_stacks(&a, &b) == 0 || argc < 2 || argv[1] == (void *)0)
		return (ft_free_stacks_0(a, b));
	if (ft_parse(argc, argv, a, b) == 0)
		return (ft_free_stacks_error_0(a, b));
	if (ft_is_sorted(a) == 1)
		return (ft_free_stacks_0(a, b));
	str = get_next_line(0);
	while (str)
	{
		ft_do_command(a, b, str);
		if (!a)
			return (ft_free_str_0(str));
		str = get_next_line(0);
	}
	if (ft_is_sorted(a) == 1 && ft_is_empty(b) == 1)
		return (ft_result_free_return(a, b, 1));
	else
		return (ft_result_free_return(a, b, 0));
}
