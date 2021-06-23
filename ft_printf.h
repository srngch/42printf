/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:42:19 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/18 14:26:01 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define FLAGS_ZEROPAD		0x01
# define FLAGS_LEFT			0x02
# define FLAGS_HASH			0x04
# define FLAGS_SPACE		0x08
# define FLAGS_PLUS			0x10
# define FLAGS_PRECISION	0x20
# define FLAGS_ISSIGNED		0x40

# define LENGTH_L			1
# define LENGTH_LL			2
# define LENGTH_H			3
# define LENGTH_HH			4

typedef struct		s_format {
	unsigned char	flags;
	int				width;
	int				precision;
	int				length;
	char			specifier;
	int				pad_space;
	int				pad_zero;
}					t_format;

int					ft_printf(const char *str, ...);

void				parse_format_flags(char **str, t_format *f);
void				parse_format_width(char **str, va_list *va, t_format *f);
void				parse_format_precision(
						char **str, va_list *va, t_format *f);
void				parse_format_length(char **str, t_format *f);
void				parse_format_specifier(char **str, t_format *f);

int					print_char(char c, t_format *f);
int					print_str(char *str, t_format *f);
int					print_int(long long nbr, t_format *f);
int					print_hex(long long nbr, t_format *f);
int					print_pointer(unsigned long long p, t_format *f);

void				ft_print_zero(int len);
void				ft_print_space(int len);

unsigned int		ft_nbrlen(long long n);
unsigned int		ft_abs(long long n);

#endif
