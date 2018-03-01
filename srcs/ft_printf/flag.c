/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:53:07 by vsteffen          #+#    #+#             */
/*   Updated: 2018/03/01 19:58:54 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagColorMoveInArg(t_data *data, const char *color, size_t move)
{
	if (data->current->outputArg == NULL)
		data->current->outputArg = ft_strdup(color);
	else
		data->current->outputArg = ft_strjoinaf1(\
			data->current->outputArg, color);
	data->moveInArg += move;
}

void	flagColorFG(t_data *data, const char *arguments)
{
	if (ft_strncmp("RED", arguments, 3) == 0)
		flagColorMoveInArg(data, FG_RED, 3);
	else if (ft_strncmp("BLUE", arguments, 4) == 0)
		flagColorMoveInArg(data, FG_BLUE, 4);
	else if (ft_strncmp("CYAN", arguments, 4) == 0)
		flagColorMoveInArg(data, FG_CYAN, 4);
	else if (ft_strncmp("LRED", arguments, 4) == 0)
		flagColorMoveInArg(data, FG_LRED, 4);
	else if (ft_strncmp("BLACK", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_BLACK, 5);
	else if (ft_strncmp("GREEN", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_GREEN, 5);
	else if (ft_strncmp("WHITE", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_WHITE, 5);
	else if (ft_strncmp("DGRAY", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_DGRAY, 5);
	else if (ft_strncmp("LBLUE", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_LBLUE, 5);
	else if (ft_strncmp("LCYAN", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_LCYAN, 5);
	else if (ft_strncmp("LGRAY", arguments, 5) == 0)
		flagColorMoveInArg(data, FG_LGRAY, 5);
	else if (ft_strncmp("YELLOW", arguments, 6) == 0)
		flagColorMoveInArg(data, FG_YELLOW, 6);
	else if (ft_strncmp("LGREEN", arguments, 6) == 0)
		flagColorMoveInArg(data, FG_LGREEN, 6);
	else if (ft_strncmp("DEFAULT", arguments, 7) == 0)
		flagColorMoveInArg(data, FG_DEFAULT, 7);
	else if (ft_strncmp("MAGENTA", arguments, 7) == 0)
		flagColorMoveInArg(data, FG_MAGENTA, 7);
	else if (ft_strncmp("LYELLOW", arguments, 7) == 0)
		flagColorMoveInArg(data, FG_LYELLOW, 7);
	else if (ft_strncmp("LMAGENTA", arguments, 8) == 0)
		flagColorMoveInArg(data, FG_LMAGENTA, 8);
	else
		data->error = 1;
}

void	flagColorBG(t_data *data, const char *arguments)
{
	if (ft_strncmp("RED", arguments, 3) == 0)
		flagColorMoveInArg(data, BG_RED, 3);
	else if (ft_strncmp("BLUE", arguments, 4) == 0)
		flagColorMoveInArg(data, BG_BLUE, 4);
	else if (ft_strncmp("CYAN", arguments, 4) == 0)
		flagColorMoveInArg(data, BG_CYAN, 4);
	else if (ft_strncmp("LRED", arguments, 4) == 0)
		flagColorMoveInArg(data, BG_LRED, 4);
	else if (ft_strncmp("BLACK", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_BLACK, 5);
	else if (ft_strncmp("GREEN", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_GREEN, 5);
	else if (ft_strncmp("WHITE", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_WHITE, 5);
	else if (ft_strncmp("DGRAY", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_DGRAY, 5);
	else if (ft_strncmp("LBLUE", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_LBLUE, 5);
	else if (ft_strncmp("LCYAN", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_LCYAN, 5);
	else if (ft_strncmp("LGRAY", arguments, 5) == 0)
		flagColorMoveInArg(data, BG_LGRAY, 5);
	else if (ft_strncmp("YELLOW", arguments, 6) == 0)
		flagColorMoveInArg(data, BG_YELLOW, 6);
	else if (ft_strncmp("LGREEN", arguments, 6) == 0)
		flagColorMoveInArg(data, BG_LGREEN, 6);
	else if (ft_strncmp("DEFAULT", arguments, 7) == 0)
		flagColorMoveInArg(data, BG_DEFAULT, 7);
	else if (ft_strncmp("MAGENTA", arguments, 7) == 0)
		flagColorMoveInArg(data, BG_MAGENTA, 7);
	else if (ft_strncmp("LYELLOW", arguments, 7) == 0)
		flagColorMoveInArg(data, BG_LYELLOW, 7);
	else if (ft_strncmp("LMAGENTA", arguments, 8) == 0)
		flagColorMoveInArg(data, BG_LMAGENTA, 8);
	else
		data->error = 1;
}

void	flagColorNO(t_data *data, const char *arguments)
{
	if (ft_strncmp("BLINK", arguments, 5) == 0)
		flagColorMoveInArg(data, NO_BLINK, 5);
	else if (ft_strncmp("REVERSE", arguments, 7) == 0)
		flagColorMoveInArg(data, NO_REVERSE, 7);
	else if (ft_strncmp("STANDOUT", arguments, 8) == 0)
		flagColorMoveInArg(data, NO_STANDOUT, 8);
	else if (ft_strncmp("UNDERLINED", arguments, 10) == 0)
		flagColorMoveInArg(data, NO_UNDERLINED, 10);
	else
		data->error = 1;
}

int8_t	flagColorOther(t_data *data, const char *arguments)
{
	if (ft_strncmp("BOLD", arguments, 4) == 0)
		flagColorMoveInArg(data, BOLD, 4);
	else if (ft_strncmp("FAINT", arguments, 5) == 0)
		flagColorMoveInArg(data, FAINT, 5);
	else if (ft_strncmp("BLINK", arguments, 5) == 0)
		flagColorMoveInArg(data, BLINK, 5);
	else if (ft_strncmp("HIDDEN", arguments, 6) == 0)
		flagColorMoveInArg(data, HIDDEN, 6);
	else if (ft_strncmp("REVERSE", arguments, 7) == 0)
		flagColorMoveInArg(data, REVERSE, 7);
	else if (ft_strncmp("CS_RESET", arguments, 8) == 0)
		flagColorMoveInArg(data, CS_RESET, 8);
	else if (ft_strncmp("UNDERLINE", arguments, 9) == 0)
		flagColorMoveInArg(data, UNDERLINE, 9);
	else
		return (1);
	return (0);
}

void	flagColorFd(t_data *data, const char *arguments)
{
	data->moveInArg++;
	if (ft_strncmp("FD", arguments, 2) == 0)
	{
		data->current->fd = (uintmax_t)va_arg(data->ap, uintmax_t);
		data->fd = data->current->fd;
		data->moveInArg += 2;
		return ;
	}
	else if (ft_strncmp("FG_", arguments, 3) == 0)
	{
		data->moveInArg += 3;
		flagColorFG(data, arguments + 3);
	}
	else if (ft_strncmp("BG_", arguments, 3) == 0)
	{
		data->moveInArg += 3;
		flagColorBG(data, arguments + 3);
	}
	else if (ft_strncmp("NO_", arguments, 3) == 0)
	{
		data->moveInArg += 3;
		flagColorNO(data, arguments + 3);
	}
	else if (flagColorOther(data, arguments) == 1)
	{
		data->error = 1;
		// data->lenSoFar -= ft_strlen(data->current->outputArg);
	}
	if (data->error != 0)
	{
		if (data->current->outputArg != NULL)
			data->current->outputArg[0] = '\0';
		data->moveInArg = 1;
		return ;
	}
	data->colorSet = 1;
}

int8_t	verifFlagAlreadyUsed(t_data *data, char flag)
{
	if (flag == '.')
	{
		if (data->current->flagDot == 1)
		{
			data->error = 2;
			return (0);
		}
		data->current->flagDot = 1;
		if (data->current->flagZero > 0)
		{
			data->current->flagZero = 0;
			data->current->flagZeroWeird = 1;
		}
		return (1);
	}
	return (0);
}

void	flagDot(t_data *data)
{
	size_t	precision;
	int		argWildcard;
	char	numeral;
	size_t	tmpMoveInArg;

	precision = 0;
	tmpMoveInArg = data->moveInArg;
	++data->moveInArg;
	if (data->format[data->formatPos + data->moveInArg] == '*')
	{
		argWildcard = va_arg(data->ap, int);
		if (argWildcard < 0)
		{
			data->current->flagZero = 1;
			data->current->flagAsterisk = 1;
		}
		else
			data->current->precision = (size_t)argWildcard;
		return ;
	}
	while (ft_isdigit((numeral = data->format\
		[data->formatPos + data->moveInArg])))
	{
		precision *= 10;
		precision += (int)numeral - 48;
		data->moveInArg++;
	}
	if (tmpMoveInArg != data->moveInArg)
		data->moveInArg--;
	data->current->precision = precision;
}

void	flagWidthNb(t_data *data)
{
	size_t	width;
	char	numeral;
	size_t	tmpMoveInArg;

	width = 0;
	tmpMoveInArg = data->moveInArg;
	while (ft_isdigit((numeral = data->format\
		[data->formatPos + data->moveInArg])))
	{
		width *= 10;
		width += (int)numeral - 48;
		data->moveInArg++;
	}
	if (tmpMoveInArg != data->moveInArg)
		data->moveInArg--;
	data->current->width = width;
}
