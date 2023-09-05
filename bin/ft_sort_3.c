/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:28:57 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 16:34:19 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_3_part2(t_swp *s, int pos)
{
	if (s->sta[pos + 2] > s->sta[pos]
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

void	ft_sort_3(t_swp *s)
{
	int	pos;

	pos = s->a_pos;
	ft_sort_3_part2(s, pos);
}
