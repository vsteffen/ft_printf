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
	char		*str;

	printf("Trying to find [%c] ...\n", charAnalyse);
	if (charAnalyse == 'd') {
		// printf("inside d --> [%d]\n", va_arg(data->ap, int));
		printf("'d' conversion detected\n");
		data->current->type = malloc(sizeof(int));
		*((int *)data->current->type) = va_arg(data->ap, int);
		printf("inside d --> [%d]\n", *((int *)data->current->type));
		return (0);
	}
	else if (charAnalyse == 'c') {
		printf("'c' conversion detected\n");
		data->current->type = malloc(sizeof(int));
		*((int *)data->current->type) = va_arg(data->ap, int);
		printf("inside c --> [%c]\n", *((char *)data->current->type));
		return (0);
	}
	else if (charAnalyse == 's') {
		str = va_arg(data->ap, char *);
		printf("inside str --> [%s]\n", str);
		printf("'s' conversion detected\n");
		data->current->type = (char *)malloc(sizeof(char *) * ft_strlen(str));
		*((char **)data->current->type) = str;
		printf("inside s --> [%s]\n", *((char **)data->current->type));
		return (0);
	}
	else
		return (1);
}

int			parse_and_move_format(t_data *data)
{
		if (data->first == NULL)
		{
			data->first = createStructArg(data);
			data->current = data->first;
		}
		else
			data->current = data->first;
		data->formatMod[data->formatPos] = '\0'; // use to improve speed
		data->formatPos++;
		while(detect_pattern(data, data->format[data->formatPos]) == -1)
			(void)data;
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
