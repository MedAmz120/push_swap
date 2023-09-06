/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 19:05:22 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_element_index(int *src, int t_find, int pos, t_swp *s)
{
	int	i;
	int	count;

	count = 0;
	while (count <= s->b_cnt)
	{
		if (src[pos] == t_find)
			return (pos);
		pos++;
		count++;
	}
	return (pos);
}

int	ft_big_number_stb(t_swp *s)
{
	int	i;
	int	j;
	int	max;

	i = s->b_pos;
	max = s->stb[i];
	while (i < s->acs)
	{
		j = i;
		while (j < s->acs)
		{
			if (s->stb[j] > max)
				max = s->stb[j];
			j++;
		}
		i++;
	}
	return (max);
}

void	ft_push_max(t_swp *s, int *pos, int *half)
{
	int	size;
	int	temp;
	int	i;

	temp = (*pos);
	if (((*pos) - s->b_pos) > (*half))
	{
		i = 0;
		size = s->b_cnt - temp + s->b_pos;
		while (i < size)
		{
			ft_rrb(s, 1);
			i++;
		}
	}
	else
	{
		size = (*pos) - s->b_pos;
		while (size > 0)
		{
			ft_rb(s, 1);
			size--;
		}
	}
	ft_pa(s);
}

void	ft_pushto_sta(t_swp *s)
{
	int	i;
	int	max;
	int	pos;
	int	half;

	i = 0;
	while (s->b_cnt)
	{
		half = s->b_cnt / 2;
		max = ft_big_number_stb(s);
		pos = get_element_index(s->stb, max, s->b_pos, s);
		ft_push_max(s, &pos, &half);
	}
}
