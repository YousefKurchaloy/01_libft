/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:45:21 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/08 12:34:14 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	substr_len;
	char	*ptr;
	size_t	i;

	ptr = (char *)str;
	substr_len = ft_strlen(substr);
	if (!*substr)
		return (ptr);
	if (n == 0)
		return (0);
	if (substr_len > n && *ptr)
		return (NULL);
	i = 0;
	while (i <= (n - substr_len) && *ptr)
	{
		if (ft_strncmp(ptr, substr, substr_len) == 0)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
