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

/*int    get_element_index(int *src, int t_find, int pos, t_swp *s)
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
}*/

/*void    ft_push_max(t_swp *s, int *pos, int *half)
{
    int size;

    if ((*pos) >= (*half))
    {
        size = s->b_cnt;
        while (size > (*pos))
        {
            ft_rrb(s);
            size--;
        }
    }
    else if ((*pos) < (*half))
    {
        size = 0;
        while (size < (*pos))
        {
            ft_rb(s);
            size++;
        }
    }
    ft_pa(s);
}

void    ft_pushto_sta(t_swp *s)
{
    int max;
    int pos;
    int half;

    while (s->b_cnt)
    {
        half = s->b_cnt / 2;
        max = ft_big_number_stb(s);
        pos = get_element_index(s->stb, max, s->b_pos, s);
        ft_push_max(s, &pos, &half);
        if (s->a_cnt >= 2)
        {
            if (s->sta[s->a_pos] < s->sta[s->a_pos + 1])
            {
                ft_sa(s); // Swap the top two elements
            }
        }

        if (s->b_cnt == 0)
            break;
    }
}*/

int ft_big_number_stb(t_swp *s)
{
    int max = INT_MIN;  // start with the minimum possible value
    int i = s->b_pos;
    int count = 0;

    while (count < s->b_cnt)
    {
        if (s->stb[i] > max)
            max = s->stb[i];
        
        i = (i + 1) % s->acs;  // wrap-around
        count++;
    }

    return max;
}

int    get_element_index(int *src, int t_find, int pos, t_swp *s)
{
    int count = 0;
    int initial_pos = pos;

    while (count < s->b_cnt)
    {
        if (src[pos] == t_find)
            return (pos);
        
        pos = (pos + 1) % s->acs;  // wrap-around
        if (pos == initial_pos)
            break;
            
        count++;
    }

    return -1; // return an invalid index if element not found
}


void    ft_push_max(t_swp *s, int *pos, int *half)
{
    int size;

    // If max is in the second half of stack B
    if ((*pos) >= (*half))
    {
        size = s->b_cnt;
        // Rotate backwards to get max to the top
        while (size > (*pos))
        {
            ft_rrb(s);
            size--;
        }
    }
    // If max is in the first half of stack B
    else if ((*pos) < (*half))
    {
        size = 0;
        // Rotate forwards to get max to the top
        while (size < (*pos))
        {
            ft_rb(s);
            size++;
        }
    }
    ft_pa(s);  // Push the element to stack A
}

void    ft_pushto_sta(t_swp *s)
{
    int max;
    int pos;
    int half;

    while (s->b_cnt)
    {
        half = s->b_cnt / 2;
        max = ft_big_number_stb(s);  // find the max element in stack B
        pos = get_element_index(s->stb, max, s->b_pos, s); // find its position
        ft_push_max(s, &pos, &half); // Push it to stack A using optimized rotations
        
        if (s->b_cnt == 0)
            break;
    }
}
