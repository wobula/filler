/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_trail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:52:08 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 21:01:34 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_remains(t_board *board, t_piece *piece)
{
	free_board_piece(board, piece);
	ft_memdel((void*)&board->raw);
	ft_memdel((void*)&piece->raw);
	ft_memdel((void*)&board);
	ft_memdel((void*)&piece);
}

void	free_board_piece(t_board *board, t_piece *piece)
{
	board->pos_x = -1;
	while (board->raw[++board->pos_x])
	{
		ft_strdel(&board->raw[board->pos_x]);
	}
	piece->pos_x = -1;
	while (piece->raw[++piece->pos_x])
	{
		ft_strdel(&piece->raw[piece->pos_x]);
	}
}

void	fill(t_board *board, char c, int y)
{
	if (board->raw[board->pos_x][y] == 'B')
		board->bread = 1;
	else if (board->raw[board->pos_x][y] == c ||
		board->raw[board->pos_x][y] == c + 32)
		board->player_s = 1;
	else if (((board->player_s == 1 && board->bread == 0) ||
		(board->player_s == 0 && board->bread == 1))
		&& board->raw[board->pos_x][y] == '3')
		board->raw[board->pos_x][y] = '3';
	else if (board->player_s == 1 &&
		board->bread == 0 && board->raw[board->pos_x][y] == 'B')
		return ;
	else if (board->player_s == 0 &&
		board->bread == 1 && board->raw[board->pos_x][y] == c)
		return ;
	else if (board->player_s == 0 &&
		board->bread == 1 && board->raw[board->pos_x][y] == c + 32)
		return ;
}

void	fill_trail(t_board *board, char c)
{
	int y;

	board->player_s = 0;
	board->bread = 0;
	y = -1;
	while (board->raw[board->pos_x][++y])
		fill(board, c, y);
}
