/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:09:55 by jborner           #+#    #+#             */
/*   Updated: 2023/06/01 17:53:29 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    check_type(char c, va_list list)
{
    if (c == 'c')
        ft_putchar_fd(va_arg(list, int), 1);
    if (c == 's')
        ft_putstr_fd(va_arg(list, char *), 1);
    if (c == 'p')
        ft_puthex_small_fd((unsigned long)va_arg(list, void*), 1);
    if (c == 'd' || c == 'i')
        ft_putnbr_fd(va_arg(list, int), 1);
    if (c == 'u')
        ft_putnbr_unsigned_fd(va_arg(list, unsigned int), 1);
    if (c == 'x')
        ft_puthex_small_fd(va_arg(list, unsigned int), 1);
    if (c == 'X')
        ft_puthex_big_fd(va_arg(list, unsigned int), 1);
    if (c == '%')
        ft_putchar_fd(c, 1);
}

int ft_printf(const char *str, ...)
{
    va_list list;
    va_start(list, str);
    int i;
    int list_pos;

    list_pos = 1;
    i = 0;
    while(str[i])
    {
        if(str[i] == '%')
        {
            i++;
            check_type(str[i], list);
            i++;
        } 
        ft_putchar_fd(str[i], 1);
        i++;
    }
    return (i);
}
 
/* #include <stdio.h>
int main(void)
{
    ft_printf("own function: %i %i\n", "hallo", 42);
    printf("standard function: %i %i", "hallo", 42); 
} */