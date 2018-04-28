/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:53:32 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

#include "errors.h"

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

t_grid	*create_grid(int size)
{
	t_grid	*grid;
	int		i;

	grid = malloc(sizeof(t_grid));
	if (grid == NULL)
		exit_with_msg(ERROR_MALLOC_FAIL);
	grid->size = size;
	grid->data = malloc(sizeof(char*) * grid->size);
	if (grid->data == NULL)
		exit_with_msg(ERROR_MALLOC_FAIL);
	i = 0;
	while (i < size)
	{
		grid->data[i] = malloc(sizeof(char) * size);
		if (grid->data[i] == NULL)
			exit_with_msg(ERROR_MALLOC_FAIL);
		ft_memset(grid->data[i], '.', size);
		i++;
	}
	return (grid);
}

void	destroy_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
		free(grid->data[i++]);
	free(grid->data);
}

/*
** We pass x and y as seperate values instead of t_pos coz 30% faster
*/

int		can_place_piece(char **data, t_pos pos_array[4], char x, char y)
{
	if (data[y + pos_array[0].y][x + pos_array[0].x] != '.')
		return (0);
	if (data[y + pos_array[1].y][x + pos_array[1].x] != '.')
		return (0);
	if (data[y + pos_array[2].y][x + pos_array[2].x] != '.')
		return (0);
	if (data[y + pos_array[3].y][x + pos_array[3].x] != '.')
		return (0);
	return (1);
}

void	apply_piece(char **data, t_piece *p, t_pos pos)
{
	data[pos.y + p->pos_array[0].y][pos.x + p->pos_array[0].x] = p->c;
	data[pos.y + p->pos_array[1].y][pos.x + p->pos_array[1].x] = p->c;
	data[pos.y + p->pos_array[2].y][pos.x + p->pos_array[2].x] = p->c;
	data[pos.y + p->pos_array[3].y][pos.x + p->pos_array[3].x] = p->c;
}

void	remove_piece(char **data, t_pos pos_array[4], t_pos pos)
{
	data[pos.y + pos_array[0].y][pos.x + pos_array[0].x] = '.';
	data[pos.y + pos_array[1].y][pos.x + pos_array[1].x] = '.';
	data[pos.y + pos_array[2].y][pos.x + pos_array[2].x] = '.';
	data[pos.y + pos_array[3].y][pos.x + pos_array[3].x] = '.';
}
