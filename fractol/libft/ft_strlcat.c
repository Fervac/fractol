/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:18:26 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 14:00:34 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmp;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	tmp = dst;
	tmp += lendst;
	if (lendst >= size)
		return (size + lensrc);
	size -= lendst;
	while (*src && size > 1)
	{
		*tmp = *src;
		size--;
		tmp++;
		src++;
	}
	*tmp = 0;
	return (lensrc + lendst);
}
