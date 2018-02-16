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

void			transform_c(t_data *data, char varChar) {
	char  *output;

	output = (char*)malloc(sizeof(char) * 2);
	output[0] = (char)varChar;
	output[1] = '\0';
	data->current->outputArg = output;
	if (varChar == '\0')
		data->current->outputLength++;
}

void			transform_s(t_data *data, char *varString) {
	if (varString == NULL)
		data->current->outputArg = ft_strdup("(null)");
	else
		data->current->outputArg = ft_strdup(varString);
}

void			transform_n(t_data *data, intmax_t *varIntMax) {
	(void)data;
	*varIntMax = 89;
	data->current->outputArg = ft_strdup("");
}
