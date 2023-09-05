
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define INT_MIN 2147483647

# include <stdlib.h>
# include <stdio.h>
# include "../src/ft_printf/ft_printf.h"
# include "../src/libft/libft.h"

typedef struct push_bonus
{
    int     *sta;
    int     *stb;
    int     a_pos;// for keeping a position known if don't when we do a pb it pushing same element on every operation call
    int     b_pos;
    int     arg_c;
    long    temp; // temp for atoi for int max value
    int     b_cnt; // stack b counter if stack b has been inisialized or bein it ++ or --
    int     a_cnt; // same as b_cnt variable just is for sta it count the number of element updated on moves
} t_bns;

/* Program Function */

int     arg_check_bns(char **av, int ac, t_bns *s);
int     check_chars_bns(char *str);
int     check_duplicate_bns(t_bns *s);
long    push_swap_atoi_bns(char *str);
int     check_sorted_bns(t_bns *s);
void    ft_apply_instructions(t_bns *s);
int     ft_apply(char *str, t_bns *s);
void	quit_program_bns(t_bns *s, int pte);

/* Operations Functions */

void    ft_sa(t_bns *s); /* Swap the 2 first elements at sta */
void    ft_sb(t_bns *s); /* Swap the 2 first elements at stb */
void    ft_ss(t_bns *s); /* sa and sb at the same time */
void    ft_pa(t_bns *s); /* take the first element at the top of b and put it at the top of a */
void    ft_pb(t_bns *s); /* Take the first element at the top of a and put it at the top of b */
void    ft_ra(t_bns *s); /* The first element becomes the last one. */
void	ft_rb(t_bns *s); /* Shift up all elements of stack b by 1. The first element becomes the last one */
void    ft_rr(t_bns *s); /* ra and rb same time */
void    ft_rra(t_bns *s); /* Shift down all elements of stack a by 1.The last element becomes the first one */
void    ft_rrb(t_bns *s); /* Shift down all elements of stack b by 1.The last element becomes the first one */
void    ft_rrr(t_bns *s); /* rra and rrb at the same time. */

#endif