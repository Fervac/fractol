/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:18:44 by abechet           #+#    #+#             */
/*   Updated: 2018/11/14 11:46:00 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != c && *(s + 1) == c)
			i++;
		if (*s != c && *(s + 1) == '\0')
			i++;
		s++;
	}
	return (i);
}
