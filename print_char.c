/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:54:53 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/16 17:46:09 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_and_count_char(t_format *f)
{
	int	occupied;

	occupied = 1;
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

int			print_char(char c, t_format *f)
{
	int		occupied;

	occupied = parse_and_count_char(f);
	if (!(f->flags & FLAGS_LEFT))
		ft_print_space(f->pad_space);
	ft_print_zero(f->pad_zero);
	ft_putchar_fd(c, 1);
	if (f->flags & FLAGS_LEFT)
		ft_print_space(f->pad_space);
	return (occupied);
}
