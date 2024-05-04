/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:59:44 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/05 05:24:14 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_print_str(char *s)
{
    int i;

    i = 0;
    if(!s[i])
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    while(s[i])
    {
        write(1 , &s[i] ,1);
        i++;
    }
    return (i);
}