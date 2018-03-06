/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:04:08 by vsteffen          #+#    #+#             */
/*   Updated: 2018/02/20 19:39:50 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <locale.h>
#include <fcntl.h>

int			main(int ac, char **av, char **env)
{
	int		retour;

	(void)ac;
	(void)av;
	(void)env;
	setlocale(LC_CTYPE, "UTF-8");
	printf("TESTING -> [%s] ARG = 0\n", "%#.3o");
	printf("--------------------------\n");
	write(1, "[", 1);
	retour = ft_printf("POULET %{FD,BG_CYAN,FG_RED,UNDERLINE}TEST AWESOME%{FD} POUET%{FD} ALLOW -> %.4r", 2, 1, 2, 3);
	write(1, "]\n", 2);
	printf("Length ft_printf read : %d\n", retour);
	printf("----------- VS -----------\n[");
	retour = printf("%llu", -1);
	printf("]\n");
	printf("Length printf read : %d\n", retour);
	return (0);
}
