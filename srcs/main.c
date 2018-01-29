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

int			main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	ft_printf("ANTI-CONSITUTIONNELLEMENT");
	printf("-------------------\n");

	int number = 6;
	char *string = "01234567";

	printf("\nTypes\n");
	printf( "%%.3f %%.3g %%.3f %%.3g --> |%.3f| |%.3g| |%.3f| |%.3g|\n", 100.2, 100.2, 3.1415926, 3.1415926 );

	printf("\nSome example of Flags\n");
	printf("|%-10d| --> |%%-10d|\n", number);
	printf("|%10d| --> |%%10d|\n", number);
	printf("|%010d| --> |%%010d|\n", number);
	// printf("|%-010d| --> \n", number); flag '0' is ignored when flag '-' is present
	printf("|%-#10x| --> ç%%-#10x|\n", number);
	printf("|%#10x| --> |%%#10x|\n", number);
	printf("|%#x| --> |%%#x|\n", number);
	printf("| %       d| --> | %%       d|\n", number);

	printf("\nPrint %% char\n");

	printf("\nMinimum width field\n");
	printf("Here is a number|%4d|and a|%10s|word + |%04d| weird and this |%-5d| also .\n", number, string, number, number);

	return (1);
}
