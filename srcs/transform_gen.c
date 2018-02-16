#include "ft_printf.h"

char	*malloc_prec_zero_doux(size_t precision) {
	char		*output;
	size_t		pos;

	printf("PREC = %zu\n", precision);
	output = (char*)malloc(sizeof(char) * precision + 1);
	output[precision] = '\0';
	pos = 0;
	while (pos++ < precision)
		output[pos - 1] = '0';
	return (output);
}

void			transform_n(t_data *data, intmax_t *varIntMax) {
	(void)data;
	*varIntMax = 89;
	// data->current->outputArg = ft_strdup("");
}
