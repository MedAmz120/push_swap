/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:56 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 21:13:55 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int     ft_apply_2(char *str, t_bns *s)
{
    if (str[0] == 'r' && str[1] == 'b')
        ft_rb(s);
    else if (str[0] == 'r' && str[1] == 'r')
        ft_rr(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
        ft_rra(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
        ft_rrb(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
        ft_rrr(s);
    else
        return (0);
    return (1);
}

int    ft_apply(char *str, t_bns *s)
{
    if (str[0] == 's' && str[1] == 'a')
        ft_sa(s);
    else if (str[0] == 's' && str[1] == 'b')
        ft_sb(s);
    else if (str[0] == 's' && str[1] == 's')
        ft_ss(s);
    else if (str[0] == 'p' && str[1] == 'a')
        ft_pa(s);    
    else if (str[0] == 'p' && str[1] == 'b')
        ft_pb(s);
    else if (str[0] == 'r' && str[1] == 'a')
        ft_ra(s);
    else
        if (!ft_apply_2(str, s))
            return (0);
    return (1);
}

void    ft_apply_instructions(t_bns *s)
{
    char    *buff;
    size_t  bytes;

    s->stb = (int *)malloc(sizeof(int) * s->arg_c);
	if (!s->stb)
		quit_program_bns (s, 0);
    buff = ft_calloc(sizeof(char), 5);
    if (!buff)
        quit_program_bns(s, 0);
    while (1)
    {
        bytes = read(0, buff, 5);
        if (bytes == 0)
            break ;
        if (!ft_apply(buff, s))
        {
            ft_printf("Error\n");
            quit_program_bns (s, 0);
        }
    }
    free(buff);
    quit_program_bns (s, 0);
}