/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:19:59 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/16 18:23:28 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_and_count_str(t_format *f, int str_len)
{
	int	occupied;

	occupied = str_len;
	f->pad_space = 0;
	if (f->width > occupied)
		f->pad_space = f->width - occupied;
	f->pad_zero = 0;
	if (f->flags & FLAGS_ZEROPAD)
		f->pad_zero = f->pad_space;
	f->pad_space -= f->pad_zero;
	occupied += f->pad_space + f->pad_zero;
	return (occupied);
}

static void	ft_putnstr(char *s, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int			print_str(char *str, t_format *f)
{
	int		occupied;
	int		str_len;

	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (0 < f->precision && f->precision < str_len)
		str_len = f->precision;
	occupied = parse_and_count_str(f, str_len);
	if (f->flags & FLAGS_PRECISION && f->precision == 0)
	{
		ft_print_space(f->width);
		occupied = f->width;
	}
	else
	{
		if (!(f->flags & FLAGS_LEFT))
			ft_print_space(f->pad_space);
		ft_print_zero(f->pad_zero);
		ft_putnstr(str, str_len);
		if (f->flags & FLAGS_LEFT)
			ft_print_space(f->pad_space);
	}
	return (occupied);
}
