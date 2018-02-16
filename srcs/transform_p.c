#include "ft_printf.h"

static uint8_t			countNumeral(uintmax_t nb, uint8_t base)
{
	uint8_t 	count;

	count = 1;
	while (nb /= base)
		++count;
	return (count);
}

char			*ft_ptoa_base_printf(uintptr_t nb, uint8_t base, char *alph, size_t prec)
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

void			transform_p(t_data *data, void *ptr) {
	uintptr_t uip = (uintptr_t)ptr;
	data->current->outputArg = ft_ptoa_base_printf(uip, 16, "0123456789abcdef", data->current->precision);
	data->current->outputArg = ft_strjoinaf2("0x", data->current->outputArg);
}
