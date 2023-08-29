/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:28:57 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/26 17:26:17 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_sort_3(t_swp *s)
{
    int pos;

    pos = s->a_pos;
    if (check_part_sorted(s))
        return ;
    else if (s->sta[pos + 2] > s->sta[pos]
        && s->sta[pos + 2] > s->sta[pos + 1]
        && s->sta[pos] > s->sta[pos + 1])
        ft_sa(s);
    else if (s->sta[pos] > s->sta[pos + 1]
        && s->sta[pos + 1] < s->sta[pos + 2]
        && s->sta[pos] > s->sta[pos + 2])
        ft_ra(s);
    else if (s->sta[pos] > s->sta[pos + 1]
        && s->sta[pos] > s->sta[pos + 2])
    {
        ft_sa(s);
        ft_rra(s);
    }
    else if (s->sta[pos] < s->sta[pos + 1]
        && s->sta[pos + 1] > s->sta[pos + 2]
        && s->sta[pos] < s->sta[pos + 2])
    {
        ft_sa(s);
        ft_ra(s);
    }
    else
        ft_rra(s);
}