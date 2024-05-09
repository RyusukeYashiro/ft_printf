/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:20:55 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/09 20:09:27 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_int(int c)
{
	int		len;
	char	*hold;

	len = 0;
	hold = ft_itoa(c);
	len = ft_print_str(hold);
	return (len);
}
