/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckecia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:28:47 by ckecia            #+#    #+#             */
/*   Updated: 2019/08/18 12:28:52 by ckecia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int		ft_putchar(char c);

void	check_rush00(int i, int j, int x, int y, char *array)
{
	if ((i == 1 && j == 1) || (i == x && j == y && y > 1 && x > 1))
		push_char(array, 'o');
	else
	{
		if ((i == x && j == 1) || (i == 1 && j == y))
			push_char(array, 'o');
		else
		{
			if ((i > 1 && i < x && (j == 1 || j == y)))
				push_char(array, '-');
			else
			{
				if ((j > 1 && j < y && (i == 1 || i == x)))
					push_char(array, '|');
				else
					push_char(array, ' ');
			}
		}
	}
}

char	*rush00(int x, int y)
{
	char *out;
	out = (char *)malloc(x * y * sizeof(char));
	int i;
	int j;

	out[0] = '\0';
	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
		returner('\n');
	if ((x == 1) && (y == 1))
		returner('o');
	while (j <= y)
	{
		while (i <= x)
		{
			check_rush00(i, j, x, y, out);
			i++;
		}
		j++;
		i = 1;
		push_char(out, '\n');
	}
	return (out);
}
