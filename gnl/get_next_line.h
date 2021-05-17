/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:30 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/17 17:51:48 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24 
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256 
# endif

int				get_next_line(int fd, char **line);

char	*my_strndup(const char *s1, int idx);
int	my_strnewline(char *s);
void        *ft_memmove(void *dst, const void *src, size_t len);
char    *my_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
