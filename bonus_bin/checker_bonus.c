/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:56 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 22:56:01 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int    ft_apply(char *str, t_bns *s)
{
    if (strcmp(str, "sa\n"))
        ft_sa(s);
    else if (strcmp(str, "sb\n"))
        ft_sb(s);
    else if (strcmp(str, "ss\n"))
        ft_ss(s);
    else if (strcmp(str, "ra\n"))
        ft_ra(s);
    else if (strcmp(str, "rb\n"))
        ft_rb(s);
    else if (strcmp(str, "rr\n"))
        ft_rr(s);
    else if (strcmp(str, "rra\n"))
        ft_rra(s);
    else if (strcmp(str, "rrb\n"))
        ft_rrb(s);
    else if (strcmp(str, "rrr\n"))
        ft_rrr(s);
    else
        return (0);
    return (1);
}

void    ft_apply_instructions(t_bns *s)
{
    char    *line;
    size_t  bytes;

    s->stb = (int *)malloc(sizeof(int) * s->arg_c);
	if (!s->stb)
		quit_program_bns (s, 0);
    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break ;
        if (!ft_apply(line, s))
        {
            free(line);
            ft_putstr_fd("Error\n", 2);
            quit_program_bns (s, 0);
        }
        free(line);
    }
}