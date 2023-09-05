/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:25:41 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 16:37:02 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicate(t_swp *s)
{
	int	i;
	int	y;

	i = 0;
	while (i < s->acs - 1)
	{
		y = i + 1;
		if (s->sta[i] > 2147483647)
			return (0);
		while (y < s->acs - 1)
		{
			if (s->sta[y] == s->sta[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_chars(char	*str)
{
	int	i;
	int	error;
	int	count;

	i = -1;
	count = 0;
	error = 1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != '-')
			error = 0;
		if (str[i] == '-')
			count++;
	}
	if (str[0] == '-' && str[1] == '\0') // ./push_swap 56 78 -
		error = 0;
	if (count > 1)
		error = 0;
	if (error == 0)
		return (0);
	return (1);
}

int	arg_check(char **av, int ac, t_swp *s)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	s->sta = (int *)malloc(sizeof(int) * ac - 1);
	if (!s->sta)
		exit (1);
	while (av[++y])
		if (!(check_chars(av[y])))
				quit_program (s, 404);
	y = -1;
	while (i < ac)
	{
		s->temp = push_swap_atoi(av[i++]);
		if (s->temp <= 2147483647)
			s->sta[++y] = s->temp;
		else
			quit_program (s, 404);
	}
	if (!(check_duplicate(s)))
		quit_program (s, 404);
	return (1);
}
