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

size_t			ft_wstrlen(wchar_t *str)
{
		size_t		length;

		length = 0;
		if (str)
			while (str[length])
				length++;
		return (length);
}

void			transform_wide_c(t_data *data, wint_t wide) {
	(void)wide;
	(void)data;
	printf("Sizeof wchar_t %lu and wint_t %lu\n", sizeof(wchar_t), sizeof(wint_t));
}

char			get_wchar_part(wchar_t wide, size_t part)
{
	wchar_t		tmp;

	(void)wide;
	tmp = 0xFF;
	tmp = tmp << (8 * part);
	tmp = wide & tmp;
	tmp = tmp >> (8 * part);
	printf("Value of tmp = %lu\n", (size_t)tmp);
	return ((char)tmp);
}



int			get_wchar(wchar_t wide, char *output, size_t outputPos)
{
	printf("+-+-+-+-+-+-+\n");
	printf("VALUE OF WCHAR = %x\n", wide);
	if (wide <= 0x7F) {
		printf("1 byte used\n");
		output[outputPos] = wide & 0x7F;
		output[outputPos + 1] = 0;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
	}
	else if (wide <= 0x7FF) {
		printf("2 bytes used\n");
		output[outputPos] = (wide >> 6) | 0xC0;
		output[outputPos + 1] = ((wide & 0x3F) | 0x80) & 0xBF;
		output[outputPos + 2] = 0;
		output[outputPos + 3] = 0;
	}
	//---------------
	else if (wide <= 0xFFFF) {
		printf("3 bytes used\n");
		output[outputPos] = (wide >> 12) | 0xE0;
		output[outputPos + 1] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 2] = (wide | 0x80) & 0xBF;
		output[outputPos + 3] = 0;
	}
	else if (wide <= 0x10FFFF) {
		output[outputPos] = (wide >> 18) | 0xF0;
		output[outputPos + 1] = ((wide >> 12) | 0x80) & 0xBF;
		output[outputPos + 2] = ((wide >> 6) | 0x80) & 0xBF;
		output[outputPos + 3] = (wide | 0x80) & 0xBF;
	}
	else
		return (-1);
	return (0);

}

void			transform_wide_s(t_data *data, wchar_t *wide) {
	size_t		length;
	size_t		pos;
	size_t		outputPos;
	char		*output;


	(void)data;
	length = ft_wstrlen(wide);
	// printf("Length of wide = %lu\n", length);
	output = (char *)malloc(sizeof(char) * length * 4 + 1);
	pos = 0;
	outputPos = 0;
	// ft_bzero(output, length * 4 + 1);
	while (wide[pos])
	{
		if (get_wchar(wide[pos], output, outputPos) == -1)
		{
			data->error = 1;
			return ;
		}
		outputPos += 4;
		pos++;
	}
	output[outputPos] = '\0';
	printf("Value of first char [%x] [%x] [%x] [%x]\n", output[0], output[1], output[2], output[3]);
	printf("First char = [%s]\n", output);
	// wide[length * size] = '\0';
	data->current->outputArg = output;
	// printf("OUTPUT = %s\n", output);
}
