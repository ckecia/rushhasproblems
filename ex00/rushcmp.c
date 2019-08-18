/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:41:22 by ekarl             #+#    #+#             */
/*   Updated: 2019/08/18 17:02:10 by ekarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	measure(char *argv, int *x, int *y)
{
	int	i;
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '\n')
			break;
		i++;
	}
	(*x) = i;
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '\n')
			(*y)++;
		i++;
	}
}

int		nbr_len(int nbr)
{
	int result;
	result = 0;
	if (nbr == 0)
	{
		result = 1;
		return (result);
	}
	while (nbr != 0)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int nb)
{
	char *str;
	long	n;
	int		i;

	n = nb;
	i = nbr_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

void	cat_param(char *param, int nbr)
{
	int	i;
	int j;
	char *temp;

	temp = ft_itoa(nbr);
	i = 0;
	j = 0;
	param[0] = '[';
	i++;
	while (temp[j] != '\0')
	{
		param[i] = temp[j];
		i++;
		j++;
	}
	param[i] = ']';
	param[i+1] = ' ';
}

void	ft_strcat(char *result, char *rushxx, int x, int y)
{
	int i;
	int j;
	char *param1;
	char *param2;

	i = 0;
	j = 0;
	param1 = (char*)malloc(sizeof(param1) * (nbr_len(x) + 3));
	param2 = (char*)malloc(sizeof(param2) * (nbr_len(y) + 3));
	cat_param(param1, x);
	cat_param(param2, y);
	while (result[i] != '\0')
		i++;
	while (rushxx[j] != '\0')
	{
		result[i] = rushxx[j];
		i++;
		j++;
	}
	j = 0;
	while (param1[j] != '\0')
	{
		result[i] = param1[j];
		j++;
		i++;
	}
	j = 0;
	while (param2[j] != '\0')
	{
		result[i] = param2[j];
		j++;
		i++;
	}

}

void	ft_strcat_or(char *result, char *or)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (result[i] != '\0')
		i++;
	while (or[j] != '\0')
	{
		result[i] = or[j];
		j++;
		i++;
	}
}

void	ft_strcat_rush(char *result, char var, int x, int y)
{
	if (var == '0')
		ft_strcat(result, "[rush-00] ", x, y);
	if (var == '1')
		ft_strcat(result, "[rush-01] ", x, y);
	if (var == '2')
		ft_strcat(result, "[rush-02] ", x, y);
	if (var == '3')
		ft_strcat(result, "[rush-03] ", x, y);
	if (var == '4')
		ft_strcat(result, "[rush-04] ", x, y);
}

void	print_result(char *argv, char *r00, char *r01, 
	char *r02, char *r03, char *r04, int x, int y)
{
	char	*result;

	result = malloc(sizeof(result) * (21 * 5));
	if (ft_strcmp(r00, argv) == 0)
	   ft_strcat_rush(result, '0', x, y);
	if (ft_strcmp(r01, argv) == 0)
		ft_strcat_rush(result, '1', x, y);
	if (ft_strcmp(r02, argv) == 0)
		ft_strcat_rush(result, '2', x, y);
	if (ft_strcmp(r03, argv) == 0)
		ft_strcat_rush(result, '3', x, y);
	if (ft_strcmp(r04, argv) == 0)
		ft_strcat_rush(result, '4', x, y);
	if (!(ft_strcmp(r00, argv) == 0) && !(ft_strcmp(r01, argv) == 0) 
		&& !(ft_strcmp(r02, argv) == 0) && 
		!(ft_strcmp(r03, argv) == 0) && !(ft_strcmp(r04, argv) == 0))
		write(1, "aucune", 6);
	write(1, result, ft_strlen(result));
}

int		rushcmp(char *argv)
{
	char	*r00;
	char	*r01;
	char	*r02;
	char	*r03;
	char	*r04;
	int		x;
	int		y;

	x = 0;
	y = 0;
	measure(argv, &x, &y);
	r00 = rush00(x, y);
	r01 = rush01(x, y);
	r02 = rush02(x, y);
	r03 = rush03(x, y);
	r04 = rush04(x, y);
	print_result(argv, r00, r01, r02, r03, r04, x, y);
	return (0);
}

int		main()
{
	char gg[12000];
	int length;
	char *str;
	int i;

	i = 0;
	length = read(0, gg, 12000);
	str = (char*)malloc(sizeof(*str) * length);
	while (i < length)
	{
		str[i] = gg[i];
		i++;
	}
	gg[ft_strlen(gg)] = '\0';
	rushcmp(str);
	write(1, "\n", 1);
	return (0);
}
