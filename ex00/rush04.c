/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckecia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:29:41 by ckecia            #+#    #+#             */
/*   Updated: 2019/08/18 12:29:44 by ckecia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	check_rush04(int i, int j, int x, int y, char *array)
{
	if ((i == 1 && j == 1) || (i == x && j == y && y > 1 && x > 1))
		push_char(array, 'A');
	else
	{
		if ((i == x && j == 1) || (i == 1 && j == y))
			push_char(array, 'C');
		else
		{
			if ((i > 1 && i < x && (j == 1 || j == y)))
				push_char(array, 'B');
			else
			{
				if ((j > 1 && j < y && (i == 1 || i == x)))
					push_char(array, 'B');
				else
					push_char(array, ' ');
			}
		}
	}
}

char	*rush04(int x, int y)
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
		returner('A');
	while (j <= y)
	{
		while (i <= x)
		{
			check_rush04(i, j, x, y, out);
			i++;
		}
		j++;
		i = 1;
		push_char(out, '\n');
	}
	return (out);
}
