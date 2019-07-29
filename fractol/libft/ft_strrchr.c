/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:52:43 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 18:03:45 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*s)
		s++;
	while (s >= p)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
