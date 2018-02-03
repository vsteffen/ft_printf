/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <vsteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:42:40 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/22 16:15:05 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct		s_arg { // Chained list for every arguments
	struct s_arg	*next;
	char					padding;
	uint8_t				precision;
	char					hashFlag; // All Flags we need
	char					zeroFlag;
	char					lessFlag;
	char					spaceFlag;
	size_t				beforeArg; // text pos before the argument we want to print
	char					type;
	char					*outputArg;
}					t_arg;

typedef struct		s_data {
	const char * restrict			format;
	char											*formatMod; // use to improve read speed
	va_list										ap;
	size_t										formatPos;
	size_t										tmpFormatPos; // use for beforeArg
	size_t										moveInArg; // length of character read in
	size_t										error;
	char											*output;
	t_arg										*first;
	t_arg										*current;
}									t_data;

int				ft_printf(const char * restrict format, ...);

t_arg			*createStructArg(t_data *data);
void			printArgAndFree(t_data *data);

void			transformArgChar(t_data *data, int8_t varInt);
void			transformArgShort(t_data *data, int16_t varInt);
void			transformArgInt(t_data *data, int32_t varInt);
void			transformArgLong(t_data *data, int64_t varInt);
void			transformArgString(t_data *data, char *varInt);
void			transformArgFloat(t_data *data, double varInt);

void      flagDot(t_data *data);


#endif
