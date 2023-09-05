

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

int     arg_check(char **av, int ac, t_bns *s);
int     check_chars(char *str);
int     check_duplicate(t_bns *s);
long    push_swap_atoi(char *str);
int     check_sorted(t_bns *s);
void    ft_apply_instructions(t_bns *s);
void	quit_program(t_bns *s, int error_type);

/* Operations Functions */