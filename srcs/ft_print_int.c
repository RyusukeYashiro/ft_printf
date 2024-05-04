/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:20:55 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/05 05:33:49 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_print_int(int c)
{
    int len;
    char *hold;

    len = 0;
    hold = ft_itoa(c);
    len = ft_print_str(hold);
    return (len);
}