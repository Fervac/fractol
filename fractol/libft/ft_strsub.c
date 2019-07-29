/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:01 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 15:48:26 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_memalloc(len + 1);
	if (!(tmp))
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	return (tmp);
}
