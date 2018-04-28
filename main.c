/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:07:24 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include "check_piece.h"
#include "errors.h"
#include "piece.h"
#include "resolver.h"

#include <fcntl.h>
#include "libft.h"

void	print_usage(void)
{
	ft_putendl("usage: fillit source_file");
}

int		main(int argc, char **argv)
{
	t_piece_list	*piece_list;
	int				file_descriptor;
	char			*file;

	if (argc != 2)
	{
		print_usage();
		return (0);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor <= 0)
		exit_with_msg(ERROR_OPEN_FAILED);
	file = read_file(file_descriptor);
	check_file(file);
	piece_list = create_piece_list(file);
	resolve(piece_list);
	return (0);
}
