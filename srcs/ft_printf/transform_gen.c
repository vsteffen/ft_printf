#include "ft_printf.h"

char	*malloc_prec_zero_doux(size_t precision) {
	char		*output;
	size_t		pos;

	// if (precision == 0 && (data->current->flagWidthNb || data->current->flagWidthWc))
	if (precision == 0)
		return (ft_strdup("0"));
	output = (char*)malloc(sizeof(char) * precision + 0 + 1);
	output[precision] = '\0';
	pos = 0; //+ 1;
	// printf("MDR\n");
	// if (1 == 1)
	// {
	// 	output[0] = '+';
	// 	pos++;
	// }
	while (pos++ < precision)
		output[pos - 1] = '0';
	return (output);
}

void			transform_n(t_data *data, intmax_t *varIntMax) {
	(void)data;
	*varIntMax = 89;
	// data->current->outputArg = ft_strdup("");
}
