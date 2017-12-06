/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:35 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/18 19:31:18 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_H
# define ft_printf_H

# include "libft.h"

typedef struct		s_elem {
	struct s_elem	*prec;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_data {
	t_elem			*elem;
	t_elem			*current;
	t_elem			*last;
}					t_data;

#endif
