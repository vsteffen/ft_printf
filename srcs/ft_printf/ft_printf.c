/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_data_and_var(t_data *data, const char * restrict format) {
	// bzero(data, sizeof(t_data));
	data->format = format;
	data->formatMod = (char *)ft_strdup(format);
	data->formatPos = 0;
	data->tmpFormatPos = 0;
	data->error = 0;
	data->lenSoFar = 0;
	data->first = NULL;
	data->current = NULL;
}

int		exitPrintf(t_data *data) {
	(void)data;
	// printf("Error encountered -> %hhd\n", data->error);
	return (0);
}

int			ft_printf(const char * restrict format, ...) {
	t_data		data;
	size_t		length;

	// printf("\nFORMAT = [%s]\n", format);// -> [%c] at %lu\n", format, format[data.formatPos], data.formatPos);
	init_data_and_var(&data, format);
	va_start(data.ap, format);
	// intmax_t argWildcard = (intmax_t)va_arg(data.ap, intmax_t);
	// intmax_t varIntMax = (intmax_t)-42;
	// printf("argWildcard = %jd vs varIntMax = %jd\n", argWildcard, varIntMax);
	while (format[data.formatPos] != '\0') {
		// printf("WHILE ON FORMAT [%s] -> [%c] at %lu\n", format, format[data.formatPos], data.formatPos);
		if (format[data.formatPos] == '%')
		{
			/*
			if (format[data.formatPos + 1] == '\0')
			{
				data.tmpFormatPos = data.formatPos + 1;
				data.formatPos++;
				continue ;
			}
			*/
			data.formatPos += parse_and_move_format(&data);
			if (data.error > 0)
			{
				// printf("KOUKOU\n");
				if (data.error != 100)
					data.formatPos--;
				data.error = 0;
				// return (exitPrintf(&data));
			}
			data.tmpFormatPos = data.formatPos + 1;
			// printf("\nChar received ... [%c]\n", format[data.formatPos]);
			data.formatPos++;
			continue ;
		}
		data.formatPos++;
		data.lenSoFar++;
	}
	printArgAndFree(&data);
	length = data.lenSoFar;
	free(data.formatMod);
	va_end(data.ap);
	return (length);
}
