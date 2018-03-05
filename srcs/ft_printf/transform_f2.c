/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:26:45 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/05 22:26:48 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t			ft_pow_printf(int64_t nb, uint8_t power)
{
	int64_t		result;
	uint8_t		count;

	count = 0;
	result = 1;
	while (count < power)
	{
		result *= nb;
		count++;
	}
	return (result);
}

int64_t			ft_round_printf(double nb)
{
	return (nb >= 0 ? (int64_t)(nb + 0.5) : (int64_t)(nb - 0.5));
}
