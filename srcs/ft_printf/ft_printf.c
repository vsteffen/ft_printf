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
	data->format_mod = (char *)ft_strdup(format);
	data->format_pos = 0;
	data->tmp_format_pos = 0;
	data->error = 0;
	data->len_so_far = 0;
	data->color_set = 0;
	data->fd = 1;
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

	// printf("\nFORMAT = [%s]\n", format);// -> [%c] at %lu\n", format, format[data.format_pos], data.format_pos);
	init_data_and_var(&data, format);
	va_start(data.ap, format);
	// intmax_t arg_wildcard = (intmax_t)va_arg(data.ap, intmax_t);
	// intmax_t var_int_max = (intmax_t)-42;
	// printf("arg_wildcard = %jd vs var_int_max = %jd\n", arg_wildcard, var_int_max);
	while (format[data.format_pos] != '\0') {
		// printf("WHILE ON FORMAT [%s] -> [%c] at %lu\n", format, format[data.format_pos], data.format_pos);
		if (format[data.format_pos] == '%')
		{
			/*
			if (format[data.format_pos + 1] == '\0')
			{
				data.tmp_format_pos = data.format_pos + 1;
				data.format_pos++;
				continue ;
			}
			*/
			data.format_pos += parse_and_move_format(&data);
			if (data.error > 0)
			{
				// printf("KOUKOU\n");
				if (data.error != 100)
					data.format_pos--;
				data.error = 0;
				// return (exitPrintf(&data));
			}
			data.tmp_format_pos = data.format_pos + 1;
			// printf("\nChar received ... [%c]\n", format[data.format_pos]);
			data.format_pos++;
			continue ;
		}
		data.format_pos++;
		data.len_so_far++;
	}
	print_arg_and_free(&data);
	length = data.len_so_far;
	free(data.format_mod);
	va_end(data.ap);
	return (length);
}
