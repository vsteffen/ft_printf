/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:51:32 by vsteffen          #+#    #+#             */
/*   Updated: 2018/01/29 19:59:08 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_output_simple(t_arg *arg, t_data *data, size_t argNumber)
{
	// printf("PRINT WITHOUT WIDTH\n");
	// printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %zu and width = %lu\n",  argNumber, data->formatMod + arg->beforeArg, arg->beforeArg, arg->outputArg, arg->precision, arg->width);

	(void)argNumber;
	ft_putstr(data->formatMod + arg->beforeArg);
	ft_putstr(arg->outputArg);
}

void print_output_width(t_arg *arg, t_data *data, size_t argNumber)
{
	// printf("Arg n°%lu -> before [%s] + arg [%s] + width [", argNumber, data->formatMod + arg->beforeArg, arg->outputArg);
	// printf("%s", arg->outputWidth);
	// printf("] ||| precision = %zu and width = %lu\n", arg->precision, arg->width);

	(void)argNumber;
	ft_putstr(data->formatMod + arg->beforeArg);
	ft_putstr(arg->outputArg);
	ft_putstr(arg->outputWidth);
}

void print_output_width_reverse(t_arg *arg, t_data *data, size_t argNumber)
{
	// printf("Arg n°%lu -> before [%s] + width [", argNumber, data->formatMod + arg->beforeArg);
	// printf("%s", arg->outputWidth);
	// printf("] + arg [%s] ||| precision = %zu and width = %lu\n", arg->outputArg, arg->precision, arg->width);

	(void)argNumber;
	ft_putstr(data->formatMod + arg->beforeArg);
	ft_putstr(arg->outputWidth);
	ft_putstr(arg->outputArg);
}

void			printArgAndFree(t_data *data) {
	t_arg		*argPtrNext;
	t_arg		*argPtrCurrent;
	size_t		argNumber = 1;

	argPtrCurrent = data->first;
	ft_putstr("[");
	while (argPtrCurrent)
	{
		argPtrNext = argPtrCurrent->next;
		// Free all variables inside
		if (argPtrCurrent->outputWidth != NULL)
		{
			if (argPtrCurrent->flagLess)
				print_output_width(argPtrCurrent, data, argNumber);
			else
				print_output_width_reverse(argPtrCurrent, data, argNumber);
		}
		else
			print_output_simple(argPtrCurrent, data, argNumber);
		// if ((argPtrCurrent->outputLength < argPtrCurrent->width) && (argPtrCurrent->flagWidthWc == 1 || argPtrCurrent->flagWidthNb == 1))
		// {
		// 	printf("PRINT WITH WIDTH\n");
		// 	argPtrCurrent->width = argPtrCurrent->width - argPtrCurrent->outputLength;
		// 	get_output_malloc_width(argPtrCurrent);
		// 	if (argPtrCurrent->flagLess)
		// 		print_output_width(argPtrCurrent, data, argNumber);
		// 	else
		// 		print_output_width_reverse(argPtrCurrent, data, argNumber);
		// }
		// else
		// 	print_output_simple(argPtrCurrent, data, argNumber);
		// printf("%s%s", data->formatMod + argPtrCurrent->beforeArg, argPtrCurrent->outputArg);
		free(argPtrCurrent->outputArg);
		free(argPtrCurrent);
		argPtrCurrent = argPtrNext;
		argNumber++;
	}
	ft_putstr(data->format + data->tmpFormatPos);
	ft_putstr("]\n");
	// printf("Rest of the string -> [%s]\n", data->format + data->tmpFormatPos);
}

t_arg	*createStructArg(t_data *data) {
	t_arg		*structPtr;

	structPtr = (t_arg*)malloc(sizeof(t_arg));
	bzero(structPtr, sizeof(t_arg)); // to remove
	structPtr->next = NULL;
	structPtr->beforeArg = data->tmpFormatPos;
	structPtr->outputArg = NULL;
	return (structPtr);
}
