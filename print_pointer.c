/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:39:43 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/16 18:39:10 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_and_count_addr(t_format *f, int str_len)
{
	int	occupied;

	occupied = str_len;
	f->pad_space = 0;
	if (f->width > occupied)
		f->pad_space = f->width - occupied;
	f->pad_zero = 0;
	if (f->precision > str_len - 2)
		f->pad_zero = f->precision - str_len + 2;
	if (f->flags & FLAGS_ZEROPAD)
		f->pad_zero = f->pad_space;
	f->pad_space -= f->pad_zero;
	if (f->pad_space < 0)
		f->pad_space = 0;
	occupied += f->pad_space + f->pad_zero;
	return (occupied);
}

static char	*int_to_hex(long long nbr, int is_uppercase)
{
	char	*base;
	char	buf[20];
	int		i;
	int		buf_len;
	char	*result;

	i = 0;
	if (nbr == 0)
	{
		result = ft_strdup("0");
		return (result);
	}
	base = "0123456789abcdef";
	if (is_uppercase)
		base = "0123456789ABCDEF";
	while (nbr > 0)
	{
		buf[i++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	result = ft_calloc(1, i + 1);
	buf_len = i;
	while (--i > -1)
		*(result++) = buf[i];
	return (result - buf_len);
}

int			print_pointer(unsigned long long p, t_format *f)
{
	int		occupied;
	char	*hex;

	hex = int_to_hex(p, f->specifier == 'X');
	occupied = parse_and_count_addr(f, ft_strlen(hex) + 2);
	if (*hex == '0' && f->flags & FLAGS_PRECISION && f->precision == 0)
	{
		if (f->width > 2)
			f->pad_space++;
		if (f->width < 3 && !p)
			occupied--;
	}
	if (!(f->flags & FLAGS_LEFT))
		ft_print_space(f->pad_space);
	ft_putstr_fd("0x", 1);
	ft_print_zero(f->pad_zero);
	if (!(*hex == '0' && f->flags & FLAGS_PRECISION && f->precision == 0))
		ft_putstr_fd(hex, 1);
	if (f->flags & FLAGS_LEFT)
		ft_print_space(f->pad_space);
	free(hex);
	return (occupied);
}
