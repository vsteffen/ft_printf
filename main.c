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
	(void)ac;
	(void)av;
	(void)env;

	setlocale(LC_CTYPE,"UTF-8");
	printf("TESTING -> [%s] ARG = 0\n", "%#.3o");
	printf("--------------------------\n");
	int retour;
	// double varToSend = 42.8999999999999999999999999;
	// char	*varToSend2 = "12345";
	// int 	varToSend1 = 420;
	// wint_t				varToSend3 = L'猫';
	// char varToSend3 = '\0';
	// char *varToSend2 = "SALUT";
	// wchar_t				*varToSend1 = L"我是一只猫";
	// wchar_t				*varToSend1 = L"𝄞𝄞𝄞";
	// wchar_t				*varToSend1 = L"~~~";
	// wchar_t				*varToSend1 = L"ééé";
	// wchar_t				*varToSend1 = L"";
	// 我是一只猫
	// int   varToSend2 = 7;

	write(1, "[", 1);
	// printf("LENNNNNN = %lu \n", ft_strlen("\033[0m"));
	// printf(BG_RED);
	// int fp;
	// fp = open ("test.txt", O_RDWR|O_CREAT, 0666);
	retour = ft_printf("POULET %{FD}TEST AWESOME%{FD}POUET%{FD} ALLOW", 2, 1, 2);
	// close (fp);
	write(1, "]\n", 2);
	printf("Length ft_printf read : %d\n", retour);
	// printf("Value of varToSend1 = %d\n", varToSend1);
	printf("----------- VS -----------\n[");
	retour = printf("%llu", -1);
	printf("]\n");
	printf("Length printf read : %d\n", retour);
	// printf("Value of varToSend1 = %d\n", varToSend1);
	// int number = 6;
	// char *string = "01234567";
    //
	// printf("\nTypes\n");
	// printf( "%%.3f %%.3g %%.3f %%.3g --> |%.3f| |%.3g| |%.3f| |%.3g|\n", 100.2, 100.2, 3.1415926, 3.1415926 );
    //
	// printf("\nSome example of Flags\n");
	// printf("|%-10d| --> |%%-10d|\n", number);
	// printf("|%10d| --> |%%10d|\n", number);
	// printf("|%010d| --> |%%010d|\n", number);
	// // printf("|%-010d| --> \n", number); flag '0' is ignored when flag '-' is present
	// printf("|%-#10x| --> |%%-#10x|\n", number);
	// printf("|%#10x| --> |%%#10x|\n", number);
	// printf("|%#x| --> |%%#x|\n", number);
	// printf("| %       d| --> | %%       d|\n", number);
    //
	// printf("\nPrint %% char\n");
    //
	// printf("\nMinimum width field\n");
	// printf("Here is a number|%4d|and a|%10s|word + |%04d| weird and this |%-5d| also .\n", number, string, number, number);
	// printf("|%-15.10s| --> |%%-15.10s|\n", string);
	return (0);
}
