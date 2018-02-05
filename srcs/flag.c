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

int8_t    verifFlagAlreadyUsed(t_data *data) {
    if (data->current->dotFlag == 1) {
        data->error = 2;
        return (0);
    }
    data->current->dotFlag = 1;
    return (1);
}

void      flagDot(t_data *data) {
    uint8_t     precision;
    char        numeral;
    size_t      tmpMoveInArg;

    precision = 0;
    tmpMoveInArg = data->moveInArg;
    while (ft_isdigit((numeral = data->format[data->formatPos + data->moveInArg]))) {
        precision *= 10;
        precision += (int)numeral - 48;
        ++data->moveInArg;
    }
    if (tmpMoveInArg != data->moveInArg) {
        --data->moveInArg;
    }
    data->current->precision = precision;
}
