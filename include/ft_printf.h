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

typedef struct		s_arg { // Chained list for every arguments
	struct s_arg	*next;
	char					padding;
	char					hashFlag; // All Flags we need
	char					zeroFlag;
	char					lessFlag;
	char					spaceFlag;
	size_t				beforeArg; // text before the argument we want to print
	char					*outputArg;
}					t_arg;

typedef struct		s_data {
	const char * restrict			format;
	char											*formatMod; // use to improve read speed
	va_list										ap;
	size_t										formatPos;
	size_t										tmpFormatPos; // use for beforeArg
	char											*output;
	t_arg										*first;
	t_arg										*current;
}									t_data;

int			ft_printf(const char * restrict format, ...);

t_arg			*createStructArg(t_data *data);
void			freeArgList(t_data *data);


#endif
