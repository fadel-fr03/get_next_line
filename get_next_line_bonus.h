/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fal-frou@students.42beirut.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:06:30 by fal-frou          #+#    #+#             */
/*   Updated: 2024/06/27 10:26:08 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Utility Functions */
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, const char *s2);

/* Main Functions */
void	read_from_file(int fd, char **buffer);
size_t	modified_strlen(const char *s);
char	*extract_line(char *buffer);
void	clean_buffer(char **buffer);
char	*get_next_line(int fd);
#endif