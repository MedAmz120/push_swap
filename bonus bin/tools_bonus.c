/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/01 11:01:52 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	quit_program_bns(t_bns *s, int error_type)
{
	int	i;

	if (error_type == 0)
	{
		if (s->stb)
		{
			i = 0;
			while (i > s->acs + 1)
				free(s->stb[i++]);
			free(s->stb);
		}
		if (s->sta)
		{
			i = 0;
			while (i < s->acs + 1)
				free(s->sta[i++]);
			free(s->sta);
		}
		if (s->chnk)
		{
			i = 0;
			while (i < s->acs + 1)
				free(s->chnk[i++]);
			free(s->chnk);
		}
		s->sta = NULL;
		s->stb = NULL;
		s->chnk = NULL;
	}
	exit (1);
}

long	push_swap_atoi_bns(char *str)
{
	long	neg;
	long	nbr;
	int		i;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f'
		|| str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	if (nbr * neg > INT_MIN)
		return (2147483648);
	return (nbr * neg);
}