#include "ft_printf.h"

void			transform_r(t_data *data, int64_t byte) {
	size_t		prec;
	char		*output;
	int64_t		tmpInt64;
	size_t		count;

	prec = data->current->precision;
	if (data->current->flag_dot != 1)
		prec = 64;
	if (prec == 0)
		return ;
	if (prec > 64)
		prec = 64;
	output = (char *)malloc(sizeof(char) * prec + 1);
	output[prec] = '\0';
	tmpInt64 = 0x01;
	count = prec;
	while (count > 0)
	{
		if (byte & tmpInt64)
			output[count - 1] = '1';
		else
			output[count - 1] = '0';
		tmpInt64 *= 2;
		count--;
	}
	data->current->output_arg = output;
}
