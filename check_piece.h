/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:33:05 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PIECE_H
# define CHECK_PIECE_H

# define DISTANCE(A, B) (ABS((A).x - (B).x) + ABS((A).y - (B).y))
# define ABS(X) ((X) > 0 ? (X) : (-(X)))

void		check_file(char const *str);

#endif
