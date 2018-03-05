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
	if (charAnalyse == 'd' || charAnalyse == 'i') {
		transform_d(data->current, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'o') {
		transform_o(data->current, (unsigned int)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'u') {
		transform_u(data->current, (unsigned int)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'x') {
		transform_x(data->current, (unsigned int)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'X') {
		transform_bx(data->current, (unsigned int)va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 'D') {
		transform_d(data->current, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'O') {
		transform_o(data->current, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'U') {
		transform_u(data->current, (long int)va_arg(data->ap, long int));
		return (0);
	}
	else if (charAnalyse == 'p') {
		transform_p(data->current, va_arg(data->ap, void *));
		return (0);
	}
	else if (charAnalyse == 'r') {
		transform_r(data->current, (int64_t)va_arg(data->ap, int64_t));
		return (0);
	}
	else if (charAnalyse == 'n') {
		transform_n(data, (intmax_t *)va_arg(data->ap, int *));
		return (0);
	}
	else if (charAnalyse == 'c') {
		transform_c(data, va_arg(data->ap, int));
		return (0);
	}
	else if (charAnalyse == 's') {
		transform_s(data, va_arg(data->ap, char *));
		return (0);
	}
	else if (charAnalyse == 'C') {
		transform_wide_c(data, (wchar_t)va_arg(data->ap, wint_t));
		return (0);
	}
	else if (charAnalyse == 'S') {
		transform_wide_s(data, va_arg(data->ap, wchar_t *));
		return (0);
	}
	else if (charAnalyse == 'h') {
		if (data->format[data->format_pos + data->move_in_arg + 1] == 'h') {
			detect_length_mod_hh1(data, data->format[data->format_pos + data->move_in_arg + 2]);
			data->move_in_arg += 2;
			return (0);
		}
		detect_length_mod_h1(data, data->format[data->format_pos + data->move_in_arg + 1]);
		data->move_in_arg++;
		return (0);
	}
	else if (charAnalyse == 'l') {
		if (data->format[data->format_pos + data->move_in_arg + 1] == 'l') {
			detect_length_mod_ll1(data, data->format[data->format_pos + data->move_in_arg + 2]);
			data->move_in_arg += 2;
			return (0);
		}
		detect_length_mod_l1(data, data->format[data->format_pos + data->move_in_arg + 1]);
		data->move_in_arg++;
		return (0);
	}
	else if (charAnalyse == 'j') {
		detect_length_mod_j1(data, data->format[data->format_pos + data->move_in_arg + 1]);
		data->move_in_arg++;
		return (0);
	}
	else if (charAnalyse == 'z') {
		detect_length_mod_z1(data, data->format[data->format_pos + data->move_in_arg + 1]);
		data->move_in_arg++;
		return (0);
	}
	else if (charAnalyse == 'f' || charAnalyse == 'F') {
		if (!data->current->flag_dot) {
			data->current->precision = 6;
		}
		transform_f(data->current, va_arg(data->ap, double));
		return (0);
	}
	else if (charAnalyse == '%') {
		transform_c(data, '%');
		return (0);
	}
	else if (charAnalyse == '.') {
		if (verif_flag_already_used(data, '.') == 0)
			return (0);
		flag_dot(data);
		return (-1);
	}
	else if (ft_isdigit(charAnalyse)) {
		if (charAnalyse == '0' && data->current->flag_dot == 0 && data->current->flag_less == 0) {
				data->current->flag_zero = 1;
				return (-1);
		}
		data->current->flag_width_nb = 1;
		flag_width_nb(data);
		return (-1);
	}
	else if (charAnalyse == ' ') {
		data->current->flag_space = 1;
		return (-1);
	}
	else if (charAnalyse == '*') {
		data->current->flag_width_wc = 1;
		int tmpInt = va_arg(data->ap, int);
		if (tmpInt < 0)
		{
			tmpInt = -tmpInt;
			data->current->flag_less = 1;
		}
		data->current->width = (size_t)tmpInt;
		return (-1);
	}
	else if (charAnalyse == '-') {
		data->current->flag_less = 1;
		if (data->current->flag_zero > 0)
			data->current->flag_zero = 0;
		return (-1);
	}
	else if (charAnalyse == '+') {
		data->current->flag_more = 1;
		return (-1);
	}
	else if (charAnalyse == '#') {
		data->current->flag_hash = 1;
		return (-1);
	}
	else if (charAnalyse == '{' && data->move_in_arg == 1) {
		flag_color_fd(data, data->format + data->format_pos + data->move_in_arg + 1);
		while (data->format[data->format_pos + data->move_in_arg] == ',')
			flag_color_fd(data, data->format + data->format_pos + data->move_in_arg + 1);
		if (data->format[data->format_pos + data->move_in_arg] != '}' && data->error == 0)
		{
			data->error = 1;
			data->len_so_far -= ft_strlen(data->current->output_arg);
			data->current->output_arg[0] = '\0';
			data->move_in_arg = 1;
		}
		return (0);
	}
	else {
		data->error = 100;
		if (charAnalyse != '\0')
		{
			data->current->output_arg = ft_strdup("q");
			data->current->output_arg[0] = data->format_mod[data->format_pos + data->move_in_arg];
		}
		return (0);
	}
}

void get_output_malloc_width(t_arg *arg, char firstCharOutput, char lastConv) {
	size_t		pos;
	char		fillWidth;

	arg->output_width = (char*)malloc(sizeof(char) * arg->width + 1);
	arg->output_width[arg->width] = '\0';
	pos = 0;
	fillWidth = ' ';
	if (arg->flag_zero > 0 || (arg->flag_zero_weird == 1 && (lastConv == 'c' || lastConv == 's' || lastConv == '%' || lastConv == 'Z' || lastConv == 'S')))
		fillWidth = '0';
	while (pos++ < arg->width)
		arg->output_width[pos - 1] = fillWidth;
	if (arg->flag_space == 1 && arg->flag_zero == 1)
	{
		arg->output_width[0] = ' ';
		arg->output_arg[0] = '0';
	}
	if (arg->flag_zero > 0 && (firstCharOutput == '+' || firstCharOutput == '-'))
	{
		arg->output_width[0] = firstCharOutput;
		arg->output_arg[0] = '0';
	}
	if (arg->flag_zero == 1 && arg->flag_hash == 1 && arg->output_width[1] != '\0' && (lastConv == 'x' || lastConv == 'X'))
	{
		arg->output_width[1] = 'x';
		arg->output_arg[1] = '0';
	}
	if (arg->flag_zero == 1 && arg->output_width[1] != '\0' && lastConv == 'p')
	{
		arg->output_width[1] = 'x';
		arg->output_arg[1] = '0';
	}
}

int			parse_and_move_format(t_data *data)
{
	if (data->first == NULL)
	{
		data->first = create_struct_arg(data);
		data->current = data->first;
	}
	else
	{
		data->current->next = create_struct_arg(data);
		data->current = data->current->next;
	}
	data->format_mod[data->format_pos] = '\0';
	data->move_in_arg = 1;
	while(detect_pattern(data, data->format[data->format_pos + data->move_in_arg]) == -1)
		data->move_in_arg++;
	if (data->format[data->format_pos + data->move_in_arg] == '\0')
		return (data->move_in_arg - 1);
	if (data->current->output_wide_length > 0)
		data->current->output_length += data->current->output_wide_length;
	else
		data->current->output_length += ft_strlen(data->current->output_arg);
	if (data->current->output_arg == NULL && data->error > 0 && data->error != 100)
		data->current->output_arg = ft_strdup("");
	if (data->current->output_length < data->current->width)
	{
		data->current->width = data->current->width - data->current->output_length;
		if (data->current->output_arg != NULL)
			get_output_malloc_width(data->current, data->current->output_arg[0], data->format[data->format_pos + data->move_in_arg]);
	}
	else
		data->current->width = 0;
	data->len_so_far += data->current->output_length + data->current->width;
	return (data->move_in_arg);
}
