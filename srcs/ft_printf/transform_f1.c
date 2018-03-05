/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_f1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:26:40 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/05 22:26:41 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint8_t	length_numeral(int64_t nb)
{
	uint8_t		count;

	count = 1;
	while (nb /= 10)
		++count;
	return (count);
}

void			fill_array_for_dtoa(char *output, uint8_t precision, \
	t_struct_fl_do *s_fl_do)
{
	uint8_t		pos_after_dot;
	uint8_t		tmp_length_before_dot;

	tmp_length_before_dot = s_fl_do->length_before_dot;
	output[tmp_length_before_dot] = '\0';
	output[--tmp_length_before_dot] = s_fl_do->before_dot % 10 + '0';
	while (s_fl_do->before_dot /= 10)
		output[--tmp_length_before_dot] = s_fl_do->before_dot % 10 + '0';
	if (s_fl_do->sign == 1)
		output[0] = s_fl_do->sign_char;
	if (precision < 1)
		return ;
	output[s_fl_do->length_before_dot] = '.';
	pos_after_dot = s_fl_do->length_before_dot + s_fl_do->dot + precision;
	output[pos_after_dot] = '\0';
	if (s_fl_do->after_dot == 0)
	{
		while (precision-- > 0)
			output[--pos_after_dot] = '0';
		return ;
	}
	output[--pos_after_dot] = s_fl_do->after_dot % 10 + '0';
	while (s_fl_do->after_dot /= 10)
		output[--pos_after_dot] = s_fl_do->after_dot % 10 + '0';
}

void			ft_dtoa_printflag(t_struct_fl_do *s_fl_do, t_arg *arg, \
	double tmp_double, uint8_t precision)
{
	if (s_fl_do->before_dot < 0)
	{
		s_fl_do->sign = 1;
		s_fl_do->sign_char = '-';
		if (arg->flag_zero == 1)
			arg->flag_zero = 2;
		s_fl_do->before_dot = -s_fl_do->before_dot;
		tmp_double = -tmp_double;
		s_fl_do->after_dot = ft_round_printf(\
			tmp_double * (ft_pow_printf(10, precision)));
	}
	else
	{
		if (arg->flag_more)
		{
			s_fl_do->sign = 1;
			s_fl_do->sign_char = '+';
			if (arg->flag_zero == 1)
				arg->flag_zero = 2;
		}
		s_fl_do->after_dot = ft_round_printf(\
			tmp_double * (ft_pow_printf(10, precision)));
	}
}

char			*ft_dtoa_printf(t_arg *arg, double nb, uint8_t precision)
{
	t_struct_fl_do	s_fl_do;
	char			*output;
	double			tmp_double;

	s_fl_do.before_dot = (int64_t)nb;
	s_fl_do.dot = 0;
	s_fl_do.sign = 0;
	if (precision == 0)
		s_fl_do.before_dot = ft_round_printf(nb);
	else
		s_fl_do.dot = 1;
	if (precision > 18)
		precision = 18;
	s_fl_do.length_before_dot = length_numeral((int64_t)s_fl_do.before_dot);
	tmp_double = nb - (double)s_fl_do.before_dot;
	ft_dtoa_printflag(&s_fl_do, arg, tmp_double, precision);
	if (s_fl_do.sign)
		++s_fl_do.length_before_dot;
	output = (char *)malloc(sizeof(char) * \
		(s_fl_do.length_before_dot + s_fl_do.dot + precision) + 1);
	fill_array_for_dtoa(output, precision, &s_fl_do);
	return (output);
}

void			transform_f(t_arg *arg, double var_float)
{
	arg->output_arg = ft_dtoa_printf(arg, var_float, arg->precision);
	if (arg->flag_space == 1 && arg->output_arg[0] != '+' \
		&& arg->output_arg[0] != '-')
		arg->output_arg = ft_strjoinaf2(" ", arg->output_arg);
}
