#include "ft_printf.h"

static size_t	nb_numeral_d(intmax_t n)
{
	size_t count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

char			*ft_itoa_printf(t_data *data, intmax_t n, size_t prec)
{
	size_t				len;
	char				*str;
	uintmax_t			tmp_nb;

	(void)prec;
	len = nb_numeral_d(n);
	if (len < prec)
		len = prec;
	tmp_nb = n;
	if (n < 0)
	{
		tmp_nb = -n;
		len++;
	}
	if (n >= 0 && data->current->flagMore)
		len++;
	str = (char*)mallocp(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	str[--len] = tmp_nb % 10 + '0';
	while (tmp_nb /= 10)
		str[--len] = tmp_nb % 10 + '0';
	if (len - data->current->flagMore > 0)
	{
		while (--len > 0)
			str[len] = '0';
		str[0] = '0';
	}
	if (data->current->flagMore)
	{
		str[0] = '+';
		if (data->current->flagZero == 1)
			data->current->flagZero = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		if (data->current->flagZero == 1)
			data->current->flagZero = 2;
	}
	return (str);
}

void			transform_d(t_data *data, intmax_t varIntMax) {
	if (varIntMax == 0)
	{
		if (data->current->precision == 0 && data->current->flagDot == 1)
			data->current->outputArg = ft_strdup("");
		else
			data->current->outputArg = malloc_prec_zero_doux(data->current->precision, data, 'd');
	}
	else
		data->current->outputArg = ft_itoa_printf(data, varIntMax, data->current->precision);
	if (data->current->flagSpace == 1 && data->current->outputArg[0] != '+' && data->current->outputArg[0] != '-')
		data->current->outputArg = ft_strjoinaf2(" ", data->current->outputArg);
}
