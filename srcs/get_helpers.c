/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:52:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 11:53:32 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_start(char *str, char *start)
{
	int x;

	x = -1;
	while (str[++x] && start[x])
	{
		if (start[x] != str[x])
			return (0);
	}
	if (start[x])
		return (0);
	return (1);
}

int		get_size(char *line)
{
	int x;

	x = -1;
	while (line[++x])
	{
		if (isdigit(line[x]))
			return (line[x]);
	}
	return (0);
}

void	get_player(t_board *board, char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp != 'p')
		++tmp;
	++tmp;
	board->player = *tmp - '0';
	if (board->player == 1)
	{
		board->player_symbol = 'O';
		board->opp_symbol = 'X';
	}
	else
	{
		board->player_symbol = 'X';
		board->opp_symbol = 'O';
	}
}

int		get_x(char *line)
{
	int x;

	x = 0;
	while (line[x] != ' ')
		x++;
	x++;
	return (ft_atoi(line + x));
}

int		get_y(char *line)
{
	int x;
	int spaces;

	x = -1;
	spaces = 0;
	while (line[++x] != '\0')
	{
		if (spaces == 2)
			break ;
		if (line[x] == ' ')
			spaces++;
	}
	return (ft_atoi(line + x));
}
