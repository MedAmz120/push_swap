#include <stdio.h>
#include <stdlib.h>

void ft_rrb(int *stb, int b_cnt, int b_pos, int acs)
{
	int	i;
	int pos;
	int hold;
	int *temp;

	i = 0;
	hold = stb[acs - 1];
	pos = b_pos;
	temp = (int *)malloc(sizeof(int) * (b_cnt - 1));
	while (i < b_cnt - 1)
	{
		temp[i++] = stb[pos++];
	}
	stb[b_pos] = hold;
	i = 0;
	pos = 1;
	while (i < b_cnt - 1)
	{
		stb[b_pos + pos] = temp[i];
		pos++;
		i++; 
	}
}


int main()
{
    int sta[10] = {8,102,5,3,6,4,1,101,0,9};
    ft_rrb(sta, 7, 3, 10);
    int i = 0;
        printf("------------------\n");
        while (i < 10)
        {
                printf("[%d] -> %d\n", i, sta[i]);
                i++;
        };
}