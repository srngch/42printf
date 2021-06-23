/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:42:27 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/17 01:40:25 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list *va, t_format *f, int **spec_n)
{
	char	specifier;
	int		len;

	specifier = f->specifier;
	len = 0;
	if (specifier == '%')
		len = print_char('%', f);
	else if (specifier == 'c')
		len = print_char(va_arg(*va, int), f);
	else if (specifier == 's')
		len = print_str(va_arg(*va, char *), f);
	else if (specifier == 'p')
		len = print_pointer(va_arg(*va, unsigned long long), f);
	else if ((specifier == 'd') || (specifier == 'i'))
		len = print_int(va_arg(*va, int), f);
	else if (specifier == 'u')
		len = print_int(va_arg(*va, unsigned int), f);
	else if ((specifier == 'x') || (specifier == 'X'))
		len = print_hex(va_arg(*va, unsigned int), f);
	else if (specifier == 'n')
		*spec_n = va_arg(*va, int*);
	else
		return (len);
	return (len);
}

static void	parse_format(char **str, va_list *va, t_format *f)
{
	parse_format_flags(str, f);
	parse_format_width(str, va, f);
	parse_format_precision(str, va, f);
	parse_format_length(str, f);
	parse_format_specifier(str, f);
	if (f->flags & FLAGS_LEFT || f->flags & FLAGS_PRECISION)
		f->flags &= ~FLAGS_ZEROPAD;
	if (f->flags & FLAGS_PLUS)
		f->flags &= ~FLAGS_SPACE;
}

static int	format_proc(
	char **str, va_list *va, int **spec_n, int *print_len)
{
	t_format	*f;

	(*str)++;
	f = (t_format *)ft_calloc(1, sizeof(t_format));
	parse_format(str, va, f);
	if (f->specifier == '\0')
	{
		free(f);
		return (0);
	}
	(*str)--;
	*print_len += print_format(va, f, spec_n);
	free(f);
	return (1);
}

int			ft_printf(const char *str, ...)
{
	int		print_len;
	va_list	va;
	int		*spec_n;

	print_len = 0;
	spec_n = NULL;
	va_start(va, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (format_proc((char **)&str, &va, &spec_n, &print_len) == 0)
				continue ;
		}
		else
		{
			write(1, str, 1);
			print_len++;
		}
		str++;
	}
	va_end(va);
	if (spec_n != NULL)
		*spec_n = print_len;
	return (print_len);
}
