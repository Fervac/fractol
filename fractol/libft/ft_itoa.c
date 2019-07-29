/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:39:35 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 13:56:18 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		b;
	int		neg;
	char	*tmp;

	b = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = (n == 0 ? 1 : 0);
	neg = (n < 0 ? 1 : 0);
	while (b != 0 && ++i)
		b = b / 10;
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1 + neg))))
		return (NULL);
	b = i;
	if (neg == 1)
		n = n * (-1);
	while (i > 0)
	{
		tmp[(i-- + neg) - 1] = (n % 10) + '0';
		n = n / 10;
	}
	(neg == 1 ? tmp[0] = '-' : 1);
	tmp[b + neg] = '\0';
	return (tmp);
}
