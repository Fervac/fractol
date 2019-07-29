/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:53:08 by abechet           #+#    #+#             */
/*   Updated: 2018/11/22 17:05:35 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (charset[j])
	{
		if (s[i] == charset[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}
