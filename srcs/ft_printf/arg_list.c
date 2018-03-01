/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:42:21 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/01 16:55:49 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_output_simple(t_arg *arg, t_data *data)
{
	write(arg->tmpFd, data->formatMod + arg->beforeArg, \
		ft_strlen(data->formatMod + arg->beforeArg));
	if (arg->outputWideLength > 0)
	{
		write(arg->fd, arg->outputArg, arg->outputWideLength);
		free(arg->outputArgWide);
	}
	else
		write(arg->fd, arg->outputArg, arg->outputLength);
}

void	print_output_width(t_arg *arg, t_data *data)
{
	write(arg->tmpFd, data->formatMod + arg->beforeArg, \
		ft_strlen(data->formatMod + arg->beforeArg));
	write(arg->fd, arg->outputWidth, ft_strlen(arg->outputWidth));
	if (arg->outputWideLength > 0)
	{
		write(arg->fd, arg->outputArg, arg->outputWideLength);
		free(arg->outputArgWide);
	}
	else
		write(arg->fd, arg->outputArg, arg->outputLength);
	free(arg->outputWidth);
}

void	print_output_width_reverse(t_arg *arg, t_data *data)
{
	write(arg->tmpFd, data->formatMod + arg->beforeArg, \
		ft_strlen(data->formatMod + arg->beforeArg));
	if (arg->outputWideLength > 0)
	{
		write(arg->fd, arg->outputArg, arg->outputWideLength);
		free(arg->outputArgWide);
	}
	else
		write(arg->fd, arg->outputArg, arg->outputLength);
	write(arg->fd, arg->outputWidth, ft_strlen(arg->outputWidth));
	free(arg->outputWidth);
}

void	print_arg_and_free(t_data *data)
{
	t_arg		*arg_ptr_next;
	t_arg		*arg_ptr_current;

	arg_ptr_current = data->first;
	while (arg_ptr_current)
	{
		arg_ptr_next = arg_ptr_current->next;
		if (arg_ptr_current->outputWidth != NULL)
		{
			if (arg_ptr_current->flagLess == 0)
				print_output_width(arg_ptr_current, data);
			else
				print_output_width_reverse(arg_ptr_current, data);
		}
		else
			print_output_simple(arg_ptr_current, data);
		if (arg_ptr_current->outputArg != NULL)
			free(arg_ptr_current->outputArg);
		free(arg_ptr_current);
		arg_ptr_current = arg_ptr_next;
	}
	write(data->fd, data->format + data->tmpFormatPos, \
		ft_strlen(data->format + data->tmpFormatPos));
	if (data->colorSet == 1)
		write(1, "\033[0m", 4);
}
