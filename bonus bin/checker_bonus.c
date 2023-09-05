

#include "../include/push_swap_bonus.h"

int     ft_apply_2(char *str, t_bns *s)
{
    if (str[0] == 'r' && str[1] == 'b')
        ft_rb(s);
    else if (str[0] == 'r' && str[1] == 'r')
        ft_rr(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
        ft_rra(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
        ft_rrb(s);
    else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
        ft_rrr(s);
    else
        return (0);
}

int    ft_apply(char *str, t_bns *s)
{
    if (str[0] == 's' && str[1] == 'a')
        ft_sa(s);
    else if (str[0] == 's' && str[1] == 'b')
        ft_sb(s);
    else if (str[0] == 's' && str[1] == 's')
        ft_ss(s);
    else if (str[0] == 'p' && str[1] == 'a')
        ft_pa(s);    
    else if (str[0] == 'p' && str[1] == 'b')
        ft_pb(s);
    else if (str[0] == 'r' && str[1] == 'a')
        ft_ra(s);
    else
        if (!ft_apply_2(str, s))
            return (0);
    return (1);
}

void    ft_apply_instructions(t_bns *s)
{
    char *buff;

    s->stb = (int *)malloc(sizeof(int) * s->acs + 1);
	if (!s->stb)
		quit_program_bns (s, 0);
    buff = ft_calloc(sizeof(char) * 4);
    if (!buff)
        quit_program_bns(s, 0);
    while (1)
    {
        read(0, buff, 5);
        if (!buff)
            break ;
        if (!ft_apply(buf, s))
        {
            ft_printf("Error\n");
            quit_program_bns (s, 0);
        }
    }
    free(buff);
    quit_program_bns (s, 0);
}