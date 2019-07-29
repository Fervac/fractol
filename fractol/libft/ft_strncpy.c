/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:37:21 by abechet           #+#    #+#             */
/*   Updated: 2018/11/16 13:25:42 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp;
	size_t	start;

	tmp = (char *)dst;
	start = len;
	while (*src && len--)
		*dst++ = *src++;
	if (len < start || !*src)
		ft_bzero(dst, len);
	return (tmp);
}
