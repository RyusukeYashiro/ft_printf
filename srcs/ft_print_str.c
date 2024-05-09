/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:59:44 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/09 13:56:22 by ryusukeyash      ###   ########.fr       */
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
        ft_putchar_fd(s[i] , 1);
        i++;
    }
    return (i);
}