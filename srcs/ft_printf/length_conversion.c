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
		transform_d(data, (signed char)va_arg(data->ap, int));
	else if (conversion == 'o')
		transform_o(data, (unsigned char)va_arg(data->ap, int));
	else if (conversion == 'u')
		transform_u(data, (unsigned char)va_arg(data->ap, int));
	else if (conversion == 'x')
		transform_x(data, (unsigned char)va_arg(data->ap, int));
	else if (conversion == 'X')
		transform_X(data, (unsigned char)va_arg(data->ap, int));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, long int));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, signed char *));
	else
		data->error = 1;
}

void	detect_length_mod_h(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (short)va_arg(data->ap, int));
	else if (conversion == 'o')
		transform_o(data, (unsigned short)va_arg(data->ap, int));
	else if (conversion == 'u')
		transform_u(data, (unsigned short)va_arg(data->ap, int));
	else if (conversion == 'x')
		transform_x(data, (unsigned short)va_arg(data->ap, int));
	else if (conversion == 'X')
		transform_X(data, (unsigned short)va_arg(data->ap, int));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, long int));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, short *));
	else
		data->error = 1;
	// transform_u(data, (long int)va_arg(data->ap, long int));
}

void	detect_length_mod_l(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (long)va_arg(data->ap, long));
	else if (conversion == 'o')
		transform_o(data, (unsigned long)va_arg(data->ap, unsigned long));
	else if (conversion == 'u')
		transform_u(data, (unsigned long)va_arg(data->ap, unsigned long));
	else if (conversion == 'x')
		transform_x(data, (unsigned long)va_arg(data->ap, unsigned long));
	else if (conversion == 'X')
		transform_X(data, (unsigned long)va_arg(data->ap, unsigned long));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, long int));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, unsigned long int));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, long *));
	else if (conversion == 'c')
		transform_wide_c(data, va_arg(data->ap, wint_t));
	else if (conversion == 's')
		transform_wide_s(data, va_arg(data->ap, wchar_t *));
	else
		data->error = 1;
}

void	detect_length_mod_ll(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (long long)va_arg(data->ap, long long));
	else if (conversion == 'o')
		transform_o(data, (unsigned long long)va_arg(data->ap, unsigned long long));
	else if (conversion == 'u')
		transform_u(data, (unsigned long long)va_arg(data->ap, unsigned long long));
	else if (conversion == 'x')
		transform_x(data, (unsigned long long)va_arg(data->ap, unsigned long long));
	else if (conversion == 'X')
		transform_X(data, (unsigned long long)va_arg(data->ap, unsigned long long));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, long long int));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, unsigned long long int));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, unsigned long long int));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, long long *));
	else
		data->error = 1;
}

void	detect_length_mod_j(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, intmax_t));
	else if (conversion == 'o')
		transform_o(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'u')
		transform_u(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'x')
		transform_x(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'X')
		transform_X(data, (uintmax_t)va_arg(data->ap, uintmax_t));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, intmax_t));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, uintmax_t));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, uintmax_t));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, intmax_t *));
	else
		data->error = 1;
}

void	detect_length_mod_z(t_data *data, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
		transform_d(data, (intmax_t)va_arg(data->ap, intmax_t));
	else if (conversion == 'o')
		transform_o(data, (size_t)va_arg(data->ap, size_t));
	else if (conversion == 'u')
		transform_u(data, (size_t)va_arg(data->ap, size_t));
	else if (conversion == 'x')
		transform_x(data, (size_t)va_arg(data->ap, size_t));
	else if (conversion == 'X')
		transform_X(data, (size_t)va_arg(data->ap, size_t));
	else if (conversion == 'D')
		transform_d(data, (long int)va_arg(data->ap, intmax_t));
	else if (conversion == 'O')
		transform_o(data, (unsigned long int)va_arg(data->ap, size_t));
	else if (conversion == 'U')
		transform_u(data, (unsigned long int)va_arg(data->ap, size_t));
	else if (conversion == 'n')
		transform_n(data, (intmax_t *)va_arg(data->ap, intmax_t *));
	else
		data->error = 1;
}
