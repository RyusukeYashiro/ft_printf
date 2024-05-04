/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:57:42 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/05 06:51:52 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


int ft_alpha_six_len(unsigned int num)
{
    int len;

    len = 0;
    while(num > 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void ft_alpha_six(unsigned int num , const char format)
{
    if(num < 16)
    {
        ft_putchar_fd(num + '0', 1);
    }
    else
    {
        ft_alpha_six(num / 16 , format);
        ft_putchar_fd(num % 16 + '0', 1);
    }
}


int ft_print_alpha(unsigned int c , const char format)
{
    if(c == 0)
        return (write(1, "0" , 1));
    else
        ft_alpha_six(c , format);
    return (ft_alpha_six_len(c));
}