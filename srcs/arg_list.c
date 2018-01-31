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

void			freeArgList(t_data *data) {
		t_arg		*argPtrNext;
		t_arg		*argPtrCurrent;

		argPtrCurrent = data->first;
		while (argPtrCurrent)
		{
			argPtrNext = data->first->next;
			// Free all variables inside
			free(argPtrCurrent);
			argPtrCurrent = argPtrNext;
		}
		printf("All arg list free\n");
}

t_arg	*createStructArg(t_data *data) {
		t_arg		*structPtr;

		structPtr = (t_arg*)malloc(sizeof(t_arg));
		structPtr->next = NULL;
		structPtr->padding = 0;
		structPtr->hashFlag = 0;
		structPtr->zeroFlag = 0;
		structPtr->lessFlag = 0;
		structPtr->spaceFlag = 0;
		structPtr->beforeArg = data->tmpFormatPos;
		structPtr->outputArg = NULL;
		printf("Arg list created\n");
		return (structPtr);
}
