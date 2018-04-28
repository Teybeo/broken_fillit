/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:25:43 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolver.h"

#include <stdlib.h>

#include "grid.h"
#include "errors.h"
#include "piece.h"

int		is_solved(char **grid, char grid_size, t_piece *piece_array)
{
	t_pos	pos;
	char	grid_x_end;
	char	grid_y_end;

	grid_x_end = grid_size - piece_array->width;
	grid_y_end = grid_size - piece_array->height;
	pos.y = -1;
	if (piece_array->width == -1)
		return (1);
	while (++pos.y < grid_y_end)
	{
		pos.x = -1;
		while (++pos.x < grid_x_end)
		{
			if (can_place_piece(grid, piece_array->pos_array, pos.x, pos.y))
			{
				apply_piece(grid, piece_array, pos);
				if (is_solved(grid, grid_size, piece_array + 1))
					return (1);
				remove_piece(grid, piece_array->pos_array, pos);
			}
		}
	}
	return (0);
}

int		get_min_enclosing_square(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

void	resolve(t_piece_list *piece_array)
{
	t_grid	*grid;
	int		grid_size;

	grid_size = get_min_enclosing_square(piece_array->count * 4);
	while (grid_size < 52)
	{
		grid = create_grid(grid_size);
		if (is_solved(grid->data, grid->size, piece_array->array))
		{
			print_grid(grid);
			return ;
		}
		destroy_grid(grid);
		grid_size++;
	}
}
