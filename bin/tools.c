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

#include "../include/push_swap.h"

void	quit_program(t_swp *s, int error_type)
{
	int	i;

	i = 0;
	if (error_type == 0)
	{
		free(s->stb);
		free(s->sta);
		free(s->chnk);
		s->sta = NULL;
		s->stb = NULL;
		s->chnk = NULL;
	}
	exit (1);
}

long	push_swap_atoi(char *str)
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

void    ft_duplicate_stack(int *src, int *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void    ft_create_chunks(t_swp *s)
{
	int	i;

	i = 0;
	if (s->acs % CHUNK_SIZE != 0)
		s->n_chnk = (s->acs / CHUNK_SIZE) + 1;
	else if (s->acs <= CHUNK_SIZE)
		s->n_chnk = 1;
	else
		s->n_chnk = s->acs / CHUNK_SIZE;
    s->chnk = (int **)malloc(sizeof(int *) * s->n_chnk);
    if (!s->chnk)
    	quit_program(s, 0);
	while (i < s->n_chnk)
	{
		s->chnk[i] = (int *)malloc(sizeof(int) * CHUNK_SIZE);
		if (!s->chnk[i])
			quit_program(s, 0);
		i++;
	}
}

void	ft_chunking(t_swp *s)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	while (i < s->acs)
	{
		y = 0;
		while (y < CHUNK_SIZE)
		{
			s->chnk[x][y] = s->sta[i];
			y++;
			i++;
		}
		x++;
	}
}