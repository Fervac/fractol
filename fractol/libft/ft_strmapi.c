/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:13:13 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 17:36:57 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if (s && f)
	{
		if (!(tmp = (char *)malloc((sizeof(char) * ft_strlen(s) + 1))))
			return (NULL);
		i = -1;
		while (s[++i])
			tmp[i] = f(i, s[i]);
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
