/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:25:38 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 18:01:00 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define RANGE_SIZE_100 15
# define RANGE_SIZE_500 25
# define INT_MIN 2147483647

# include <stdlib.h>
# include <stdio.h>
# include "../src/ft_printf/ft_printf.h"
# include "../src/libft/libft.h"

typedef struct push_swap
{
	int		*sta;
	int		*stb;
	int		a_pos;
	int		b_pos;
	int		acs;
	long	temp;
	int		*chnk;
	int		b_cnt;
	int		a_cnt;
	int		s_num;
	int		start;
	int		stop;
}	t_swp;

/* Program Function */

int		arg_check(char **av, int ac, t_swp *s);
int		check_chars(char *str);
int		check_duplicate(t_swp *s);
long	push_swap_atoi(char *str);
int		check_sorted(t_swp *s);
void	ft_push_swap(t_swp *s);
int		check_part_sorted(t_swp *s);
void	ft_create_chunk(t_swp *s);
void	ft_duplicate_stack(int *src, int *dest, int size);
int		get_element_index(int *src, int t_find, int pos, t_swp *s);
int		ft_big_number_stb(t_swp *s);
void	quit_program(t_swp *s, int pte);

/* Operations Functions */

void	ft_sa(t_swp *s, int msg);
void	ft_sb(t_swp *s, int msg);
void	ft_ss(t_swp *s);
void	ft_pa(t_swp *s);
void	ft_pb(t_swp *s);
void	ft_ra(t_swp *s, int msg);
void	ft_rb(t_swp *s, int msg);
void	ft_rr(t_swp *s);
void	ft_rra(t_swp *s, int msg);
void	ft_rrb(t_swp *s, int msg);
void	ft_rrr(t_swp *s);

/* Sorting Functions */

void	ft_sort_3(t_swp *s);
void	ft_sort_5(t_swp *s);
void	ft_sort_100(t_swp *s);
void	ft_sort_500(t_swp *s);
void	ft_small_number_pb(int *tab, t_swp *s);
void	ft_small_out(t_swp *s);
long	ft_get_position(t_swp *s);
void	ft_range(t_swp *s);
void	ft_sort_chunk(t_swp *s);
void	ft_pushto_stb(t_swp *s);
void	ft_pushto_sta(t_swp *s);
void	ft_push_max(t_swp *s, int *pos, int *half);
#endif
