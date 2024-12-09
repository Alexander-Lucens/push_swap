#include "../push_swap.h"

/**
 * s1 - list where we grab fircs char and pushing in to s2
 * s2 - destenation list
 * if s1 in empty do nothing
 * s1 - from s2 - to
 */
void	push(int *s1, int *s2)
{
	int temp;

	if (ft_numlistlen(s1) > 0)
	{
		temp = s1[0];
		s1 = ft_sublist(s1, 1);
		s2 = ft_addfront(temp, s2);
	}
}

void	pb(int *a, int *b)
{
	push(a, b);
}

void	pa(int *a, int *b)
{
	push(b, a);
}