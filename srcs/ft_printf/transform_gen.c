#include "ft_printf.h"

char	*malloc_prec_zero_doux(size_t precision, t_data *data, char conversion) {
	char		*output;
	size_t		pos;

	if (data->current->flagMore && data->current->flagDot == 0 && (conversion == 'd' || conversion == 'f'))
		return (ft_strdup("+0"));
	if (precision == 0)
		return (ft_strdup("0"));
	output = (char*)malloc(sizeof(char) * precision + 0 + 1);
	output[precision] = '\0';
	pos = 0;
	while (pos++ < precision)
		output[pos - 1] = '0';
	return (output);
}

void			transform_n(t_data *data, intmax_t *varIntMax) {
	*varIntMax = data->lenSoFar;
	data->current->outputArg = ft_strdup("");
}
