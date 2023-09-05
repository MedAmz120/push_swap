/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 17:15:18 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quit_program(t_swp *s, int pte)
{
	int	i;

	s->stb = NULL;
	if (s->stb == NULL)
		free(s->stb);
	if (s->sta != NULL)
		free(s->sta);
	if (s->chnk != NULL)
		free(s->chnk);
	s->sta = NULL;
	s->stb = NULL;
	s->chnk = NULL;
	if (pte == 404)
		ft_printf("Error\n");
	while (1)
		printf("");
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

void    ft_create_chunk(t_swp *s)
{
    s->chnk = (int *)malloc(sizeof(int *) * s->acs);
    if (!s->chnk)
    	quit_program(s, 0);
}