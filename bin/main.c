/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:20:09 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 21:25:26 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_swp	swp;

	swp.sta = NULL;
	swp.stb = NULL;
	swp.chnk = NULL;
	swp.avg = NULL;
	if (ac > 1)
	{
		if (ac == 2)
			check_double_quo(av[1], &swp, &ac);
		else
			swp.avg = av;
		swp.acs = ac - 1;
		if (!arg_check(swp.avg, ac, &swp))
			quit_program (&swp, 404);
		swp.acs = ac - 1;
		if (check_sorted(&swp))
			quit_program(&swp, 0);
		else
			ft_push_swap(&swp);
	}
	quit_program(&swp, 0);
	return (0);
}
