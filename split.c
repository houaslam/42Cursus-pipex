/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:13:16 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/12 12:46:36 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h" 

char	**ft_split(char *s, char c)
{
	char	**p;
	int		j;
	size_t	i;
	size_t	size ;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	size = ft_dim1((char *)s, c);
	p = malloc((size + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (!ft_func(p, (char *)s, c))
		return (NULL);
	return (p);
}

int	ft_dim1(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
	i++;
	}
	return (j + 1);
}

char	**ft_func(char **arr, char *s, char c)
{
	int	i;
	int	p;
	int	k;

	i = 0;
	p = 0;
	k = 0;
	while (p < ft_dim1(s, c) && s[i])
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		i = k;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[p] = ft_substr(s, k, i - k);
		k = i;
		if (!arr[p])
			return (ft_freestr(arr));
		p++;
	}
	arr[p] = NULL;
	return (arr);
}

char	**ft_freestr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(unsigned char)c)
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
