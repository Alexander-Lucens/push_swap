/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:43:03 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:53 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*safe_free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

/**
 *	Read file with current file descriptor, while do not meat char '\n'
 *	When it is apears return string, which was joined with all sub strings
 *	readed by th length of buffer size
 */
static char	*readline(int fd, char *output)
{
	ssize_t	bytes_read;
	char	*vault;

	bytes_read = 1;
	vault = malloc(BUFFER_SIZE + 1);
	if (!vault)
		return (safe_free(&output));
	while (bytes_read > 0 && !ft_strchr(output))
	{
		bytes_read = read(fd, vault, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			vault[bytes_read] = '\0';
			output = ft_strjoin(output, vault);
			if (!output)
				return (safe_free(&vault));
		}
	}
	safe_free(&vault);
	if (bytes_read == -1)
		return (safe_free(&output));
	return (output);
}

/**
 *	Go thrue prewiosly created string, splint it to 2 part on char '\n'
 *	Clean prewious buffer string, and write inside what is left after '\n'  
 *	Return allocated memory with string from start before position of '\n' + 1
 */
static char	*write_line(char **buffer)
{
	char	*output;
	char	*temp_buffer;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	if (ft_strchr(*buffer) != NULL)
		len = ft_strchr(*buffer) - *buffer;
	else
		len = ft_strlen(*buffer);
	output = ft_substr(*buffer, 0, len);
	if (!output)
		return (safe_free(buffer));
	if (ft_strchr(*buffer))
		temp_buffer = ft_strdup(ft_strchr(*buffer));
	else
		temp_buffer = NULL;
	safe_free(buffer);
	*buffer = temp_buffer;
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(buffer[fd]) || !buffer[fd])
		buffer[fd] = readline(fd, buffer[fd]);
	if (ft_strlen(buffer[fd]) == 0 || buffer[fd] == NULL)
		return (safe_free(&buffer[fd]));
	line = write_line(&buffer[fd]);
	if (!line)
		return (safe_free(&buffer[fd]));
	return (line);
}
