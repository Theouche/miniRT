/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:52:17 by hnogared          #+#    #+#             */
/*   Updated: 2024/01/04 21:16:36 by hnogared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fdout(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fdout(char *s, int fd)
{
	int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}

int	ft_putnbr_fdout(int n, int len, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		len++;
		n *= -1;
	}
	if (n > 9)
	{
		len += ft_putnbr_fdout(n / 10, 0, fd);
		len += ft_putnbr_fdout(n % 10, 0, fd);
	}
	if (n <= 9)
	{
		ft_putchar_fdout(n + '0', fd);
		len++;
	}
	return (len);
}

int	ft_putunsigned_fdout(unsigned int n, int len, int fd)
{
	if (n > 9)
	{
		len += ft_putunsigned_fdout(n / 10, 0, fd);
		len += ft_putunsigned_fdout(n % 10, 0, fd);
	}
	if (n <= 9)
	{
		ft_putchar_fdout(n + '0', fd);
		len++;
	}
	return (len);
}

int	ft_puthex_fdout(unsigned long n, int len, char cap, int fd)
{
	char	*baselow;
	char	*basehigh;

	baselow = "0123456789abcdef";
	basehigh = "0123456789ABCDEF";
	if (n > 15)
	{
		len += ft_puthex_fdout(n / 16, 0, cap, fd);
		len += ft_puthex_fdout(n % 16, 0, cap, fd);
	}
	if (n <= 15)
	{
		if (cap == 'X')
			ft_putchar_fdout(basehigh[n], fd);
		else
			ft_putchar_fdout(baselow[n], fd);
		len++;
	}
	return (len);
}
