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

int		detect_pattern(t_data *data, char charAnalyse) {
	if (charAnalyse == 'd') {
		printf("'d' conversion detected\n");
		data->current->type = 1;
		transformArgInt(data, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'c') {
		printf("'c' conversion detected\n");
		data->current->type = 2;
		transformArgChar(data, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 's') {
		printf("'s' conversion detected\n");
		data->current->type = 3;
		transformArgString(data, va_arg(data->ap, char *));
		return (0);
	}
	else if (charAnalyse == 'f') {
		printf("'f' conversion detected\n");
		data->current->type = 4;
		transformArgFloat(data, va_arg(data->ap, double));
		return (0);
	}
	else if (charAnalyse == '%') {
		printf("'%%' character detected\n");
		data->current->type = 5;
		transformArgChar(data, '%');
		return (0);
	}
	else if (charAnalyse == '.') {
		printf("'.' character detected\n");
		data->current->type = 6;
		flagDot(data);
		return (0);
	}
	else {
		data->error = 1;
		return (0);
	}
}

int			parse_and_move_format(t_data *data)
{
		if (data->first == NULL)
		{
			data->first = createStructArg(data);
			data->current = data->first;
		}
		else {
			data->current->next = createStructArg(data);
			data->current = data->current->next;
		}
		data->formatMod[data->formatPos] = '\0'; // use to improve speed
		data->moveInArg = 1;
		while(detect_pattern(data, data->format[data->formatPos + data->moveInArg]) == -1) {
			data->moveInArg++;
		}
		printf("+-+-+-+ [%s] and moveArg = %lu +-+-+-+\n", data->current->outputArg, data->moveInArg);
		return (data->moveInArg);
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

int		exitPrintf(t_data *data) {
	printf("Errror encountered -> %lu", data->error);
	return (0);
}

int			ft_printf(const char * restrict format, ...) {
	t_data		data;

	init_data_and_var(&data, format);
	va_start(data.ap, format);
	while (format[++data.formatPos] != '\0') {
		// printf("WHILE ON FORMAT -> %c at %lu\n", format[data.formatPos], data.formatPos);
		if (format[data.formatPos] == '%')
		{
			data.formatPos += parse_and_move_format(&data);
			data.tmpFormatPos = data.formatPos + 1;
			if (data.error == 1)
				return (exitPrintf(&data));
			continue ;
		}
	}
	printf("\nRESULT:\n");
	printArgAndFree(&data);
	// printf("]\n");
	va_end(data.ap);
	return (0);
}
