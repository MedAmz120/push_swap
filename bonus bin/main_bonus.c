#include "../include/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_bns	swp;

	swp.arg_c = ac;
	if (ac > 1)
	{
		if (arg_check(av, ac, &swp))
		{
			swp.arg_c = swp.arg_c - 1;
			if (check_sorted(&swp))
				quit_program(&swp, 0);
			else
			{
				ft_apply_instructions(&swp);
				quit_program(&swp, 0);
			}
		}
	}
	return (0);
}