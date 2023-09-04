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

// int    ft_big_number_stb(t_swp *s)
// {
//     int i;
//     int max;
    
//     i = s->b_pos;
//     max = s->stb[i];
//     while (i < s->acs)
//     {
//         if (s->stb[i] > max)
//             max = s->stb[i];
//         i++;
//     }
//     return (max);
// }

int ft_big_number_stb(t_swp *s)
{
    int i = s->b_pos;
    int j;
    int max = s->stb[i];  // Initialize max with the first element in stack b

    while (i < s->acs)
    {
        j = s->b_pos;
        while (j < s->acs)
        {
            if (s->stb[j] > max)
            {
                max = s->stb[j];
            }
            j++;
        }
        i++;
    }

    return max;  // Return the biggest number found
}


void    ft_pushto_sta(t_swp *s)
{
    printf("----> %d\n", ft_big_number_stb(s));
    return ;
}