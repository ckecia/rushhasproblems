/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdebi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:07:05 by pdebi             #+#    #+#             */
/*   Updated: 2019/08/03 17:07:39 by pdebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int z;

	i = 0;
	z = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
				*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		z = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *str++;
		i -= '0';
	}
	return (i * z);
}

void	check_rush(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == 1 && j == y))
		ft_putchar('A');
	else
	{
		if ((i == x && j == 1) || (i == x && j == y))
			ft_putchar('C');
		else
		{
			if ((i > 1 && i < x && (j == 1 || j == y)))
				ft_putchar('B');
			else
			{
				if ((j > 1 && j < y && (i == 1 || i == x)))
					ft_putchar('B');
				else
					ft_putchar(' ');
			}
		}
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
		return ;
	if ((x == 1) && (y == 1))
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	while (j <= y)
	{
		while (i <= x)
		{
			check_rush(i, j, x, y);
			i++;
		}
		j++;
		i = 1;
		ft_putchar('\n');
	}
}

int main(int argc, char **argv)
{
	int x;
	int y;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (argc == 3)
		rush(x, y);
	return 0;
}
