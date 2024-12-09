#include "../push_swap.h"

void	reverse_rotate(int *s)
{
	int	*temp;
	size_t len;
	size_t i;

	len = ft_numlistlen(s);
	temp = malloc(sizeof(int) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = NULL;
	temp[0] = s[len - 1];
	i = 1;
	while (i < len)
		temp[i] = s[i - 1];
	free(s);
	s = temp;
}

void	rra(int *a)
{
	reverse_rotate(a);
}

void	rrb(int *b)
{
	reverse_rotate(b);
}

void	rrr(int *a, int *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}