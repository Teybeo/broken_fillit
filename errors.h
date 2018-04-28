/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:58:52 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define DEV 0

# if DEV == 1
#  define ERROR_CHARSET_INVALID "charset invalid"
#  define ERROR_OPEN_FAILED "Could not open file"
#  define ERROR_EMPTY_FILE "File is empty"
#  define ERROR_NOT_4_ELEMS "Piece doesn't have exactly 4 elems"
#  define ERROR_MALFORMED_PIECE "Piece is malformed"
#  define ERROR_DISJOINT_ELEMS "Piece has disjoint elements"
#  define ERROR_INVALID_CHARACTER "Piece has invalid characters"
#  define ERROR_MALLOC_FAIL "This will never happen but we"
#  define ERROR_TOO_MANY_PIECES "File has more than 26 pieces"
# else
#  define ERROR_CHARSET_INVALID "error"
#  define ERROR_OPEN_FAILED "error"
#  define ERROR_EMPTY_FILE "error"
#  define ERROR_NOT_4_ELEMS "error"
#  define ERROR_MALFORMED_PIECE "error"
#  define ERROR_DISJOINT_ELEMS "error"
#  define ERROR_INVALID_CHARACTER "error"
#  define ERROR_MALLOC_FAIL "error"
#  define ERROR_TOO_MANY_PIECES "error"
# endif

void	exit_with_msg(char const *message);

#endif
