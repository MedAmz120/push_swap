/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 23:17:15 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	quit_program_bns(t_bns *s, int pte)
{
	int	i;

	if (s->stb != NULL)
		free(s->stb);
	if (s->sta != NULL)
		free(s->sta);
	if (s->ca_se == 1)
	{
		i = 0;
		while (i <= s->arg_c)
			free(s->avg_b[i++]);
		free(s->avg_b);
	}
	s->sta = NULL;
	s->stb = NULL;
	s->avg_b = NULL;
	if (pte == 404)
		ft_putstr_fd("Error\n", 2);
	if (pte == 1)
		ft_printf("OK\n", 2);
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

void	check_spaces_bns(char *str, t_bns *s)
{
	int		i;
	size_t	space;

	i = -1;
	space = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
			space++;
		else
			break ;
	}
	if (space == ft_strlen(str))
		quit_program_bns (s, 404);
}

int	ft_word_cswp_bns(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			cnt++;
		i++;
	}
	return (cnt);
}

void	check_double_quo_bns(char *str, t_bns *s, int *ac)
{
	int		i;
	char	**tmp;
	size_t	space;

	i = 1;
	(*ac) = ft_word_cswp_bns(str, ' ') + 1;
	check_spaces_bns(str, s);
	if ((*ac) == 2)
		quit_program_bns (s, 1);
	else
		tmp = ft_split(str, ' ');
	s->avg_b = tmp;
	if (!s->avg_b)
		quit_program_bns (s, 404);
	s->ca_se = 1;
}
