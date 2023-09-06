/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:11:50 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 15:07:44 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_sorted_bns(t_bns *s)
{
	int	i;

	i = 1;
	while (i < s->arg_c)
	{
		if ((s->sta[i - 1] < s->sta[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
