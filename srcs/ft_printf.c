/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:34:45 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/05 06:46:33 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_print_char(int c)
{
    char p;

    p = (char)c;
    return(write(1, &p , 1));
}


int ft_convert_format(va_list args , const char format)
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
        return (ft_print_alpha(va_arg(args , unsigned int),format));
    if(format == '%')
        return (ft_print_percent());
    return (0);
}


int ft_printf(const char *format,  ...)
{
    int i;
    int ft_print_len;  //printfは戻り値がintの値を返す。実際に書き込まれた文字数。負の値の場合はエラーあり。
    va_list args;
    char *str;

    va_start(args,format);
    i = 0;
    ft_print_len = 0;
    str = (char *)format;
    while(str[i])
    {
        if(str[i] == '%')
        {
            ft_print_len = ft_convert_format(args , str[i+1]);
            i++;
        }
        else
        ft_print_len += ft_print_char(str[i]);
        i++;
    }
    va_end(args);
    return (ft_print_len);
}

int main(void)
{
    ft_printf("test" , 3 , 'a');
    return (0);
}