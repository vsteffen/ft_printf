/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		detect_pattern(t_data *data, char charAnalyse) {
	printf("CHAR %c\n", charAnalyse);
	if (charAnalyse == 'd' || charAnalyse == 'i') {
		printf("'d' conversion detected\n");
		// data->current->type = 1;
		transform_d(data, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'o') {
		printf("'o' conversion detected\n");
		transform_o(data, (uintmax_t)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'u') {
		printf("'u' conversion detected\n");
		transform_u(data, (uintmax_t)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'x') {
		printf("'x' conversion detected\n");
		transform_x(data, (uintmax_t)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'X') {
		printf("'x' conversion detected\n");
		transform_X(data, (uintmax_t)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'D') {
		printf("'D' conversion detected\n");
		transform_d(data, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'O') {
		printf("'O' conversion detected\n");
		transform_o(data, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'U') {
		printf("'U' conversion detected\n");
		transform_u(data, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'p') {
		printf("'p' conversion detected\n");
		transform_p(data, va_arg(data->ap, void *));
		return (0);
	}
	else if (charAnalyse == 'n') {
		printf("'n' conversion detected\n");
		transform_n(data, (intmax_t *)va_arg(data->ap, int *));
		return (0);
	}
	else if (charAnalyse == 'c') {
		printf("'c' conversion detected\n");
		transform_c(data, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 's') {
		printf("'s' conversion detected\n");
		transform_s(data, va_arg(data->ap, char *));
		return (0);
	}
	else if (charAnalyse == 'C') {
		printf("'C' conversion detected\n");
		transform_wide_c(data, va_arg(data->ap, wint_t));
		return (0);
	}
	else if (charAnalyse == 'S') {
		printf("'S' conversion detected\n");
		transform_wide_s(data, va_arg(data->ap, wchar_t *));
		return (0);
	}
	else if (charAnalyse == 'h') {
		if (data->format[data->formatPos + data->moveInArg + 1] == 'h') {
			printf("'hh' length modifier detected\n");
			detect_length_mod_hh(data, data->format[data->formatPos + data->moveInArg + 2]);
			data->moveInArg += 2;
			return (0);
		}
		printf("'h' length modifier detected\n");
		detect_length_mod_h(data, data->format[data->formatPos + data->moveInArg + 1]);
		data->moveInArg++;
		return (0);
	}
	else if (charAnalyse == 'l') {
		if (data->format[data->formatPos + data->moveInArg + 1] == 'l') {
			printf("'ll' length modifier detected\n");
			detect_length_mod_ll(data, data->format[data->formatPos + data->moveInArg + 2]);
			data->moveInArg += 2;
			return (0);
		}
		printf("'l' length modifier detected\n");
		detect_length_mod_l(data, data->format[data->formatPos + data->moveInArg + 1]);
		data->moveInArg++;
		return (0);
	}
	else if (charAnalyse == 'j') {
		printf("'j' length modifier detected\n");
		detect_length_mod_j(data, data->format[data->formatPos + data->moveInArg + 1]);
		data->moveInArg++;
		return (0);
	}
	else if (charAnalyse == 'z') {
		printf("'z' length modifier detected\n");
		detect_length_mod_z(data, data->format[data->formatPos + data->moveInArg + 1]);
		data->moveInArg++;
		return (0);
	}
	else if (charAnalyse == 'f' || charAnalyse == 'F') {
		printf("'f' conversion detected\n");
		// data->current->type = 4;
		if (!data->current->flagDot) {
			data->current->precision = 6;
		}
		transform_f(data, va_arg(data->ap, double));
		return (0);
	}
	else if (charAnalyse == '%') {
		printf("'%%' character detected\n");
		// data->current->type = 5;
		transform_c(data, '%');
		return (0);
	}
	else if (charAnalyse == '.') {
		printf("'.' flag detected\n");
		if (verifFlagAlreadyUsed(data, '.') == 0)
			return (0);
		flagDot(data);
		return (-1);
	}
	else if (ft_isdigit(charAnalyse)) {
		printf("Width flag detected\n");
		if (charAnalyse == '0') {
				data->current->flagZero = 1;
				return (-1);
		}
		// if (verifFlagAlreadyUsed(data, 'w') == 0)
			// return (0);
		data->current->flagWidthNb = 1;
		flagWidthNb(data);
		return (-1);
	}
	else if (charAnalyse == ' ') {
		printf("' ' flag detected\n");
		data->current->flagSpace = 1;
		return (-1);
	}
	else if (charAnalyse == '*') {
		printf("'*' flag detected\n");
		data->current->flagWidthWc = 1;
		int64_t tmpInt64 = va_arg(data->ap, int64_t);
		data->current->width = tmpInt64;
		if (tmpInt64 < 0)
		{
			data->current->width = -tmpInt64;
			data->current->flagLess = 1;
		}
		return (-1);
	}
	else if (charAnalyse == '-') {
		printf("'-' flag detected\n");
		data->current->flagLess = 1;
		return (-1);
	}
	else if (charAnalyse == '+') {
		printf("'+' flag detected\n");
		data->current->flagMore = 1;
		return (-1);
	}
	else if (charAnalyse == '#') {
		printf("'#' flag detected\n");
		data->current->flagHash = 1;
		return (-1);
	}
	else {
		data->error = 1;
		return (0);
	}
}

void get_output_malloc_width(t_arg *arg) {
	size_t		pos;
	char		fillWidth;

	arg->outputWidth = (char*)malloc(sizeof(char) * arg->width + 1);
	arg->outputWidth[arg->width] = '\0';
	pos = 0;
	fillWidth = ' ';
	if (arg->flagZero)
		fillWidth = '0';
	while (pos++ < arg->width)
		arg->outputWidth[pos - 1] = fillWidth;
}

int			parse_and_move_format(t_data *data)
{
	if (data->first == NULL)
	{
		data->first = createStructArg(data);
		data->current = data->first;
	}
	else
	{
		data->current->next = createStructArg(data);
		data->current = data->current->next;
	}
	data->formatMod[data->formatPos] = '\0'; // use to improve speed
	data->moveInArg = 1;
	while(detect_pattern(data, data->format[data->formatPos + data->moveInArg]) == -1)
		data->moveInArg++;
	data->current->outputLength += ft_strlen(data->current->outputArg); // don't forget to think about length of '\0' in %c
	if (data->current->outputLength < data->current->width)
	{
		data->current->width = data->current->width - data->current->outputLength;
		get_output_malloc_width(data->current);
	}
	else
		data->current->width = 0;
	data->lenSoFar += data->current->outputLength + data->current->width;
	return (data->moveInArg);
}
