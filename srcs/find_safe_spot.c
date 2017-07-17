/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_safe_spot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:09:58 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 12:10:00 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_data(t_board *board, t_piece *piece, int x, int y)
{
	if ((board->pos_x - piece->pos_x) + x >= board->l || (board->pos_y -
		piece->pos_y) + y >= board->h || (board->pos_x - piece->pos_x) + x < 0
		|| (board->pos_y - piece->pos_y) + y < 0)
		return (0);
	else if (board->raw[(board->pos_x - piece->pos_x) + x][(board->pos_y -
		piece->pos_y) + y] == board->player_symbol || board->raw[(board->pos_x
		- piece->pos_x) + x][(board->pos_y - piece->pos_y) + y] ==
		board->player_symbol + 32)
		board->touch++;
	else if (board->raw[(board->pos_x - piece->pos_x) + x][(board->pos_y -
		piece->pos_y) + y] == board->opp_symbol || board->raw[(board->pos_x -
		piece->pos_x) + x][(board->pos_y - piece->pos_y) + y] ==
		board->opp_symbol + 32)
		return (0);
	else if (ft_isdigit((board->raw[(board->pos_x - piece->pos_x) +
		x][(board->pos_y - piece->pos_y) + y])))
		board->value = board->value + (board->raw[(board->pos_x -
			piece->pos_x) +
		x][(board->pos_y - piece->pos_y) + y] - '0');
	return (1);
}

int		transfer_to_high_value(t_board *board, t_piece *piece)
{
	board->high_value = board->value;
	board->move_x = board->pos_x - piece->pos_x;
	board->move_y = board->pos_y - piece->pos_y;
	return (1);
}

int		check_board_to_piece(t_board *board, t_piece *piece)
{
	int x;
	int y;

	board->touch = 0;
	board->value = 0;
	x = piece->pos_x - 1;
	y = piece->pos_y - 1;
	while (piece->raw[++x])
	{
		while (piece->raw[x][++y])
		{
			if (piece->raw[x][y] == '*')
				if (!check_data(board, piece, x, y))
					return (0);
		}
		y = -1;
	}
	if (board->touch == 1)
	{
		if (board->value > board->high_value &&
			transfer_to_high_value(board, piece))
			return (1);
	}
	return (0);
}

void	compare_board(t_board *board, t_piece *piece)
{
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (check_board_to_piece(board, piece))
				;
		}
	}
}

void	find_safe_spot(t_board *board, t_piece *piece)
{
	piece->pos_x = -1;
	while (piece->raw[++piece->pos_x])
	{
		piece->pos_y = -1;
		while (piece->raw[piece->pos_x][++piece->pos_y])
		{
			if (piece->raw[piece->pos_x][piece->pos_y] == '*')
			{
				compare_board(board, piece);
				return ;
			}
		}
	}
}
