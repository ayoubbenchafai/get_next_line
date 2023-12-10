/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:33:00 by aben-cha          #+#    #+#             */
/*   Updated: 2023/12/10 17:37:29 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE  2147483646

#endif


int ft_check_line(const char *s, char c);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strcpy(char * dst, const char * src);
char *ft_strjoin(char *s1, const char *s2);
char    *get_next_line(int fd);


#endif