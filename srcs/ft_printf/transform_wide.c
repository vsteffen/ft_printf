#include "ft_printf.h"

char	*ft_strdup_mod_prec(const char *s, size_t prec)
{
	size_t		pos;
	char		*dest;

	pos = 0;
	dest = (char*)mallocp(sizeof(char) * prec + 1);
	while (s[pos] && prec > pos)
	{
		dest[pos] = s[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

void			transform_c(t_data *data, char varChar) {
	char  *output;

	output = (char*)malloc(sizeof(char) * 2);
	output[0] = varChar;
	output[1] = '\0';
	data->current->outputArg = output;
	if (varChar == '\0')
		data->current->outputLength++;
}

void			transform_s(t_data *data, char *varString) {
	if (varString == NULL)
	{
		if (data->current->flagDot == 1)
			data->current->outputArg = ft_strdup_mod_prec("(null)", data->current->precision);
		else
			data->current->outputArg = ft_strdup("(null)");
	}
	else
	{
		if (data->current->flagDot == 1)
			data->current->outputArg = ft_strdup_mod_prec(varString, data->current->precision);
		else
			data->current->outputArg = ft_strdup(varString);

	}
}

size_t			ft_wstrlen(wchar_t *str)
{
		size_t		length;

		length = 0;
		if (str)
			while (str[length])
				length++;
		return (length);
}

int			get_wchar(wchar_t wide, char *output, size_t outputPos, t_data *data)
{
	if (wide <= 0x7F) {
		output[outputPos] = wide & 0x7F;
		output[outputPos + 1] = 0;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
		data->current->trueLengthWide += 1;
	}
	else if (wide <= 0x7FF) {
		output[outputPos] = (wide >> 6) | 0xC0;
		output[outputPos + 1] = ((wide & 0x3F) | 0x80) & 0xBF;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
		data->current->trueLengthWide += 2;
	}
	else if (wide <= 0xFFFF) {
		output[outputPos] = (wide >> 12) | 0xE0;
		output[outputPos + 1] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 2] = (wide | 0x80) & 0xBF;
		output[outputPos + 3] = 0;
		data->current->trueLengthWide += 3;
	}
	else if (wide <= 0x10FFFF) {
		output[outputPos] = (wide >> 18) | 0xF0;
		output[outputPos + 1] = ((wide >> 12) | 0x80) & 0xBF;
		output[outputPos + 2] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 3] = (wide | 0x80) & 0xBF;
		data->current->trueLengthWide += 4;
	}
	else
		return (-1);
	return (0);
}

void			transform_wide_c(t_data *data, wchar_t wide) {
	// (void)wide;
	// (void)data;

	char		*output;

	output = (char *)malloc(sizeof(char) * 4 + 1);
	if (get_wchar(wide, output, 0, data) == -1)
	{
		data->error = 1;
		return ;
	}
	output[4] = '\0';
	data->current->outputArg = output;
	data->current->outputWideLength = 4;
}

void			transform_wide_s(t_data *data, wchar_t *wide) {
	size_t		length;
	size_t		pos;
	size_t		outputPos;
	char		*output;


	length = ft_wstrlen(wide);
	output = (char *)malloc(sizeof(char) * length * 4 + 1);
	pos = 0;
	outputPos = 0;
	while (wide[pos])
	{
		if (get_wchar(wide[pos], output, outputPos, data) == -1)
		{
			data->error = 1;
			return ;
		}
		outputPos += 4;
		pos++;
	}
	output[outputPos] = '\0';
	// printf("Value of first char [%x] [%x] [%x] [%x]\n", output[0], output[1], output[2], output[3]);
	// printf("First char = [%s]\n", output);
	data->current->outputArg = output;
	data->current->outputWideLength = outputPos;
}
