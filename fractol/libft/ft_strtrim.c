/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:40 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 15:53:18 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (s[i + 1] != '\0')
		i++;
	while (ft_isspace(s[i]))
		i--;
	end = i;
	i = end - start;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (start <= end)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
