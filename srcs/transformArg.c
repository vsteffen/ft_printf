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

size_t          getLengthBeforeDot(int nb)
{
	size_t				length;
    int                 tmpNb;

    tmpNb = nb;
    length = 1;
    while (tmpNb /= 10)
        ++length;
	if (nb < 0)
		++length;
	return (length);
}

void        fillArrayForFtoa(char *output, double nb, uint8_t precision, t_structFlDo *structFlDo) {
    size_t      posAfterDot;
    double      subtractInt;

    structFlDo->tmpNb = (int)nb;
    output[structFlDo->lengthBeforeDot + structFlDo->dot] = '\0';
	output[--structFlDo->lengthBeforeDot] = structFlDo->tmpNb % 10 + '0';
	while (structFlDo->tmpNb /= 10)
		output[--structFlDo->lengthBeforeDot] = structFlDo->tmpNb % 10 + '0';
	if (structFlDo->beforeDot < 0)
		output[0] = '-';
    if (precision < 0)
        return ;
    posAfterDot = structFlDo->lengthBeforeDot + structFlDo->dot;
    while (precision > 0) {
        structFlDo->afterDot *= 10;
        subtractInt = (int)structFlDo->afterDot;
        output[posAfterDot] = subtractInt + '0';
        structFlDo->afterDot -= subtractInt;
        --precision;
        ++posAfterDot;
    }
    output[posAfterDot] = '\0';
}

char      *ft_ftoa(double nb, uint8_t precision) {
    t_structFlDo    structFlDo;
    char            *output;

    structFlDo.beforeDot = (int)nb;
    structFlDo.afterDot -= structFlDo.beforeDot;
    structFlDo.dot = 0;
    structFlDo.lengthBeforeDot = getLengthBeforeDot(structFlDo.beforeDot);
    if (precision > 0)
        structFlDo.dot = 1;
    output = (char *)malloc(sizeof(char) * (structFlDo.lengthBeforeDot + structFlDo.dot + precision) + 1);
    fillArrayForFtoa(output, nb, precision, &structFlDo);
    printf("-----------> array of ft_ftoa [%s]\n", output);
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

void			transformArgFloat(t_data *data, double varFloat) {
    // printf("The maximum value of float = %.10e\n", FLT_MAX);
    // printf("The minimum value of float = %.10e\n", FLT_MIN);
    // data->current->outputArg = ft_itoa(varFloat);
    (void)varFloat;
    data->current->outputArg = ft_ftoa(4.200, data->current->precision);
}

void			transformArgLong(t_data *data, int64_t varLong) {
    data->current->outputArg = ft_itoa(varLong);
}

void			transformArgString(t_data *data, char *varString) {
    data->current->outputArg = ft_strdup(varString);
}
