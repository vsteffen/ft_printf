/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformArg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

char      *ft_ftoa(double nb, int precision) {
    double     beforeDot;
    double     afterDot = 0.0;

    beforeDot = (int)nb;
    afterDot -= beforeDot;
    if (precision == -1) {
      precision = 6;
    }
    // while (precision > 0) {
    //
    // }
    return (NULL);
}

void			transformArgChar(t_data *data, int8_t varChar) {
    char  *output;

    output = (char*)malloc(sizeof(char) * 2);
    output[0] = (char)varChar;
    output[1] = '\0';
    data->current->outputArg = output;
}
void			transformArgShort(t_data *data, int16_t varShort) {
    data->current->outputArg = ft_itoa(varShort);
}

void			transformArgInt(t_data *data, int32_t varInt) {
    data->current->outputArg = ft_itoa(varInt);
}

void			transformArgFloat(t_data *data, double varInt) {
    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The minimum value of float = %.10e\n", FLT_MIN);
    data->current->outputArg = ft_itoa(varInt);
}

void			transformArgLong(t_data *data, int64_t varLong) {
    data->current->outputArg = ft_itoa(varLong);
}

void			transformArgString(t_data *data, char *varString) {
    data->current->outputArg = ft_strdup(varString);
}
