/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t    verifFlagAlreadyUsed(t_data *data, char flag) {
	if (flag == '.') {
		if (data->current->flagDot == 1) {
			data->error = 2;
				return (0);
		}
		data->current->flagDot = 1;
		return (1);
	}
	else if (flag == 'w') {
		if (data->current->flagWidthNb == 1) {
			data->error = 2;
				return (0);
		}
		data->current->flagWidthNb = 1;
		return (1);
	}
	return (0);
}

void      flagDot(t_data *data) {
	uint8_t     precision;
	char        numeral;
	size_t      tmpMoveInArg;

	precision = 0;
	tmpMoveInArg = data->moveInArg;
	++data->moveInArg; // to put cursor on the first numeral
	while (ft_isdigit((numeral = data->format[data->formatPos + data->moveInArg]))) {
		precision *= 10;
		precision += (int)numeral - 48;
		data->moveInArg++;
	}
	if (tmpMoveInArg != data->moveInArg) {
		data->moveInArg--;
	}
	data->current->precision = precision;
	// printf("PREC FUNCTION: precision = %d and tmp = %lu and moveInArg = %lu and last char = %c\n", precision, tmpMoveInArg, data->moveInArg, numeral);
}

void      flagWidthNb(t_data *data) {
	size_t		width;
	char        numeral;
	size_t      tmpMoveInArg;

	width = 0;
	tmpMoveInArg = data->moveInArg;
	while (ft_isdigit((numeral = data->format[data->formatPos + data->moveInArg]))) {
		width *= 10;
		width += (int)numeral - 48;
		data->moveInArg++;
	}
	if (tmpMoveInArg != data->moveInArg) {
		data->moveInArg--;
	}
	data->current->width = width;
}
