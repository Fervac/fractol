/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:58:17 by abechet           #+#    #+#             */
/*   Updated: 2018/12/04 08:33:00 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (charset[j])
		{
			if (charset[j] == s[i])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
