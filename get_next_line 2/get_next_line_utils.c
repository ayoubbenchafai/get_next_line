/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:12:52 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/30 22:40:19 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check_line(const char *s, char c)
{
    while(*s)
    {
        if(*s == c)
            return (1);
        s++;    
    }
    return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    int size;
    char *tab;

    if(!s1)
        return (ft_strdup(s2));
    if(!s2)
        return (NULL);
    i = 0;
    j = 0;
    size = ft_strlen(s1) + ft_strlen(s2);
    tab = malloc(size + 1);
    if(!tab)
        return (NULL);
    while(i < ft_strlen(s1))
    {
        tab[i] = s1[i];
        i++;
    }
    while(i < size)
        tab[i++] = s2[j++];
    tab[i] = '\0';
    return (tab);
}