/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:57:57 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 16:45:07 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int pos;
	unsigned int i;

	pos = 0;
	i = 1;
	if (ft_strlen(needle) == ft_strlen(haystack) && ft_strlen(needle) == '\0')
		return ((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			while (needle[i] != '\0' && haystack[pos + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (NULL);
}
