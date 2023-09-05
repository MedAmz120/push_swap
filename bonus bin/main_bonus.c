#include "../include/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_bns	swp;

	swp.arg_c = ac;
	if (ac > 1)
	{
		if (arg_check_bns(av, ac, &swp))
		{
			swp.arg_c = swp.arg_c - 1;
			if (check_sorted_bns(&swp))
				quit_program_bns (&swp, 0);
			else
			{
				ft_apply_instructions(&swp);
				if (check_sorted_bns(s))
					ft_printf("OK\n");
				else
					ft_printf("KO\n");
				quit_program_bns (&swp, 0);
			}
		}
	}
	return (0);
}