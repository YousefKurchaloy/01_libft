/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:10:02 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/05 12:54:52 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;
	int		j;
	int		numlen;

	nb = n;
	numlen = ft_numlen(nb);
	str = ft_calloc((numlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		str[i++] = '-';
	}
	j = numlen - 1;
	while (i <= j)
	{
		str[j] = nb % 10 + '0';
		nb = nb / 10;
		j--;
	}
	return (str);
}
