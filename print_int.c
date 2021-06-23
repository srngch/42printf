/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:20:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/17 01:50:10 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_sign(long long nbr, t_format **f)
{
	char	sign;

	sign = 0;
	if (nbr == 0)
		return (0);
	if (nbr < 0)
	{
		sign = '-';
		return (sign);
	}
	if ((*f)->flags & FLAGS_SPACE)
		sign = ' ';
	if ((*f)->flags & FLAGS_PLUS)
		sign = '+';
	return (sign);
}

static int	parse_and_count_int(t_format *f, long long nbr, char *sign)
{
	int	nbr_len;
	int	occupied;

	nbr_len = ft_nbrlen(ft_abs(nbr));
	occupied = nbr_len;
	if (*sign != 0)
		occupied++;
	f->pad_space = 0;
	if (f->width > occupied)
		f->pad_space = f->width - occupied;
	f->pad_zero = 0;
	if (f->precision > nbr_len)
		f->pad_zero = f->precision - nbr_len;
	if (f->flags & FLAGS_ZEROPAD)
		f->pad_zero = f->pad_space;
	f->pad_space -= f->pad_zero;
	if (f->pad_space < 0)
		f->pad_space = 0;
	occupied += f->pad_space + f->pad_zero;
	return (occupied);
}

int			print_int(long long nbr, t_format *f)
{
	char	sign;
	int		occupied;

	sign = get_sign(nbr, &f);
	occupied = parse_and_count_int(f, nbr, &sign);
	if (nbr == 0 && f->flags & FLAGS_PRECISION && f->precision == 0)
	{
		if (f->width > 0 && f->pad_space >= 0)
			f->pad_space++;
		ft_print_space(f->pad_space);
		if (f->width == 0)
			occupied--;
	}
	else
	{
		if (!(f->flags & FLAGS_LEFT))
			ft_print_space(f->pad_space);
		if (sign != 0)
			ft_putchar_fd(sign, 1);
		ft_print_zero(f->pad_zero);
		ft_putnbr_fd(ft_abs(nbr), 1);
		if (f->flags & FLAGS_LEFT)
			ft_print_space(f->pad_space);
	}
	return (occupied);
}
