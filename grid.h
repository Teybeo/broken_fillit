/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:53:58 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "piece.h"

struct	s_grid {
	char	size;
	char	**data;
};
typedef struct s_grid	t_grid;

t_grid	*create_grid(int size);
void	destroy_grid(t_grid *grid);
void	print_grid(t_grid *grid);
int		can_place_piece(char **grid, t_pos pos_array[4], char x, char y);
void	apply_piece(char **data, t_piece *p, t_pos pos);
void	remove_piece(char **grid, t_pos pos_array[4], t_pos pos);

#endif
