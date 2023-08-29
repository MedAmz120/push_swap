/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:18 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/24 10:56:38 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_search_position(int *src, int t_find, int size)
{
        int     i;

        i = 0;
        while (i < size)
        {
                if (src[i] == t_find)
                        return (i);
        }
        return (-1);
}


void    ft_push_chunks(t_swp *s)
{
        int     i;
        int     j;
        int     sorted;

        while (s->acs >= 0)
	{
		sorted = ft_search_position(s->chnk[i][j], s->sta[s->sta[0]], s->acs); // take the temp chaos, pos 0 stack a, counter size of stack a
		if (sorted <= 10)
			ft_pb(s);
		else if (sorted < 0)
		{
			ft_pb(s);
			ft_rb(s);
		}
		else if (sorted > 10)
			ft_ra(s);
	}
	free(s->chnk);
	ft_push_a(s);
}

void    ft_sort_chunks(t_swp *s, size_t tab_size, int chunk_size)
{
        int     i;
        int     j;
        int     tmp;

        i = 0;
        while (i < tab_size)
        {
                j = 0;
                while (j < chunk_size)
                {
                        if (s->chnk[i][j] > s->chnk[i][j + 1])
                        {
                                tmp = s->chnk[i][j];
                                s->chnk[i][j] = s->chnk[i][j + 1];
                                s->chnk[i][j + 1] = tmp;
                                j = 0;
                        }
                        else
                                j++;
                        if (j + 1 == chunk_size)
                                break ;
                }
                i++;
        }
}

void    ft_sort_100(t_swp *s)
{
        ft_create_chunks(s, 1, s->acs);
        s->chnk[0] = (int *)malloc(sizeof(int) * s->acs);
        if (!s->chnk[0])
                quit_program(s, 0);
        ft_duplicate_stack(s->sta, s->chnk[0], s->acs);
        ft_sort_chunks(s, 1, s->acs);
        ft_push_chunks(s);
        return ;
}