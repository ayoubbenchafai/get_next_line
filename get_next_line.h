/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:12:47 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/30 22:00:00 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif


int     ft_check_line(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);


#endif