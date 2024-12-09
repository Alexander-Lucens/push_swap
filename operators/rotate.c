#include "../push_swap.h"

void	rotate(int *s)
{
	int	*temp;
	size_t len;
	size_t i;

	len = ft_numlistlen(s);
	temp = malloc(sizeof(int) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = NULL;
	temp[len - 1] = s[0];
	i = 0;
	while (i < len -1)
		temp[i] = s[i + 1];
	free(s);
	s = temp;
}

void	ra(int *a)
{
	rotate(a);
}

void	rb(int *b)
{
	rotate(b);
}

void	rr(int *a, int *b)
{
	rotate(a);
	rotate(b);
}