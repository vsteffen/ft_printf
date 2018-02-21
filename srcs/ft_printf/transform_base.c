#include "ft_printf.h"

static uint8_t			countNumeral_base(uintmax_t nb, uint8_t base)
{
	uint8_t 	count;

	count = 1;
	while (nb /= base)
		++count;
	return (count);
}

char			*ft_itoa_base_printf(uintmax_t nb, uint8_t base, char *alph, size_t prec)
{
	char		*output;
	size_t		length;


	if (nb == 0)
		return (ft_strdup("0"));
	length = (size_t)countNumeral_base(nb, base);
	if (length < prec)
		length = prec;
	output = (char *)mallocp(sizeof(char) * length + 1);
	output[length] = '\0';
	while (nb != 0)
	{
		length--;
		output[length] = alph[nb % base];
		nb /= base;
	}
	if (length > 0)
	{
		while (--length > 0)
			output[length] = '0';
		output[0] = '0';
	}
	return (output);
}

void			transform_o(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->flagHash == 1)
			data->current->outputArg = ft_strdup("0");
		else if (data->current->precision == 0 && data->current->flagDot == 1)
			data->current->outputArg = ft_strdup("");
		else
			data->current->outputArg = malloc_prec_zero_doux(data->current->precision, data);
		return ;
	}
	else
		data->current->outputArg = ft_itoa_base_printf(varUIntMax, 8, "0123456789abcdef", data->current->precision);
	if (data->current->flagHash)
	{
		data->current->outputArg = ft_strjoinaf2("0", data->current->outputArg);
	}
}

void			transform_u(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flagDot == 1)
			data->current->outputArg = ft_strdup("");
		else
			data->current->outputArg = malloc_prec_zero_doux(data->current->precision, data);
	}
	else
		data->current->outputArg = ft_itoa_base_printf(varUIntMax, 10, "0123456789abcdef", data->current->precision);
}

void			transform_x(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flagDot == 1)
			data->current->outputArg = ft_strdup("");
		else
			data->current->outputArg = malloc_prec_zero_doux(data->current->precision, data);
	}
	else
		data->current->outputArg = ft_itoa_base_printf(varUIntMax, 16, "0123456789abcdef", data->current->precision);
	if (data->current->flagHash && varUIntMax > 0)
	{
		data->current->outputArg = ft_strjoinaf2("0x", data->current->outputArg);
	}
}

void			transform_X(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flagDot == 1)
			data->current->outputArg = ft_strdup("");
		else
			data->current->outputArg = malloc_prec_zero_doux(data->current->precision, data);
	}
	else
		data->current->outputArg = ft_itoa_base_printf(varUIntMax, 16, "0123456789ABCDEF", data->current->precision);
	if (data->current->flagHash)
	{
		data->current->outputArg = ft_strjoinaf2("0X", data->current->outputArg);
	}
}
