/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:52:23 by vsteffen          #+#    #+#             */
/*   Updated: 2016/11/17 17:37:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_and_move_format(t_data *data)
{
		(void)data;

		return (0);
}

void		init_data_and_var(t_data *data, const char * restrict format) {
	bzero(data, sizeof(t_data));
	data->format = format;
	data->formatPos = -1;
}

int			ft_printf(const char * restrict format, ...) {
	t_data		data;

	init_data_and_var(&data, format);
	va_start(data.ap, format);
	while (format[++data.formatPos] != '\0') {
		printf("Char = %c | %s\n", format[data.formatPos], format + data.formatPos);
		if (format[data.formatPos] == '%')
		{
			data.formatPos += parse_and_move_format(&data);
			continue ;
		}
	}
	va_end(data.ap);
	return (0);
}

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
	printf( "%%.3f %%.3g %%.3f %%.3g --> %.3f %.3g %.3f %.3g\n", 100.2, 100.2, 3.1415926, 3.1415926 );

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
	printf("Here is a number|%4d|and a|%10s|word + |%04d| weird.\n", number, string, number);

	return (1);
}
