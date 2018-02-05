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

void			printArgAndFree(t_data *data) {
		t_arg		*argPtrNext;
		t_arg		*argPtrCurrent;
		size_t		argNumber = 1;

		argPtrCurrent = data->first;
		while (argPtrCurrent)
		{
			argPtrNext = argPtrCurrent->next;
			// Free all variables inside
			printf("Arg n°%lu -> [%s] at %lu + [%s] ||| precision = %hhu\n",  argNumber, data->formatMod + argPtrCurrent->beforeArg, argPtrCurrent->beforeArg, argPtrCurrent->outputArg, argPtrCurrent->precision);
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

		// printf("STRUCT ARG CREATED\n");
		structPtr = (t_arg*)malloc(sizeof(t_arg));
		bzero(structPtr, sizeof(t_arg)); // to remove
		structPtr->next = NULL;
		structPtr->padding = 0;
		structPtr->beforeArg = data->tmpFormatPos;
		structPtr->outputArg = NULL;
		return (structPtr);
}
