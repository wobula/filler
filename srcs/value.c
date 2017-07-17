/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:40:00 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 11:40:05 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	test(t_board *board, char value, int offset)
{
	if (board->raw[board->pos_x][board->pos_y + offset] &&
		board->raw[board->pos_x][board->pos_y + offset] == board->opp_symbol)
		board->raw[board->pos_x][board->pos_y] = value;
	if (board->raw[board->pos_x][board->pos_y - offset] &&
		board->raw[board->pos_x][board->pos_y - offset] == board->opp_symbol)
		board->raw[board->pos_x][board->pos_y] = value;
	if (board->raw[board->pos_x + offset] && board->raw[board->pos_x +
		offset][board->pos_y] && board->raw[board->pos_x +
		offset][board->pos_y] == board->opp_symbol)
		board->raw[board->pos_x][board->pos_y] = value;
	if (board->raw[board->pos_x - offset] && board->raw[board->pos_x -
		offset][board->pos_y] && board->raw[board->pos_x -
		offset][board->pos_y] == board->opp_symbol)
		board->raw[board->pos_x][board->pos_y] = value;
}

void	value(t_board *board, char value, int offset)
{
	int	x;

	x = board->h / 2;
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (board->raw[board->pos_x][board->pos_y] == '.')
				test(board, value, offset);
			if (ft_isdigit(board->raw[board->pos_x][board->pos_y] == '.'))
				test(board, value, offset);
		}
	}
}
