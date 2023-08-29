/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/26 17:27:23 by moamzil          ###   ########.fr       */
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
		s->sta = NULL;
		s->stb = NULL;
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

void    ft_create_chunks(t_swp *s, size_t tab_size, int chunk_size)
{
        s->chnk = (int **)malloc(sizeof(int *) * tab_size);
        if (!s->chnk)
                quit_program(s, 0);
        return ;
}
