/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:39:03 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/10 15:45:37 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **strsarr)
{
	int	i;

	i = 0;
	while (strsarr[i] != NULL)
	{
		free(strsarr[i]);
		i++;
	}
	free(strsarr);
}

static int	ft_countwords(char *str, char sep)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

static int	ft_strlenwsep(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

static void	ft_allocate(char **strsarr, char const *s, char sep)
{
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
		{
			*strsarr = ft_substr(s, 0, ft_strlenwsep(s, sep));
			if (*strsarr == NULL)
			{
				ft_free(strsarr);
				return ;
			}
			s += ft_strlenwsep(s, sep);
			strsarr++;
		}
	}
	*strsarr = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**strsarr;

	words = ft_countwords((char *)s, c);
	strsarr = malloc(sizeof(char *) * (words + 1));
	if (!strsarr)
		return (NULL);
	ft_allocate(strsarr, s, c);
	return (strsarr);
}
// #include <stdio.h>
// int	main()
// {
// 	char	**strsarr;
// 	int		i;

// 	strsarr = ft_split("Hello!", 32);
// 	i = 0;
// 	while (strsarr[i] != NULL)
// 	{
// 		printf("%s\n", strsarr[i]);
// 		i++;
// 	}
// 	ft_free(strsarr);
// 	return (0);
// }