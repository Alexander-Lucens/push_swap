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

int	*ft_sublist(int *s, unsigned int start)
{
	size_t	i;
	char	*out;
	size_t	len;

	out = NULL;
	if (!s)
		return (NULL);
	len = ft_numlistlen(s);
	out = malloc(sizeof(int) * len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len - 1 && s[i + start] != '\0')
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}
