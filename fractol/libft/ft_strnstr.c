/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:16:02 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 17:18:44 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	unsigned int pos;
	unsigned int i;

	pos = 0;
	i = 1;
	if (ft_strlen(needle) == ft_strlen(haystack) && ft_strlen(needle) == 0)
		return ((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[pos] != '\0' && pos < l)
	{
		if (haystack[pos] == needle[0])
		{
			while (needle[i] != '\0' && haystack[pos + i] == needle[i] &&
			i + pos < l)
				i++;
			if (needle[i] == '\0')
				return ((char*)(&haystack[pos]));
		}
		pos++;
	}
	return (NULL);
}
