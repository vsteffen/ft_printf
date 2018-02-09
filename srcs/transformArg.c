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
#include <math.h>

uint8_t				lengthNumeral(int64_t nb)
{
	uint8_t		count;

	count = 1;
	while (nb /= 10)
		++count;
	return (count);
}

int64_t			ft_pow_printf(int64_t nb, uint8_t power) {
	int64_t			result;
	uint8_t			count;

	count = 0;
	result = 1;
	while (count < power) {
		result *= nb;
		count++;
	}
	return (result);
}

int64_t	ft_round_printf(double nb)
{
	return (nb >= 0 ? (int64_t)(nb + 0.5) : (int64_t)(nb - 0.5));
}

void        fillArrayForDtoa(char *output, uint8_t precision, t_structFlDo *structFlDo) {
	uint8_t      		posAfterDot;
	uint8_t				tmpLengthBeforeDot;

	tmpLengthBeforeDot = structFlDo->lengthBeforeDot;
	output[tmpLengthBeforeDot] = '\0';
	output[--tmpLengthBeforeDot] = structFlDo->beforeDot % 10 + '0';
	while (structFlDo->beforeDot /= 10)
		output[--tmpLengthBeforeDot] = structFlDo->beforeDot % 10 + '0';
	if (structFlDo->sign == 1)
		output[0] = '-';
	if (precision < 1)
		return ;
	output[structFlDo->lengthBeforeDot] = '.';
	posAfterDot = structFlDo->lengthBeforeDot + structFlDo->dot + precision;
	output[posAfterDot] = '\0';
	if (structFlDo->afterDot == 0) {
		while (precision-- > 0)
			output[--posAfterDot] = '0';
		return ;
	}
	output[--posAfterDot] = structFlDo->afterDot % 10 + '0';
	while (structFlDo->afterDot /= 10)
		output[--posAfterDot] = structFlDo->afterDot % 10 + '0';
}

char      		*ft_dtoa(double nb, uint8_t precision) {
	t_structFlDo    structFlDo;
	char            *output;
	double					tmpDouble;

	structFlDo.beforeDot = (int64_t)nb;
	structFlDo.dot = 0;
	structFlDo.sign = 0;
	if (precision == 0)
		structFlDo.beforeDot = ft_round_printf(nb);
	else
		structFlDo.dot = 1;
	if (precision > 18)
		precision = 18;
	structFlDo.lengthBeforeDot = lengthNumeral((int64_t)structFlDo.beforeDot);
	tmpDouble = nb - (double)structFlDo.beforeDot;
	if (structFlDo.beforeDot < 0) {
		structFlDo.sign = 1;
		++structFlDo.lengthBeforeDot;
		structFlDo.beforeDot = -structFlDo.beforeDot;
		tmpDouble = -tmpDouble;
		structFlDo.afterDot = ft_round_printf(tmpDouble * (ft_pow_printf(10, precision)));
	}
	else
		structFlDo.afterDot = ft_round_printf(tmpDouble * (ft_pow_printf(10, precision)));
	output = (char *)malloc(sizeof(char) * (structFlDo.lengthBeforeDot + structFlDo.dot + precision) + 1);
	fillArrayForDtoa(output, precision, &structFlDo);
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
	(void)varFloat;
	data->current->outputArg = ft_dtoa(varFloat, data->current->precision);
}

void			transformArgLong(t_data *data, int64_t varLong) {
	data->current->outputArg = ft_itoa(varLong);
}

void			transformArgString(t_data *data, char *varString) {
	data->current->outputArg = ft_strdup(varString);
}
