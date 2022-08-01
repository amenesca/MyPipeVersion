/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:52:54 by thsousa           #+#    #+#             */
/*   Updated: 2022/08/01 12:51:48 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t    ft_len(char const *s, int c)
{
    size_t    j;

    j = 0;

    while (s[j] != c && s[j] != '\0')
    {
        if (s[j] == '"')
        {
            j++;
            while(s[j] != '"')
                j++;
        }
        if (s[j] == 39)
        {
            j++;
            while(s[j] != 39)
                j++;

        }
        j++;
    }
    return (j);
}

static size_t    ft_count(char const *s, int c)
{
    size_t    i;
    size_t    j;

    i = 1;
    j = 0;
    while (*s && *s == c)
        s++;
    while (s[j])
    {
        if (s[j] != c && s[j - 1] == c)
            i++;
        if (s[j] == '"')
        {
            j++;
            while (s[j] != '"')
                j++;
        }
        if (s[j] == 39)
        {
            j++;
            while (s[j] != 39)
                j++;
        }
        j++;
    }
    return (i);
} 

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	j;
	char	*str1;
	int		substr;

	str1 = (char *)s;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **) malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < ft_count(s, c))
	{
		while (*str1 == c && *str1)
			str1++;
		substr = ft_len(str1, c);
		str[j] = ft_substr(str1, 0, substr);
		j++;
		str1 += substr;
	}
	str[j] = NULL;
	return (str);
}
