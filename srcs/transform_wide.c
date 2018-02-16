#include "ft_printf.h"

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

void			transform_wide_c(t_data *data, wint_t wide) {
	(void)wide;
	(void)data;
}

void			transform_wide_s(t_data *data, wchar_t *wide) {
	(void)wide;
	(void)data;
}
