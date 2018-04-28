/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:20:08 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_piece.h"

#include "errors.h"

#include "libft.h"
#include "piece.h"

static void	get_elems_positions(char const *piece, t_pos *pos_array)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (i < 20)
	{
		if (piece[i] == '#')
		{
			pos_array[e].x = (i % 5);
			pos_array[e].y = i / 5;
			e++;
		}
		i++;
	}
}

static void	check_links(int const *links)
{
	int	elems_with_1_link;
	int	elems_with_2_link;
	int	elems_with_3_link;
	int	i;

	elems_with_1_link = 0;
	elems_with_2_link = 0;
	elems_with_3_link = 0;
	i = 0;
	while (i < 4)
	{
		elems_with_1_link += (links[i] == 1);
		elems_with_2_link += (links[i] == 2);
		elems_with_3_link += (links[i] == 3);
		i++;
	}
	if (elems_with_2_link == 2 && elems_with_1_link == 2)
		return ;
	if (elems_with_1_link == 3 && elems_with_3_link == 1)
		return ;
	if (elems_with_2_link == 4)
		return ;
	exit_with_msg(ERROR_DISJOINT_ELEMS);
}

static void	check_elems(char const *s1)
{
	t_pos	pos[4];
	int		elem;
	int		other;
	int		links[4];

	ft_memset(links, 0, sizeof(links));
	get_elems_positions(s1, pos);
	elem = 0;
	while (elem < 4)
	{
		other = 0;
		while (other < 4)
		{
			if (other != elem && DISTANCE(pos[elem], pos[other]) == 1)
				links[elem] += 1;
			other++;
		}
		elem++;
	}
	check_links(links);
}

void		check_piece(char const *piece)
{
	int		i;
	int		j;
	char	line[5];
	int		elem_count;

	j = 0;
	elem_count = 0;
	while (j < 20)
	{
		i = 0;
		ft_memcpy(line, &piece[j], 5);
		while (i < 4)
		{
			if (line[i] != '#' && line[i] != '.')
				exit_with_msg(ERROR_INVALID_CHARACTER);
			elem_count += (line[i] == '#');
			i++;
		}
		if (line[i] != '\n')
			exit_with_msg(ERROR_MALFORMED_PIECE);
		j += 5;
	}
	if (elem_count != 4)
		exit_with_msg(ERROR_NOT_4_ELEMS);
	check_elems(piece);
}

void		check_file(char const *str)
{
	int		piece_count;
	int		i;
	int		chars_left;

	if (str[0] == '\0')
		exit_with_msg(ERROR_EMPTY_FILE);
	i = 0;
	piece_count = 0;
	chars_left = (int)ft_strlen(str);
	while (chars_left > 0)
	{
		if (chars_left < 20)
			exit_with_msg(ERROR_MALFORMED_PIECE);
		check_piece(&str[i]);
		piece_count++;
		i += 20;
		chars_left -= 20;
		if ((chars_left >= 20 && str[i] != '\n')
			|| (chars_left == 1 && str[i] != '\0'))
			exit_with_msg(ERROR_MALFORMED_PIECE);
		i++;
		chars_left--;
	}
	if (chars_left < -1)
		exit_with_msg(ERROR_MALFORMED_PIECE);
}
