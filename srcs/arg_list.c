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

void			freeArgList(t_data *data) {
		t_arg		*argPtrNext;
		t_arg		*argPtrCurrent;

		argPtrCurrent = data->first;
		while (argPtrCurrent)
		{
			*argPtrNext = data->first->next;
			// Free all variables inside
			free(argPtrCurrent);
			argPtrCurrent = argPtrNext;
		}
}

t_arg	*createStructArg(t_data *data) {
		t_arg		*structPtr;

		structPtr = (t_arg*)malloc(sizeof(t_arg));
		structPtr->next = NULL;
		structPtr->padding = NULL;
		structPtr->hashFlag = NULL;
		structPtr->zeroFlag = NULL;
		structPtr->lessFlag = NULL;
		structPtr->spaceFlag = NULL;
		structPtr->beforeArg = data->tmpFormatPos;
		structPtr->outputArg = NULL;
		return (structPtr);
}
