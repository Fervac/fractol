/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:17:25 by abechet           #+#    #+#             */
/*   Updated: 2018/12/18 17:50:46 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		nb2;
	int		result;

	result = 0;
	if (nb % 2 == 0)
		nb2 = 2;
	if (nb % 2 == 1)
		nb2 = 3;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	if (nb > 0)
	{
		while (nb2 <= 46340)
		{
			if (nb2 * nb2 == nb)
				return (nb2);
			if (nb2 * nb2 > nb)
				return (nb2 - 1);
			nb2++;
		}
	}
	return (0);
}