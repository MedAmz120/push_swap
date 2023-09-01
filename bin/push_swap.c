/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:20:08 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/01 10:28:52 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_push_swap(t_swp *s)
{
    s->b_pos = s->acs;
    s->a_pos = 0;
    s->b_cnt = 0;
    s->a_cnt = s->acs;// because a is already full unlike stack b is empty
    s->stb = (int *)malloc(sizeof(int) * s->acs + 1);
    if (!s->stb)
        quit_program (s, 0);
    if (s->acs >= 1 && s->acs <= 3)
        ft_sort_3(s);
    if (s->acs > 3 && s->acs <= 5)
        ft_sort_5(s);
    if (s->acs > 5 && s->acs <= 100)
        ft_sort_100(s);
}