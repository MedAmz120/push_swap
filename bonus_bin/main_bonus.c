/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:33 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 19:12:37 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_bns	swp;

	swp.arg_c = ac;
	if (ac > 1)
	{
		if (arg_check_bns(av, ac, &swp))
		{
			swp.arg_c = swp.arg_c - 1;
			if (check_sorted_bns(&swp))
				quit_program_bns (&swp, 1);
			else
			{
				ft_apply_instructions(&swp);
				if (check_sorted_bns(&swp))
					ft_printf("OK\n");
				else
					ft_printf("KO\n");
				quit_program_bns (&swp, 0);
			}
		}
	}
	return (0);
}
