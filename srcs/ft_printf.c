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

int			parse_and_move_format(t_data *data)
{
		data->formatMod[data->formatPos] = '\0';
		if (data->first == NULL)
		{
			data->first = createStructArg(data);
			data->current = data->first;
		}
		else
			data->current = data->first;
		return (0);
}

void		init_data_and_var(t_data *data, const char * restrict format) {
	bzero(data, sizeof(t_data));
	data->format = format;
	data->formatMod = (char *)ft_strdup(format);
	data->formatPos = -1;
	data->tmpFormatPos = 0;
	data->output = NULL;
	data->first = NULL;
	data->current = NULL;
}

int			ft_printf(const char * restrict format, ...) {
	t_data		data;

	init_data_and_var(&data, format);
	va_start(data.ap, format);
	while (format[++data.formatPos] != '\0') {
		// printf("Char = %c | %s\n", format[data.formatPos], format + data.formatPos);
		if (format[data.formatPos] == '%')
		{
			data.formatPos += parse_and_move_format(&data);
			data.tmpFormatPos = data.formatPos;
			continue ;
		}
	}
	freeArgList(&data);
	va_end(data.ap);
	return (0);
}
