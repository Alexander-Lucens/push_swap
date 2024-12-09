/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2024/11/24 09:43:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_addfront(int x, int *s)
{
	size_t	i;
	char	*out;
	size_t	len;

	out = NULL;
	if (!s || !x)
		return (NULL);
	len = ft_numlistlen(s);
	out = malloc(sizeof(int) * len + 2);
	if (!out)
		return (NULL);
	out[0] = x;
	i = 1;
	while (s[i] != '\0')
	{
		out[i] = s[i - 1];
		i++;
	}
	out[i] = '\0';
	return (out);
}
