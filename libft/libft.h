/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:28 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/18 12:26:21 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_bzero(void *b, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(const char *str);
char			*ft_strdup(char *src);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long long n, int fd);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

#endif
