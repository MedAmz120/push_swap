/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:45 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 19:06:02 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_duplicate_bns(t_bns *s)
{
	int	i;
	int	y;

	i = 0;
	while (i < s->arg_c - 1)
	{
		y = i + 1;
		if (s->sta[i] > 2147483647)
			return (0);
		while (y < s->arg_c - 1)
		{
			if (s->sta[y] == s->sta[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_chars_bns(char *str)
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
	if (str[0] == '-' && str[1] == '\0')
		error = 0;
	if (count > 1)
		error = 0;
	if (error == 0)
		return (0);
	return (1);
}

int	che_rg_bns(char *str)
{
	return (!(ft_strlen(str) > 11));
}

int	arg_check_bns(char **av, int ac, t_bns *s)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	s->sta = (int *)malloc(sizeof(int) * ac);
	if (!s->sta)
		exit (1);
	while (av[++y])
		if (!(check_chars_bns(av[y]) && che_rg_bns(av[y])))
			quit_program_bns (s, 404);
	y = -1;
	while (i < ac)
	{
		s->temp = push_swap_atoi_bns(av[i++]);
		if (s->temp <= 2147483647)
			s->sta[++y] = s->temp;
		else
			quit_program_bns (s, 404);
	}
	if (!(check_duplicate_bns(s)))
		quit_program_bns (s, 404);
	return (1);
}
