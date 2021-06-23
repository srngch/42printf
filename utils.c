/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 02:18:44 by sarchoi           #+#    #+#             */
/*   Updated: 2021/06/16 18:08:14 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nbrlen(long long n)
{
	unsigned int	count;
	unsigned int	num;

	if (n == 0)
		return (1);
	count = 0;
	num = n;
	if (n < 0)
	{
		count = 1;
		num = -n;
	}
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}

unsigned int	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void			ft_print_zero(int len)
{
	while (len > 0)
	{
		write(1, "0", 1);
		len--;
	}
}

void			ft_print_space(int len)
{
	while (len > 0)
	{
		write(1, " ", 1);
		len--;
	}
}
