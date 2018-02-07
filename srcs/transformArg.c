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
		size_t				count;

    count = 1;
    while (nb /= 10)
      ++count;
		return (count);
}

void        fillArrayForFtoa(char *output, uint8_t precision, t_structFlDo *structFlDo) {
    size_t      		posAfterDot;
    // unsigned int		subtractInt;
		size_t					tmpLengthBeforeDot;

		tmpLengthBeforeDot = structFlDo->lengthBeforeDot;
    output[tmpLengthBeforeDot] = '\0';
		printf("Going to work with [%d] [%lu] [%lu]\n", structFlDo->tmpNb, tmpLengthBeforeDot, tmpLengthBeforeDot + structFlDo->dot);
		printf("New String 1 -> [%c%c%c]\n", output[0], output[1], output[2]);
		output[--tmpLengthBeforeDot] = structFlDo->tmpNb % 10 + '0';
		printf("New String 2 -> [%c%c%c]\n", output[0], output[1], output[2]);
		while (structFlDo->tmpNb /= 10) {
			output[--tmpLengthBeforeDot] = structFlDo->tmpNb % 10 + '0';
			printf("ALLOOOOOOOOW\n");
		}
		if (structFlDo->sign == 1)
			output[0] = '-';
		printf("New String 3 -> [%s]\n", output);
    if (precision < 1)
        return ;
		output[structFlDo->lengthBeforeDot] = '.';
		printf("New String 4 -> [%s]\n", output);
    posAfterDot = structFlDo->lengthBeforeDot + structFlDo->dot;
		double testVar = 3.000000;
		printf("TESTING CAST -> %d // AfterDot = %f\n", (int)testVar, -43.16);
    while (precision > 0) {
				printf("+-+-+-+\nPRECISION -> afterDot before * -> %f\n", structFlDo->afterDot);
        structFlDo->afterDot *= 10;
				printf("PRECISION -> afterDot after * -> %f /// result of cast -> %d\n", structFlDo->afterDot, (int)structFlDo->afterDot);
        testVar = (int)structFlDo->afterDot;
				printf("PRECISION -> substract int -> %f\n", testVar);
        output[posAfterDot] = testVar + '0';
        structFlDo->afterDot -= (double)testVar;
				printf("PRECISION -> afterDot after - -> %f\n", structFlDo->afterDot);
        --precision;
        ++posAfterDot;
    }
    output[posAfterDot] = '\0';
}

char      *ft_ftoa(double nb, uint8_t precision) {
    t_structFlDo    structFlDo;
    char            *output;

		structFlDo.beforeDot = (int)nb;
		printf("WTF IS THAT SHIT -> %f and %d\n", nb, (int)nb);
    structFlDo.afterDot = nb - (double)structFlDo.beforeDot;
    structFlDo.dot = 0;
		structFlDo.sign = 0;
    structFlDo.lengthBeforeDot = getLengthBeforeDot(structFlDo.beforeDot);
		structFlDo.tmpNb = structFlDo.beforeDot;
		if (structFlDo.beforeDot < 0) {
			structFlDo.sign = 1;
			++structFlDo.lengthBeforeDot;
			structFlDo.tmpNb = -structFlDo.beforeDot;
			structFlDo.afterDot = -structFlDo.afterDot;
		}
    if (precision > 0)
        structFlDo.dot = 1;
    output = (char *)malloc(sizeof(char) * (structFlDo.lengthBeforeDot + structFlDo.dot + precision) + 1);
    fillArrayForFtoa(output, precision, &structFlDo);
    printf("-----------> array of ft_ftoa [%s]\n", output);
    return (output);
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
    data->current->outputArg = ft_ftoa(varFloat, data->current->precision);
}

void			transformArgLong(t_data *data, int64_t varLong) {
    data->current->outputArg = ft_itoa(varLong);
}

void			transformArgString(t_data *data, char *varString) {
    data->current->outputArg = ft_strdup(varString);
}
