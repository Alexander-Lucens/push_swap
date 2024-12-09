#include "../push_swap.h"

void	swap(int *s1)
{
	int temp;

	if (ft_numlistlen(s1) >= 2)
	{
		temp = s1[0];
		s1[0] = s1[1];
		s1[1] = temp;
	}
}

void	sa(int *a)
{
	swap(a);
}

void	sb(int *b)
{
	swap(b);
}

void	ss(int *a, int *b)
{
	swap(a);
	swap(b);
}