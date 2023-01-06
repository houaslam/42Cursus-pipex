/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:10:55 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/06 15:03:44 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	if (!s1)
		ft_putstr_fd("command not found\n", 2);
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while ((i < n) && (str[i] != '\0' || str1[i] != '\0'))
	{
		if (str[i] > str1[i])
			return (1);
		else if (str[i] < str1[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s1 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s1)
		return (NULL);
	while (i < ft_strlen(s))
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	size_t			k;

	if (!s)
		return (0);
	k = ft_strlen((char *)s);
	if (start > k)
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (i < len && start < k)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
