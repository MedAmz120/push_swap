/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:20:09 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 13:33:26 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_swp	swp;

	swp.acs = ac;
	swp.sta = NULL;
	swp.stb = NULL;
	swp.chnk = NULL;
	if (ac > 1)
	{
		if (arg_check(av, ac, &swp))
		{
			swp.acs = swp.acs - 1;
			if (check_sorted(&swp))
				quit_program(&swp, 0);
			else
			{
				ft_push_swap(&swp);
				int i = 0;
				/*while (i < swp.acs)
				{printf("%d\n", swp.sta[i]);i++;}*/
				quit_program(&swp, 0);
			}
		}
	}
	return (0);
}
