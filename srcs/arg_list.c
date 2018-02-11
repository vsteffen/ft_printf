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
	printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %hhu and width = %lu\n",  argNumber, data->formatMod + arg->beforeArg, arg->beforeArg, arg->outputArg, arg->precision, arg->width);
}

void print_output_width(t_arg *arg, t_data *data, size_t argNumber)
{
	printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %hhu and width = %lu\n",  argNumber, data->formatMod + arg->beforeArg, arg->beforeArg, arg->outputArg, arg->precision, arg->width);
}

void print_output_width_reverse(t_arg *arg, t_data *data, size_t argNumber)
{
	printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %hhu and width = %lu\n",  argNumber, data->formatMod + arg->beforeArg, arg->beforeArg, arg->outputArg, arg->precision, arg->width);
}

void			printArgAndFree(t_data *data) {
	t_arg		*argPtrNext;
	t_arg		*argPtrCurrent;
	size_t		argNumber = 1;

	argPtrCurrent = data->first;
	while (argPtrCurrent)
	{
		argPtrNext = argPtrCurrent->next;
		// Free all variables inside
		argPtrCurrent->outputLength = ft_strlen(argPtrCurrent->outputArg); // don't forget to think about length of '\0' in %c
		if (argPtrCurrent->flagWidthNb == 1 || argPtrCurrent->flagWidthNb == 1)
		{
			if (argPtrCurrent->flagLess)
				print_output_width(argPtrCurrent, data, argNumber);
			else
				print_output_width_reverse(argPtrCurrent, data, argNumber);
		}
		else
			print_output_simple(argPtrCurrent, data, argNumber);
		// printf("%s%s", data->formatMod + argPtrCurrent->beforeArg, argPtrCurrent->outputArg);
		free(argPtrCurrent->outputArg);
		free(argPtrCurrent);
		argPtrCurrent = argPtrNext;
		argNumber++;
	}
	printf("Rest of the strring -> [%s]\n", data->format + data->tmpFormatPos);
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
