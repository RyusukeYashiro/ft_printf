/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:34:45 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/09 18:55:57 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_print_char(char c)
{
    return(write(1, &c , 1));
}


int ft_convert_format(va_list args ,const char format)
{
    if(format == 'c')
        return (ft_print_char(va_arg(args , int)));
    if(format == 's')
        return (ft_print_str(va_arg(args , char *)));
    if(format == 'd' || format == 'i')
        return (ft_print_int(va_arg(args , int)));
    if(format == 'u')
        return (ft_print_unit(va_arg(args , unsigned int)));
    if(format == 'x' || format == 'X')
        return (ft_print_hex(va_arg(args , unsigned int),format));
    if(format == '%')
        return (ft_print_percent());
    if(format == 'p')
        return (ft_print_point(va_arg(args , unsigned long long)));
    return (-1);
}


int ft_printf(const char *format,  ...)
{
    int ft_print_len;  //printfは戻り値がintの値を返す。実際に書き込まれた文字数。負の値の場合はエラーあり。
    int temp;
    va_list args;

    va_start(args,format);
    ft_print_len = 0;
    if(!format)
        return (0);
    while(*format)
    {
        temp = 0;
        if(*format == '%')
        {
            format++;
            temp = ft_convert_format(args , *format);
        }        
        else
            temp = ft_print_char(*format);
        if(ft_print_len < 0)
            return (-1);
        ft_print_len += temp;
        format++;
    }
    va_end(args);
    return (ft_print_len);
}

#include <stdio.h>
int main(void)
{
    int a;
    int b;
    a = ft_printf("ans = %dです%u\n" , 90 , 80);
    b = printf("ans = %dです%u\n" , 90 , 70);
    printf("%d\n" , a);
    printf("%d\n" , b);
    return (0);
}