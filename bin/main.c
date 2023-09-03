/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:20:09 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/26 17:23:23 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{
    t_swp   swp;

    swp.acs = ac;
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
                quit_program(&swp, 0);
            }
        }
    }
    return (0);
}