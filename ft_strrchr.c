/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:54:43 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/05 17:48:25 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	ch;

	last = NULL;
	ch = (unsigned char)c;
	while (*str)
	{
		if (*str == ch)
			last = (char *)str;
		str++;
	}
	if (ch == 0)
		return ((char *)str);
	return (last);
}
