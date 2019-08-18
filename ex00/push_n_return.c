/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckecia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:27:58 by ckecia            #+#    #+#             */
/*   Updated: 2019/08/18 17:28:02 by ckecia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	push_char(char *array, char c)
{
	int count;
	count = ft_strlen(array);
	array[count] = c;
	array[count + 1] = '\0';
	return (0);
}

char	returner(char c)
{
	return(c);
}
