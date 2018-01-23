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

typedef struct		s_part {
	struct s_part	*next;
	struct s_part	*padding;
	struct s_part	*hashFlag;
	struct s_part	*zeroFlag;
	struct s_part	*lessFlag;
	struct s_part	*spaceFlag;
	struct s_part	*result;
}					t_part;

typedef struct		s_data {
	const char * restrict			format;
	va_list										ap;
	size_t										formatPos;
	t_part										*first;
	t_part										*current;
}					t_data;

#endif
