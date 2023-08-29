/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:11:50 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/25 20:17:54 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_swp *s)
{
	int	i;

	i = 0;
	while (i < s->acs - 1)
	{
		if ((s->sta[i] < s->sta[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_part_sorted(t_swp *s)
{
	int	i;

	i = s->a_pos;
	while (i < s->a_cnt)
	{
		if ((s->sta[i] < s->sta[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}
