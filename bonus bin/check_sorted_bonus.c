/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:11:50 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 17:12:50 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_sorted_bns(t_bns *s)
{
	int	i;

	i = 0;
	while (i < s->arg_c - 1)
	{
		if ((s->sta[i] < s->sta[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}
