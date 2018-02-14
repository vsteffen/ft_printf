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

void get_output_malloc_width(t_arg *arg, t_data *data) {
	size_t		pos;
	char		fillWidth;

	(void)data;
	arg->outputWidth = (char*)malloc(sizeof(char) * arg->width + 1);
	arg->outputWidth[arg->width] = '\0';
	pos = -1;
	fillWidth = ' ';
	if (arg->flagZero)
		fillWidth = '0';
	while (++pos < arg->width)
		arg->outputWidth[pos] = fillWidth;
}

void print_output_simple(t_arg *arg, t_data *data, size_t argNumber)
{
	printf("PRINT WITHOUT WIDTH\n");
	printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %zu and width = %lu\n",  argNumber, data->formatMod + arg->beforeArg, arg->beforeArg, arg->outputArg, arg->precision, arg->width);
}

void print_output_width(t_arg *arg, t_data *data, size_t argNumber)
{
	printf("Arg n°%lu -> before [%s] + arg [%s] + width [", argNumber, data->formatMod + arg->beforeArg, arg->outputArg);
	printf("%s", arg->outputWidth);
	printf("] ||| precision = %zu and width = %lu\n", arg->precision, arg->width);
}

void print_output_width_reverse(t_arg *arg, t_data *data, size_t argNumber)
{
	printf("Arg n°%lu -> before [%s] + width [", argNumber, data->formatMod + arg->beforeArg);
	printf("%s", arg->outputWidth);
	printf("] + arg [%s] ||| precision = %zu and width = %lu\n", arg->outputArg, arg->precision, arg->width);
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
		// printf("CONDITION: (%lu < %lu) && (%hhd == 1 || %hhd == 1)\n", argPtrCurrent->outputLength, argPtrCurrent->width, argPtrCurrent->flagWidthWc, argPtrCurrent->flagWidthNb);
		if ((argPtrCurrent->outputLength < argPtrCurrent->width) && (argPtrCurrent->flagWidthWc == 1 || argPtrCurrent->flagWidthNb == 1))
		{
			printf("PRINT WITH WIDTH\n");
			argPtrCurrent->width = argPtrCurrent->width - argPtrCurrent->outputLength;
			get_output_malloc_width(argPtrCurrent, data);
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
	printf("Rest of the string -> [%s]\n", data->format + data->tmpFormatPos);
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
