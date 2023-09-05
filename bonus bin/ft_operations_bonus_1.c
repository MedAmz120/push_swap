/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:07 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/02 12:41:10 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ft_sa(t_bns *s)
{
	int	tmp;

	if (s->a_cnt > 1)
	{
		tmp = s->sta[s->a_pos];
		s->sta[s->a_pos] = s->sta[s->a_pos + 1];
		s->sta[s->a_pos + 1] = tmp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_bns *s)
{
	int	tmp;

	if (s->b_cnt > 1)
	{
		tmp = s->stb[s->b_pos];
		s->stb[s->b_pos] = s->stb[s->b_pos + 1];
		s->stb[s->b_pos + 1] = tmp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_bns *s)
{
	ft_sa(s);
	ft_sb(s);
}

void	ft_pa(t_bns *s)
{
	if (s->b_cnt < 1)
		return ;
	s->sta[s->a_pos - 1] = s->stb[s->b_pos];
	s->stb[s->b_pos] = 9999;
	s->b_pos++;
	s->a_pos--;
	s->a_cnt++;
	s->b_cnt--;
	ft_printf("pa\n");
}

void	ft_pb(t_bns *s)
{
	if (s->a_cnt < 1)
		return ;
	if (s->b_cnt != s->acs)
		s->b_pos--;
	s->stb[s->b_pos] = s->sta[s->a_pos];
	s->a_pos++;
	s->a_cnt--;
	s->b_cnt++;
	ft_printf("pb\n");
}