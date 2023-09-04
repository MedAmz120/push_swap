/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:38:43 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/04 11:45:57 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_swp *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->sta[s->a_pos];
	while (i < s->a_cnt)
	{
		s->sta[s->a_pos + i] = s->sta[s->a_pos + i + 1];
		i++;
	}
	s->sta[s->acs - 1] = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_swp *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->stb[s->b_pos];
	while (i < s->b_cnt)
	{
		s->stb[s->b_pos + i] = s->stb[s->b_pos + i + 1];
		i++;
	}
	s->stb[s->acs - 1] = tmp;
	ft_printf("rb\n");
}

void	ft_rr(t_swp *s)
{
	ft_ra(s);
	ft_rb(s);
}

void	ft_rra(t_swp *s)
{
	int	i;
	int	j;
	int	c;
	int	tmp;

	j = 0;
	c = 0;
	i = s->acs - 1;
	tmp = s->sta[i]; // Save the last element
	while (c < s->a_cnt - 1)
	{
		s->sta[i] = s->sta[(i - 1 + s->acs) % s->acs]; // Move elements one position to the right
		i = (i - 1 + s->acs) % s->acs;
		c++;
	}
	s->sta[s->a_pos] = tmp; // Place the saved element in the correct position
	ft_printf("rra\n");
}

/*void	ft_rrb(t_swp *s)
{
	int	i;
	int	c;
	int	j;
	int	tmp;

	j = 0;
	c = 1;
	i = s->acs - 2;
	tmp = s->stb[s->acs - 1];
	while (c <= s->b_cnt)
	{
		s->stb[s->acs - c] = s->stb[i];
		c++;
		i--;
	}
	s->stb[s->b_pos] = tmp;
	ft_printf("rrb\n");
}*/

void ft_rrb(t_swp *s)
{
	int	i;
	int pos;
	int hold;
	int *temp;

	i = 0;
	hold = s->stb[s->acs - 1];
	pos = s->b_pos;
	temp = (int *)malloc(sizeof(int) * (s->b_cnt - 1));
	while (i < s->b_cnt - 1)
	{
		temp[i++] = s->stb[pos++];
	}
	s->stb[s->b_pos] = hold;
	i = 0;
	pos = 1;
	while (i < s->b_cnt - 1)
	{
		s->stb[s->b_pos + pos] = temp[i];
		pos++;
		i++; 
	}
	ft_printf("rrb\n");
}
