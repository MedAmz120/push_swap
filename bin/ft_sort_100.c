/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:18 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/01 10:54:26 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_search_position(int *src, int t_find, int pos, int size)
{
        int     start;
        int     stop;

        start = (pos / size) * size;
        stop = start + size - 1;
        while (start <= stop)
        {
                if (src[start] == t_find)
                        return (1);
                stop++;
        }
        return (0);
}

void    ft_pushto_stb(t_swp *s)
{
        int     i;
        int     pos;

        i = 0;
        pos = 0;
        while (i < s->acs)
        {
                if (ft_search_position(s->chnk, s->sta[i], pos, CHUNK_SIZE))
                        printf("I HAVE FOUND IT\n");
                else
                        printf("I HAVE NOT FOUND IT\n");
                i++;
                pos++;
        }
}

void    ft_sort_chunk(t_swp *s)
{
        int     i;
        int     tmp;

        i = 0;
        while (i < s->acs)
        {
                if (s->chnk[i] > s->chnk[i + 1])
                {
                        tmp = s->chnk[i];
                        s->chnk[i] = s->chnk[i + 1];
                        s->chnk[i + 1] = tmp;
                        i = 0;
                }
                else
                        i++;
                if (i + 1 == s->acs)
                        break ;
        }
}

void    ft_sort_100(t_swp *s)
{
        ft_create_chunk(s);
        ft_duplicate_stack(s->sta, s->chnk, s->acs);
        ft_sort_chunk(s);
        ft_pushto_stb(s);
}