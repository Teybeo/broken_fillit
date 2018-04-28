/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:37:26 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

#include "libft.h"

void	print_grid(t_grid *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			ft_putchar(grid->data[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}
