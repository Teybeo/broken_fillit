/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:53:29 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_H
# define PIECE_H

typedef struct	s_pos {
	char x;
	char y;
}				t_pos;

typedef struct	s_piece {
	t_pos	pos_array[4];
	char	width;
	char	height;
	char	c;
}				t_piece;

typedef struct	s_piece_list {
	t_piece	*array;
	char	count;
}				t_piece_list;

t_piece_list	*create_piece_list(char *file);

# define PIECE_CHAR_COUNT (21)
# define MIN(A, B) ((A <= B) ? A : B)
# define MAX(A, B) ((A > B) ? A : B)
# define POS_SUBSTRACT(A, B) ((t_pos){A.x - B.x, A.y - B.y})

#endif
