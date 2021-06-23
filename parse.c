/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:30:50 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/17 00:15:39 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format_flags(char **str, t_format *f)
{
	f->flags = 0x00;
	while (ft_strchr("0-# +", **str) != NULL)
	{
		if (**str == '0')
			f->flags |= FLAGS_ZEROPAD;
		if (**str == '-')
			f->flags |= FLAGS_LEFT;
		if (**str == '#')
			f->flags |= FLAGS_HASH;
		if (**str == ' ')
			f->flags |= FLAGS_SPACE;
		if (**str == '+')
			f->flags |= FLAGS_PLUS;
		(*str)++;
	}
}

void	parse_format_width(char **str, va_list *va, t_format *f)
{
	if (ft_isdigit(**str))
	{
		f->width = 0;
		f->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		return ;
	}
	else if (**str == '*')
	{
		f->width = va_arg(*va, int);
		(*str)++;
		if (f->width < 0)
		{
			f->flags |= FLAGS_LEFT;
			f->width = ft_abs(f->width);
		}
	}
}

void	parse_format_precision(char **str, va_list *va, t_format *f)
{
	if (**str == '.')
	{
		(*str)++;
		f->flags |= FLAGS_PRECISION;
		f->precision = 0;
		if (ft_isdigit(**str))
		{
			f->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		else if (**str == '*')
		{
			f->precision = va_arg(*va, int);
			(*str)++;
		}
		if (f->precision < 0)
			f->flags &= ~FLAGS_PRECISION;
	}
}

void	parse_format_length(char **str, t_format *f)
{
	if (**str == 'l')
	{
		f->length = LENGTH_L;
		(*str)++;
		if (**str == 'l')
			f->length = LENGTH_LL;
	}
	else if (**str == 'h')
	{
		f->length = LENGTH_H;
		(*str)++;
		if (**str == 'h')
			f->length = LENGTH_HH;
	}
}

void	parse_format_specifier(char **str, t_format *f)
{
	char	specifier;

	f->specifier = **str;
	specifier = f->specifier;
	if ((ft_strchr("cspdiuxX%", specifier) == NULL)
		|| specifier == '\0')
		return ;
	if (specifier == 'c')
		f->flags |= FLAGS_PRECISION;
	else if (specifier == 'p')
		f->flags |= FLAGS_HASH;
	else if ((specifier == 'd') || (specifier == 'i'))
	{
		f->flags |= FLAGS_ISSIGNED;
		f->flags &= ~FLAGS_HASH;
	}
	else if (specifier == 'u')
		f->flags &= ~FLAGS_HASH;
	(*str)++;
}
