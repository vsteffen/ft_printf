/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <vsteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:42:40 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/05 18:36:49 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

typedef struct				s_arg {
	struct s_arg			*next;
	size_t					width;
	size_t					precision;
	int8_t					flag_width_nb;
	int8_t					flag_width_wc;
	int8_t					flag_asterisk;
	int8_t					flag_hash;
	int8_t					flag_zero;
	int8_t					flag_zero_weird;
	int8_t					flag_less;
	int8_t					flag_more;
	int8_t					flag_space;
	int8_t					flag_dot;
	size_t					before_arg;
	int8_t					type;
	uintmax_t				fd;
	uintmax_t				tmp_fd;
	char					*output_arg;
	char					*output_arg_wide;
	size_t					output_wide_length;
	char					*output_width;
	size_t					output_length;
}							t_arg;

typedef struct				s_data {
	const char * restrict	format;
	char					*format_mod;
	va_list					ap;
	size_t					format_pos;
	size_t					tmp_format_pos;
	size_t					move_in_arg;
	int8_t					error;
	size_t					len_so_far;
	int8_t					color_set;
	uintmax_t				fd;
	t_arg					*first;
	t_arg					*current;
}							t_data;

typedef struct				s_struct_fl_do {
	int64_t					before_dot;
	int64_t					after_dot;
	int8_t					length_before_dot;
	int8_t					dot;
	int8_t					sign;
	char					sign_char;
}							t_struct_fl_do;

int							ft_printf(const char *restrict format, ...);

int							parse_and_move_format(t_data *data);

t_arg						*create_struct_arg(t_data *data);
void						print_arg_and_free(t_data *data);

void						detect_length_mod_hh1(t_data *data, \
								char conversion);
void						detect_length_mod_h1(t_data *data, char conversion);
void						detect_length_mod_l1(t_data *data, char conversion);
void						detect_length_mod_ll1(t_data *data, \
								char conversion);
void						detect_length_mod_j1(t_data *data, char conversion);
void						detect_length_mod_z1(t_data *data, char conversion);

void						transform_c(t_data *data, char varInt);
void						transform_s(t_data *data, char *varString);
void						transform_wide_c(t_data *data, wchar_t wide);
void						transform_wide_s(t_data *data, wchar_t *wide);
void						transform_d(t_arg *arg, intmax_t var_int_max);
void						transform_o(t_data *data, uintmax_t varUIntMax);
void						transform_u(t_data *data, uintmax_t varUIntMax);
void						transform_x(t_data *data, uintmax_t varUIntMax);
void						transform_X(t_data *data, uintmax_t varUIntMax);
void						transform_n(t_data *data, intmax_t *var_int_max);
void						transform_f(t_arg *arg, double var_float);
void						transform_p(t_data *data, void *ptr);
void						transform_r(t_data *data, int64_t byte);

char						*ft_itoa_base_printf(uintmax_t nb, uint8_t base, \
								char *alph, size_t prec);

char						*malloc_prec_zero_doux(size_t prec, t_arg *arg, \
								char conversion);

int64_t						ft_pow_printf(int64_t nb, uint8_t power);
int64_t						ft_round_printf(double nb);

int8_t						verif_flag_already_used(t_data *data, char flag);
void						flag_dot(t_data *data);
void						flag_color_fd(t_data *data, const char *arguments);
void						flag_color_bg1(t_data *data, const char *arguments);
void						flag_color_fg1(t_data *data, const char *arguments);
void						flag_color_no(t_data *data, const char *arguments);
int8_t						flag_color_other(t_data *data, \
								const char *arguments);
void						flag_color_move_in_arg(t_data *data, \
								const char *color, size_t move);

void						flag_width_nb(t_data *data);

#endif
