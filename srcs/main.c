/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:04:08 by vsteffen          #+#    #+#             */
/*   Updated: 2018/01/29 20:04:11 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	printf("%lu\n", sizeof(uint64_t));
	printf("Float -> [%.f] /// double -> [%0.8g] /// int -> [%d]\n", 4.1234567890123456789012345678901234567890, (double)4.22, (int)4.722222);

	printf("-------------------\n");
	double varToSend = -42.6;
	if (ac > 1)
		printf("Trying to send this string %d -> [%s]\n\n", ac, av[1]);
	if (ac == 1)
		ft_printf("ANTI-CONSTITUTIONNELLEMENT");
	else if (ac >  1)
		ft_printf(av[1], varToSend);
	printf("--------- VS ---------\n");
	printf(av[1], varToSend);
	printf("\n");
/*
	int number = 6;
	char *string = "01234567";

	printf("\nTypes\n");
	printf( "%%.3f %%.3g %%.3f %%.3g --> |%.3f| |%.3g| |%.3f| |%.3g|\n", 100.2, 100.2, 3.1415926, 3.1415926 );

	printf("\nSome example of Flags\n");
	printf("|%-10d| --> |%%-10d|\n", number);
	printf("|%10d| --> |%%10d|\n", number);
	printf("|%010d| --> |%%010d|\n", number);
	// printf("|%-010d| --> \n", number); flag '0' is ignored when flag '-' is present
	printf("|%-#10x| --> |%%-#10x|\n", number);
	printf("|%#10x| --> |%%#10x|\n", number);
	printf("|%#x| --> |%%#x|\n", number);
	printf("| %       d| --> | %%       d|\n", number);

	printf("\nPrint %% char\n");

	printf("\nMinimum width field\n");
	printf("Here is a number|%4d|and a|%10s|word + |%04d| weird and this |%-5d| also .\n", number, string, number, number);
	printf("|%-15.10s| --> |%%-15.10s|\n", string);
*/
	return (1);
}
