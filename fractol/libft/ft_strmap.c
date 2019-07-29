/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:42:33 by abechet           #+#    #+#             */
/*   Updated: 2018/11/13 17:22:48 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(*tmp) * (len + 1));
	if (!(tmp))
		return (NULL);
	while (*s)
	{
		*tmp = f(*s);
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (tmp - len);
}
