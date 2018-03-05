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
	if (data->current->flag_hash == 1)
	{
		// if (data->current->precision == 0 && data->current->flag_dot == 1)
		if (varUIntMax == 0)
		{
			// printf("\nICI 1\n");
			if (data->current->flag_dot == 1 && data->current->precision > 0)
				data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'o');
			else
				data->current->output_arg = ft_strdup("0");
		}
		else if (data->current->flag_dot == 1)
		{
			data->current->output_arg = ft_itoa_base_printf(varUIntMax, 8, "0123456789abcdef", data->current->precision);
			if (data->current->precision == 0)
				data->current->output_arg = ft_strjoinaf2("0", data->current->output_arg);
		}
		else
		{
			data->current->output_arg = ft_itoa_base_printf(varUIntMax, 8, "0123456789abcdef", data->current->precision);
				data->current->output_arg = ft_strjoinaf2("0", data->current->output_arg);
		}
		return ;
	}
	else if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup("");
		else
			data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'o');
		return ;
	}
	else
		data->current->output_arg = ft_itoa_base_printf(varUIntMax, 8, "0123456789abcdef", data->current->precision);
}

void			transform_u(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup("");
		else
			data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'u');
	}
	else
		data->current->output_arg = ft_itoa_base_printf(varUIntMax, 10, "0123456789abcdef", data->current->precision);
}

void			transform_x(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup("");
		else
			data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'x');
	}
	else
		data->current->output_arg = ft_itoa_base_printf(varUIntMax, 16, "0123456789abcdef", data->current->precision);
	if (data->current->flag_hash && varUIntMax > 0)
	{
		data->current->output_arg = ft_strjoinaf2("0x", data->current->output_arg);
	}
}

void			transform_X(t_data *data, uintmax_t varUIntMax) {
	if (varUIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup("");
		else
			data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'X');
	}
	else
		data->current->output_arg = ft_itoa_base_printf(varUIntMax, 16, "0123456789ABCDEF", data->current->precision);
	if (data->current->flag_hash && varUIntMax > 0)
	{
		data->current->output_arg = ft_strjoinaf2("0X", data->current->output_arg);
	}
}
