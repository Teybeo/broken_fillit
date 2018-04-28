/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:07:21 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*my_realloc(char *buffer, int size, int size_increase)
{
	char	*new_buffer;
	int		new_size;
	int		i;

	new_size = size + size_increase;
	if (!(new_buffer = malloc(sizeof(char) * new_size)))
		exit(0);
	i = 0;
	while (i < size)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*read_file(int fd)
{
	int		space_left;
	int		buffer_offset;
	char	*buffer;
	ssize_t	bytes_read;

	if (!(buffer = malloc(sizeof(char) * CHUNK_READ_SIZE)))
		exit(0);
	space_left = CHUNK_READ_SIZE;
	buffer_offset = 0;
	while ((bytes_read = read(fd, buffer + buffer_offset, space_left)) > 0)
	{
		buffer_offset += bytes_read;
		space_left -= bytes_read;
		if (space_left < MIN_BUF_SPACE_TRESHOLD)
		{
			buffer = my_realloc(buffer, (buffer_offset + space_left),
								CHUNK_READ_SIZE);
			space_left += CHUNK_READ_SIZE;
		}
	}
	buffer[buffer_offset] = '\0';
	return (buffer);
}
