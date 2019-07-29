/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:05:50 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 15:07:02 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		counter;
	int		i;
	char	**tab;
	char	*tmp;
	int		words;

	if (!(counter = 0) && !s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (counter < words && !(i = 0))
	{
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != '\0')
			i++;
		tmp = ft_strnew(i);
		tab[counter++] = tmp;
		while (*s != c && *s != '\0')
			*tmp++ = *s++;
		*tmp = '\0';
	}
	tab[counter] = 0;
	return (tab);
}
