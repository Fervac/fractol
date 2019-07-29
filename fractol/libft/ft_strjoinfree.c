/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:26:32 by abechet           #+#    #+#             */
/*   Updated: 2018/11/29 18:28:46 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel((char**)&s1);
	return (ret);
}
