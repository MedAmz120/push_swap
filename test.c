#include <stdio.h>

int ft_big_number_stb(int *stb)
{
    int i = 8;
    int j;
    int max = stb[i];  // Initialize max with the first element in stack b

    while (i < 10)
    {
        j = i;
        while (j < 10)
        {
            if (stb[j] > max)
            {
                max = stb[j];
            }
            j++;
        }
        i++;
    }
    return max;  // Return the biggest number found
}

void	ft_rb(int *stb)
{
	int	i;
	int	tmp;

	i = 2;
	tmp = stb[0];
	while (i < 10)
	{
		stb[i] = stb[i + 1];
		i++;
	}
	stb[10 - 1] = tmp;
}


int main()
{
    int sta[10] = {8,102,5,3,6,4,1,101,0,9};
    // int max = ft_big_number_stb(sta);
    ft_rb(sta);
      int i = 0;
        printf("------------------\n");
        while (i < 10)
        {
                printf("[%d] -> %d\n", i, sta[i]);
                i++;
        };
}