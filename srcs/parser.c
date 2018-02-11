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
	else if (charAnalyse == 'f' || charAnalyse == 'F') {
		printf("'f' conversion detected\n");
		data->current->type = 4;
		if (!data->current->flagDot) {
			data->current->precision = 6;
		}
		transformArgDouble(data, va_arg(data->ap, double));
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
		if (verifFlagAlreadyUsed(data, '.') == 0)
			return (0);
		flagDot(data);
		return (-1);
	}
	else if (ft_isdigit(charAnalyse)) {
		printf("Width character detected\n");
		if (charAnalyse == '0') {
				data->current->flagZero = 1;
				return (-1);
		}
		if (verifFlagAlreadyUsed(data, 'w') == 0)
			return (0);
		flagWidthNb(data);
		return (-1);
	}
	else if (charAnalyse == ' ') {
		printf("' ' character detected\n");
		data->current->flagSpace = 1;
		return (-1);
	}
	else if (charAnalyse == '*') {
		printf("'*' character detected\n");
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
	return (data->moveInArg);
}
