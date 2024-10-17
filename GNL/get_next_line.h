/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:32:08 by itahri            #+#    #+#             */
/*   Updated: 2024/09/16 17:26:47 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif // !BUFFER_SIZE

int		ft_strlen_gnl(char *str, int cas);
int		ft_check_if_newline(char *sortie);

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);

char	*ft_format_sortie(char *sortie);

#endif // !GET_NEXT_LINE_BONUS
