#include "ft_printf.h"

char	*ft_strdup_mod_prec(const char *s, size_t prec, int8_t flag_asterisk)
{
	size_t		pos;
	char		*dest;

	pos = 0;
	dest = (char*)mallocp(sizeof(char) * prec + 1);
	while (s[pos] && (flag_asterisk == 1 || prec > pos))
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
	data->current->output_arg = output;
	if (varChar == '\0')
		data->current->output_length++;
}

void			transform_s(t_data *data, char *varString) {
	if (varString == NULL)
	{
		if (data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup_mod_prec("(null)", data->current->precision, data->current->flag_asterisk);
		else
			data->current->output_arg = ft_strdup("(null)");
	}
	else
	{
		if (data->current->flag_dot == 1)
			data->current->output_arg = ft_strdup_mod_prec(varString, data->current->precision, data->current->flag_asterisk);
		else
			data->current->output_arg = ft_strdup(varString);

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

int			get_wchar(wchar_t wide, char *output, size_t outputPos)
{
	// printf("\nPOSITION = %lu and char analysed is [%C]\n", outputPos, wide);
	if (wide <= 0x7F) {
		output[outputPos] = wide & 0x7F;
		output[outputPos + 1] = 0;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
		// printf("RETURNING 1\n");
		return (1);
	}
	else if (wide <= 0x7FF) {
		output[outputPos] = (wide >> 6) | 0xC0;
		output[outputPos + 1] = ((wide & 0x3F) | 0x80) & 0xBF;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
		// printf("RETURNING 2\n");
		return (2);
	}
	else if (wide <= 0xFFFF) {
		output[outputPos] = (wide >> 12) | 0xE0;
		output[outputPos + 1] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 2] = (wide | 0x80) & 0xBF;
		output[outputPos + 3] = 0;
		// printf("RETURNING 3\n");
		return (3);
	}
	else if (wide <= 0x10FFFF) {
		output[outputPos] = (wide >> 18) | 0xF0;
		output[outputPos + 1] = ((wide >> 12) | 0x80) & 0xBF;
		output[outputPos + 2] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 3] = (wide | 0x80) & 0xBF;
		// printf("RETURNING 4\n");
		return (4);
	}
	return (0);
}

void			transform_wide_c(t_data *data, wchar_t wide) {
	// (void)wide;
	// (void)data;

	char		*output;

	output = (char *)malloc(sizeof(char) * 4 + 1);
	if ((data->current->output_wide_length += get_wchar(wide, output, 0)) == 0)
	{
		// free(output);
		data->error = 1;
		return ;
	}
	output[data->current->output_wide_length] = '\0';
	data->current->output_arg = output;
}

void reset_output_for_precision(char *output, t_data *data, size_t tmpWideLength)
{
	while (tmpWideLength < data->current->output_wide_length)
	{
		output[data->current->output_wide_length] = '\0';
		data->current->output_wide_length--;
	}
}

void			transform_wide_s(t_data *data, wchar_t *wide) {
	size_t		length;
	size_t		pos;
	char		*output;
	size_t		tmpWideLength;

	if (wide == NULL)
	{
		data->current->output_arg = ft_strdup("(null)");
		return ;
	}
	// if (data->current->flag_dot == 1 && data->current->output_wide_length > data->current->precision)
	// {
	// 	data->current->output_arg = malloc_prec_zero_doux(data->current->precision, data->current, 'd');
	// }
	length = ft_wstrlen(wide);
	output = (char *)malloc(sizeof(char) * length * 4 + 1);
	pos = 0;
	tmpWideLength = 0;
	data->current->output_wide_length = 0;
	while (wide[pos])
	{
		tmpWideLength = data->current->output_wide_length;
		if ((data->current->output_wide_length += get_wchar(wide[pos], output, data->current->output_wide_length)) == 0)
		{
			data->error = 1;
			return ;
		}
		if (data->current->flag_asterisk == 0 && data->current->flag_dot == 1 && data->current->output_wide_length > data->current->precision)
		{
			reset_output_for_precision(output, data, tmpWideLength);
			break ;
		}
		pos++;
	}
	output[data->current->output_wide_length] = '\0';
	// printf("Value of first char [%x] [%x] [%x] [%x]\n", output[0], output[1], output[2], output[3]);
	// printf("First char = [%s]\n", output);
	data->current->output_arg = output;
	data->current->output_wide_length = data->current->output_wide_length;
}
