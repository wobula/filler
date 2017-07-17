/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:27:51 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 20:40:16 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_leftovers_with_twos(t_board *board)
{
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (board->raw[board->pos_x][board->pos_y] == '.')
				board->raw[board->pos_x][board->pos_y] = '2';
		}
	}
}

void	create_bread_trail(t_board *board)
{
	int	limit;

	limit = board->h / 2;
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (board->pos_y == limit &&
				board->raw[board->pos_x][board->pos_y] == '2')
				board->raw[board->pos_x][board->pos_y] = 'B';
		}
	}
}

void	connect_to_trail(t_board *board, char c)
{
	board->bread = 0;
	board->player_s = 0;
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (board->raw[board->pos_x][board->pos_y] == 'B')
				board->bread = 1;
			else if (board->raw[board->pos_x][board->pos_y] == c ||
				board->raw[board->pos_x][board->pos_y] == c + 32)
				board->player = 1;
			if (board->bread == 1 && board->player == 1)
			{
				fill_trail(board, c);
				board->bread = 0;
				board->player = 0;
			}
		}
		board->bread = 0;
		board->player = 0;
	}
}

void	convert_b_to_three(t_board *board)
{
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		board->pos_y = -1;
		while (board->raw[board->pos_x][++board->pos_y])
		{
			if (board->raw[board->pos_x][board->pos_y] == 'B')
				board->raw[board->pos_x][board->pos_y] = '3';
		}
	}
}

void	make_heat_map(t_board *board)
{
	value(board, '4', 3);
	value(board, '2', 1);
	value(board, '7', 2);
	fill_leftovers_with_twos(board);
	create_bread_trail(board);
	connect_to_trail(board, board->player_symbol);
	connect_to_trail(board, board->opp_symbol);
	convert_b_to_three(board);
}
