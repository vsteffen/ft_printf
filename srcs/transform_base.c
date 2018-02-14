#include "ft_printf.h"

static uint8_t			countNumeral(uintmax_t nb, uint8_t base)
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
	length = (size_t)countNumeral(nb, base);
	if (length < prec)
		length = prec;
	output = (char *)mallocp(sizeof(char) * length + 1);
	output[length] = '\0';
	while (nb != 0)
	{
		length--;
		// printf("Add [%c] at %zu\n", alph[nb % base], length);
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
	data->current->outputArg = ft_itoa_base_printf(varUIntMax, 8, "0123456789abcdef", data->current->precision);
}

void			transform_u(t_data *data, uintmax_t varUIntMax) {
	data->current->outputArg = ft_itoa_base_printf(varUIntMax, 10, "0123456789abcdef", data->current->precision);
}

void			transform_x(t_data *data, uintmax_t varUIntMax) {
	data->current->outputArg = ft_itoa_base_printf(varUIntMax, 16, "0123456789abcdef", data->current->precision);
}

void			transform_X(t_data *data, uintmax_t varUIntMax) {
	data->current->outputArg = ft_itoa_base_printf(varUIntMax, 16, "0123456789ABCDEF", data->current->precision);
}
