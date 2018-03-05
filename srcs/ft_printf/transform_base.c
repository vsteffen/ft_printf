/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:19:05 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/05 23:21:28 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint8_t		count_numeral_base(uintmax_t nb, uint8_t base)
{
	uint8_t		count;

	count = 1;
	while (nb /= base)
		++count;
	return (count);
}

char				*ft_itoa_base_printf(uintmax_t nb, uint8_t base, \
	char *alph, size_t prec)
{
	char		*output;
	size_t		length;

	if (nb == 0)
		return (ft_strdup("0"));
	length = (size_t)count_numeral_base(nb, base);
	if (length < prec)
		length = prec;
	output = (char *)mallocp(sizeof(char) * length + 1);
	output[length] = '\0';
	while (nb != 0)
	{
		length--;
		output[length] = alph[nb % base];
		nb /= base;
	}
	if (length > 0)
	{
		while (--length > 0)
			output[length] = '0';
		output[0] = '0';
	}
	return (output);
}

void				transform_o_flag_hash(t_arg *arg, uintmax_t var_uintmax)
{
	if (var_uintmax == 0)
	{
		if (arg->flag_dot == 1 && arg->precision > 0)
			arg->output_arg = malloc_prec_zero_doux(arg->precision, arg, \
				'o');
		else
			arg->output_arg = ft_strdup("0");
	}
	else if (arg->flag_dot == 1)
	{
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 8, \
			"0123456789abcdef", arg->precision);
		if (arg->precision == 0)
			arg->output_arg = ft_strjoinaf2("0", arg->output_arg);
	}
	else
	{
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 8, \
			"0123456789abcdef", arg->precision);
		arg->output_arg = ft_strjoinaf2("0", arg->output_arg);
	}
}

void				transform_o(t_arg *arg, uintmax_t var_uintmax)
{
	if (arg->flag_hash == 1)
	{
		transform_o_flag_hash(arg, var_uintmax);
		return ;
	}
	else if (var_uintmax == 0)
	{
		if (arg->precision == 0 && arg->flag_dot == 1)
			arg->output_arg = ft_strdup("");
		else
			arg->output_arg = malloc_prec_zero_doux(arg->precision, arg, 'o');
		return ;
	}
	else
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 8, \
			"0123456789abcdef", arg->precision);
}

void				transform_u(t_arg *arg, uintmax_t var_uintmax)
{
	if (var_uintmax == 0)
	{
		if (arg->precision == 0 && arg->flag_dot == 1)
			arg->output_arg = ft_strdup("");
		else
			arg->output_arg = malloc_prec_zero_doux(arg->precision, arg, 'u');
	}
	else
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 10, \
			"0123456789abcdef", arg->precision);
}

void				transform_x(t_arg *arg, uintmax_t var_uintmax)
{
	if (var_uintmax == 0)
	{
		if (arg->precision == 0 && arg->flag_dot == 1)
			arg->output_arg = ft_strdup("");
		else
			arg->output_arg = malloc_prec_zero_doux(arg->precision, arg, 'x');
	}
	else
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 16, \
			"0123456789abcdef", arg->precision);
	if (arg->flag_hash && var_uintmax > 0)
	{
		arg->output_arg = ft_strjoinaf2("0x", arg->output_arg);
	}
}

void				transform_bx(t_arg *arg, uintmax_t var_uintmax)
{
	if (var_uintmax == 0)
	{
		if (arg->precision == 0 && arg->flag_dot == 1)
			arg->output_arg = ft_strdup("");
		else
			arg->output_arg = malloc_prec_zero_doux(arg->precision, arg, 'X');
	}
	else
		arg->output_arg = ft_itoa_base_printf(var_uintmax, 16, \
			"0123456789ABCDEF", arg->precision);
	if (arg->flag_hash && var_uintmax > 0)
	{
		arg->output_arg = ft_strjoinaf2("0X", arg->output_arg);
	}
}
