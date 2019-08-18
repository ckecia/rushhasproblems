/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:33:25 by ekarl             #+#    #+#             */
/*   Updated: 2019/08/18 16:49:01 by ekarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

char	push_char(char *array, char c);

char	returner(char c);

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

char	*rush00(int x, int y);

char	*rush01(int x, int y);

char	*rush02(int x, int y);

char	 *rush03(int x, int y);

char	*rush04(int x, int y);

void	check_rush01(int i, int j, int x, int y, char *array);

void	check_rush00(int i, int j, int x, int y, char *array);

void	check_rush02(int i, int j, int x, int y, char *array);

void	check_rush03(int i, int j, int x, int y, char *array);

void	check_rush04(int i, int j, int x, int y, char *array);

char	push_char(char *array, char c);

char	returner(char c);

#endif
