/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:04:48 by gjuste            #+#    #+#             */
/*   Updated: 2018/11/15 17:04:49 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	while (i < size - 1 && i < size_src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
