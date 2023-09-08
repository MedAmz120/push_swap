/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:29:34 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 19:51:26 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_word_cswp(char const *s, char c)
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

void	check_spaces(char *str, t_swp *s)
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
		quit_program (s, 404);
}
