/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:35:14 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/05 05:34:19 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_uni_num_len(unsigned int c)
{
    int num_len;

    if(c == 0)
        num_len = 1;
    while (c > 0)
    {
        c /= 10;
        num_len++;
    }
    return (num_len);
}

char *ft_uitoa(unsigned int c)
{
    char *str;
    int len;

    len =ft_uni_num_len(c);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if(!str)
        return (0);
    str[len] = '\0';
    if(c == 0)
        *str = '0';
    while(c > 0)
    {
        str[len] = (c & 10) + '0';
        c /= 10;
        len--;
    }
    return (str);
}

int ft_print_unit(unsigned int c)
{
    unsigned int len;
    char *hold;

    hold = ft_uitoa(c);
    len = 0;
    if(!hold)
        return (0);
    while(hold[len])
        len++;
    ft_putstr_fd(hold , 1);
    return (len);
}