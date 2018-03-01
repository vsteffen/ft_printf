/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:57:32 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/01 16:57:35 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct_arg_flag(t_arg *struct_ptr)
{
	struct_ptr->flagWidthNb = 0;
	struct_ptr->flagWidthWc = 0;
	struct_ptr->flagAsterisk = 0;
	struct_ptr->flagHash = 0;
	struct_ptr->flagZero = 0;
	struct_ptr->flagZeroWeird = 0;
	struct_ptr->flagLess = 0;
	struct_ptr->flagMore = 0;
	struct_ptr->flagSpace = 0;
	struct_ptr->flagDot = 0;
}

t_arg	*create_struct_arg(t_data *data)
{
	t_arg		*struct_ptr;

	struct_ptr = (t_arg*)malloc(sizeof(t_arg));
	struct_ptr->next = NULL;
	struct_ptr->beforeArg = data->tmpFormatPos;
	struct_ptr->outputArg = NULL;
	struct_ptr->fd = data->fd;
	struct_ptr->tmpFd = data->fd;
	struct_ptr->width = 0;
	struct_ptr->precision = 0;
	struct_ptr->type = 0;
	struct_ptr->outputArgWide = NULL;
	struct_ptr->outputWideLength = 0;
	struct_ptr->outputWidth = NULL;
	struct_ptr->outputLength = 0;
	struct_ptr->outputWidthLength = 0;
	init_struct_arg_flag(struct_ptr);
	return (struct_ptr);
}
