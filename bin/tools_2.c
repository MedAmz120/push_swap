/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:25:29 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/01 11:01:52 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    get_element_index(int *src, int t_find, int pos, t_swp *s)
{
    int i;
    int count;

    count = 0;
    while (count <= s->b_cnt)
    {
        if (src[pos] == t_find)
            return (pos);
        pos++;
        count++;
    }
    return (pos);
}

int ft_big_number_stb(t_swp *s)
{
    int i = s->b_pos;
    int j;
    int max = s->stb[i];

    while (i < s->acs)
    {
        j = i;
        while (j < s->acs)
        {
            if (s->stb[j] > max)
                max = s->stb[j];
            j++;
        }
        i++;
    }
    return (max);
}

void    ft_push_max(t_swp *s, int *pos, int *half)
{
    int size;
    int temp;
    int i;

    temp = (*pos);
    if (((*pos) - s->b_pos) > (*half))
    {
        i = 0;
        size = s->b_cnt - temp + s->b_pos;
        while (i < size)
        {
            ft_rrb(s);
            i++;
        }
    }
    else
    {
        size = (*pos) - s->b_pos;
        while (size > 0)
        {
            ft_rb(s);
            size--;
        }
    }
    ft_pa(s);
}

void    ft_pushto_sta(t_swp *s)
{
    int i;
    int max;
    int pos;
    int half;

    i = 0;
    while (s->b_cnt)
    {
        half = s->b_cnt / 2;
        max = ft_big_number_stb(s);
        pos = get_element_index(s->stb, max, s->b_pos, s);
        // printf("------> STACK B Before adding :\n");
        // i = 0;
        // while (i < s->acs)
        // {
        //     printf("[%d] -> %d\n", i, s->stb[i]);
        //     i++;
        // };
        // printf("Max is \"%d\" in position [%d] and there is %d element left in stack B mean b->cnt is = %d\n", max, pos, s->b_cnt, s->b_cnt);
        ft_push_max(s, &pos, &half);
        // printf("------> STACK B After adding :\n");
        // i = 0;
        // while (i < s->acs)
        // {
        //     printf("[%d] -> %d\n", i, s->stb[i]);
        //     i++;
        // };
        // printf("\n\n\n\n\n");
    }
}