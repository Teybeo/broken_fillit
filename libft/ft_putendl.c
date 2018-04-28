/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdarchiv <tdarchiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:02:12 by tdarchiv          #+#    #+#             */
/*   Updated: 2018/04/28 17:18:14 by tdarchiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (ALLOW_SILENT_FAIL && (s == NULL))
		return ;
	write(STDOUT_FILENO, s, ft_strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}
