/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:16:28 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/31 11:41:35 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NEWLINE '\n'
# define BYTE_START 1

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// get_next_line
char		*get_next_line(int fd);
char		*destroy(char **s);

// get_next_line_utils
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
char		*tochr(char *str, int c);
char		*ft_strdup(const char *s);
#endif
