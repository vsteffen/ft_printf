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

typedef __int128			int128_t;

typedef struct				s_arg { // Chained list for every arguments
	struct s_arg			*next;
	size_t					width;
	size_t					precision;
	int8_t					flagWidthNb;
	int8_t					flagWidthWc;
	int8_t					flagHash;
	int8_t					flagZero;
	int8_t					flagLess;
	int8_t					flagMore;
	int8_t					flagSpace;
	int8_t					flagDot;
	size_t					beforeArg; // text pos before the argument we want to print
	int8_t					type;
	char					*outputArg;
	char					*outputWidth;
	size_t					outputLength;
	size_t					outputWidthLength;
}							t_arg;

typedef struct				s_data {
	const char * restrict	format;
	char					*formatMod; // use to improve read speed
	va_list					ap;
	size_t					formatPos;
	size_t					tmpFormatPos; // use for beforeArg
	size_t					moveInArg; // length of character read in
	int8_t					error;
	char					*output;
	t_arg					*first;
	t_arg					*current;
}							t_data;

typedef struct				s_structFlDo {
	int64_t					beforeDot;
	int64_t					afterDot;
	int8_t					lengthBeforeDot;
	int8_t					lengthAfterDot;
	int8_t					dot;
	int8_t					sign;
	char					signChar;
}							t_structFlDo;

int					ft_printf(const char * restrict format, ...);

int					parse_and_move_format(t_data *data);

t_arg				*createStructArg(t_data *data);
void				printArgAndFree(t_data *data);

void				detect_length_mod_hh(t_data *data, char conversion);
void				detect_length_mod_h(t_data *data, char conversion);
void				detect_length_mod_l(t_data *data, char conversion);
void				detect_length_mod_ll(t_data *data, char conversion);
void				detect_length_mod_j(t_data *data, char conversion);
void				detect_length_mod_z(t_data *data, char conversion);

void				transform_c(t_data *data, char varInt);
void				transform_d(t_data *data, intmax_t varIntMax);
void				transform_s(t_data *data, char *varString);
void				transform_o(t_data *data, uintmax_t varUIntMax);
void				transform_u(t_data *data, uintmax_t varUIntMax);
void				transform_x(t_data *data, uintmax_t varUIntMax);
void				transform_X(t_data *data, uintmax_t varUIntMax);
void				transform_n_char(t_data *data, signed char *varTyped);
void				transform_n_short(t_data *data, short *varTyped);
void				transform_n_l(t_data *data, long *varTyped);
void				transform_n_ll(t_data *data, long long *varTyped);
void				transform_n_intmax(t_data *data, intmax_t *varTyped);
void				transform_n_size(t_data *data, size_t *varTyped);
void				transform_f(t_data *data, double varFloat);



int8_t   			verifFlagAlreadyUsed(t_data *data, char flag);
void      			flagDot(t_data *data);
void      			flagWidthNb(t_data *data);

#endif
