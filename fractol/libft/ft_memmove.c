/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:25:14 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 13:58:20 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
