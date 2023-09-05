/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:25:38 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/05 16:37:45 by moamzil          ###   ########.fr       */
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
    int     *sta;
    int     *stb;
    int     a_pos;// for keeping a position known if don't when we do a pb it pushing same element on every operation call
    int     b_pos;
    int     acs; // ac variable acs = ac
    long    temp; // temp for atoi for int max value
    int     *chnk;
    int     b_cnt; // stack b counter if stack b has been inisialized or bein it ++ or --
    int     a_cnt; // same as b_cnt variable just is for sta it count the number of element updated on moves
    int     s_num; // For storing the small number
    int     start;
    int     stop;
} t_swp;

/* Program Function */

int     arg_check(char **av, int ac, t_swp *s); // check the hol arguments and store the int pointer into the struct
int     check_chars(char *str); // check argument charachters if it's not a valid number
int     check_duplicate(t_swp *s); //check if there is a duplicate number
long    push_swap_atoi(char *str); //for int max case returned by atoi
int     check_sorted(t_swp *s); //check if the given numbers are sorted or not
void    ft_push_swap(t_swp *s); // like oujada says it s mfezra bayna dyalach
int     check_part_sorted(t_swp *s); /* we give it a part like the three last element and it check if they are sorted on not add it for the sorting 5 element*/
void    ft_create_chunk(t_swp *s); /* Create the double pointer that will hold me the values */
void    ft_duplicate_stack(int *src, int *dest, int size); // duplicate a stack
int     get_element_index(int *src, int t_find, int pos, t_swp *s); // for pushing back to stack a the elements from stack B it return the t_find position on stack B
int     ft_big_number_stb(t_swp *s); // search for the biggest element on stack B for ft_pushto_sta function
void	quit_program(t_swp *s, int pte); // clean F* program quiting

/* Operations Functions */

void    ft_sa(t_swp *s, int msg); /* Swap the 2 first elements at sta */
void    ft_sb(t_swp *s, int msg); /* Swap the 2 first elements at stb */
void    ft_ss(t_swp *s); /* sa and sb at the same time */
void    ft_pa(t_swp *s); /* take the first element at the top of b and put it at the top of a */
void    ft_pb(t_swp *s); /* Take the first element at the top of a and put it at the top of b */
void    ft_ra(t_swp *s, int msg); /* The first element becomes the last one. */
void	ft_rb(t_swp *s, int msg); /* Shift up all elements of stack b by 1. The first element becomes the last one */
void    ft_rr(t_swp *s); /* ra and rb same time */
void    ft_rra(t_swp *s, int msg); /* Shift down all elements of stack a by 1.The last element becomes the first one */
void    ft_rrb(t_swp *s, int msg); /* Shift down all elements of stack b by 1.The last element becomes the first one */
void    ft_rrr(t_swp *s); /* rra and rrb at the same time. */

/* Sorting Functions */

void    ft_sort_3(t_swp *s); // sort 3 numbers
void    ft_sort_5(t_swp *s); // sort 5 numbers
void    ft_sort_100(t_swp *s); // sort 100 numbers
void    ft_sort_500(t_swp *s); // sort 100 numbers
void    ft_small_number_pb(int  *tab, t_swp *s); // Function to get the smallest number on the stack
void    ft_small_out(t_swp *s); // take the small number out of the stack so changing and pushing it with pb
long    ft_get_position(t_swp *s); // get the small number position
void    ft_range(t_swp *s);
void    ft_sort_chunk(t_swp *s); // sort the chunks normal sort
void    ft_pushto_stb(t_swp *s); // push chunk after sorting;
void    ft_pushto_sta(t_swp *s); // push back elements from stack B to stack A
void    ft_push_max(t_swp *s, int *pos, int *half); // rotate and push the max from stack B to stack A
#endif
