/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:49:25 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece.h"
#include "errors.h"

#include "libft.h"
#include <stdlib.h>

void			normalize_positions(t_piece *piece, t_pos origin)
{
	piece->pos_array[0] = POS_SUBSTRACT(piece->pos_array[0], origin);
	piece->pos_array[1] = POS_SUBSTRACT(piece->pos_array[1], origin);
	piece->pos_array[2] = POS_SUBSTRACT(piece->pos_array[2], origin);
	piece->pos_array[3] = POS_SUBSTRACT(piece->pos_array[3], origin);
}

void			get_min_and_max(t_piece piece, t_pos *min_ptr, t_pos *max_ptr)
{
	int		i;
	t_pos	min;
	t_pos	max;

	max = (t_pos){0, 0};
	min = (t_pos){42, 42};
	i = 0;
	while (i < 4)
	{
		min.x = MIN(min.x, piece.pos_array[i].x);
		min.y = MIN(min.y, piece.pos_array[i].y);
		max.x = MAX(max.x, piece.pos_array[i].x);
		max.y = MAX(max.y, piece.pos_array[i].y);
		i++;
	}
	*min_ptr = min;
	*max_ptr = max;
}

t_piece			create_piece(const char *piece_string)
{
	int		i;
	int		e;
	t_piece	piece;
	t_pos	min;
	t_pos	max;

	i = 0;
	e = 0;
	while (i < 20)
	{
		if (piece_string[i] == '#')
		{
			piece.pos_array[e] = (t_pos){i % 5, i / 5};
			e++;
		}
		i++;
	}
	get_min_and_max(piece, &min, &max);
	normalize_positions(&piece, min);
	piece.width = max.x - min.x;
	piece.height = max.y - min.y;
	return (piece);
}

t_piece_list	*create_piece_list(char *file)
{
	int				i;
	t_piece_list	*list;

	list = malloc(sizeof(t_piece_list));
	if (list == NULL)
		exit_with_msg(ERROR_MALLOC_FAIL);
	list->count = (int)((ft_strlen(file) + 1) / PIECE_CHAR_COUNT);
	list->array = malloc(sizeof(t_piece) * (list->count + 1));
	if (list->array == NULL)
		exit_with_msg(ERROR_MALLOC_FAIL);
	if (list->count > 26)
		exit_with_msg(ERROR_TOO_MANY_PIECES);
	i = 0;
	while (i < list->count)
	{
		list->array[i] = create_piece(file);
		list->array[i].c = 'A' + i;
		file += PIECE_CHAR_COUNT;
		i++;
	}
	list->array[(int)list->count].width = -1;
	return (list);
}
