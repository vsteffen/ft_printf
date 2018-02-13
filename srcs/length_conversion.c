/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	detect_length_mod_hh(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'o')
		transform_o(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'u')
		transform_u(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'x')
		transform_x(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'X')
		transform_X(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'n')
		transform_n_char(data, va_arg(data->ap, signed char *));
	else
		data->error = 1;
}

void	detect_length_mod_h(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'o')
		transform_o(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'u')
		transform_u(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'x')
		transform_x(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'X')
		transform_X(data, (intmax_t)va_arg(data->ap, int));
	else if (conversion == 'n')
		transform_n_short(data, va_arg(data->ap, short *));
	else
		data->error = 1;
}

void	detect_length_mod_l(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, long));
	else if (conversion == 'o')
		transform_o(data, (intmax_t)va_arg(data->ap, unsigned long));
	else if (conversion == 'u')
		transform_u(data, (intmax_t)va_arg(data->ap, unsigned long));
	else if (conversion == 'x')
		transform_x(data, (intmax_t)va_arg(data->ap, unsigned long));
	else if (conversion == 'X')
		transform_X(data, (intmax_t)va_arg(data->ap, unsigned long));
	else if (conversion == 'n')
		transform_n_l(data, va_arg(data->ap, long *));
	else
		data->error = 1;
}

void	detect_length_mod_ll(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, long long));
	else if (conversion == 'o')
		transform_o_unsigned(data, (uintmax_t)va_arg(data->ap, unsigned long long));
	else if (conversion == 'u')
		transform_u_unsigned(data, (uintmax_t)va_arg(data->ap, unsigned long long));
	else if (conversion == 'x')
		transform_x_unsigned(data, (uintmax_t)va_arg(data->ap, unsigned long long));
	else if (conversion == 'X')
		transform_X_unsigned(data, (uintmax_t)va_arg(data->ap, unsigned long long));
	else if (conversion == 'n')
		transform_n_ll(data, va_arg(data->ap, long long *));
	else
		data->error = 1;
}

void	detect_length_mod_j(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, intmax_t));
	else if (conversion == 'o')
		transform_o_unsigned(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'u')
		transform_u_unsigned(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'x')
		transform_x_unsigned(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'X')
		transform_X_unsigned(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'n')
		transform_n_intmax(data, va_arg(data->ap, intmax_t *));
	else
		data->error = 1;
}

void	detect_length_mod_z(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, va_arg(data->ap, intmax_t));
	else if (conversion == 'o')
		transform_o_unsigned(data, (uintmax_t)va_arg(data->ap, size_t));
	else if (conversion == 'u')
		transform_u_unsigned(data, (uintmax_t)va_arg(data->ap, size_t));
	else if (conversion == 'x')
		transform_x_unsigned(data, (uintmax_t)va_arg(data->ap, size_t));
	else if (conversion == 'X')
		transform_X_unsigned(data, (uintmax_t)va_arg(data->ap, size_t));
	else if (conversion == 'n')
		transform_n_size(data, va_arg(data->ap, size_t *));
	else
		data->error = 1;
}
