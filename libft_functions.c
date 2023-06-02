/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:33:17 by jborner           #+#    #+#             */
/*   Updated: 2023/06/01 17:42:33 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0 || c < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	write(fd, &(char){num % 10 + '0'}, 1);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	long	num;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	write(fd, &(char){num % 10 + '0'}, 1);
}

void	ft_puthex_small_fd(int n, int fd)
{
    long	num;
    char    digit;     

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
    if (num > 15)
		ft_puthex_small_fd(num / 16, fd);
	digit = num % 16;
	if (digit < 10)
		digit += '0';
	else
		digit -= 10 + 'a';
	write(fd, &digit, 1);
}

void	ft_puthex_big_fd(int n, int fd)
{
    long	num;
    char    digit;     

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
    if (num > 15)
		ft_puthex_big_fd(num / 16, fd);
	digit = num % 16;
	if (digit < 10)
		digit += '0';
	else
		digit -= 10 + 'A';
	write(fd, &digit, 1);
}