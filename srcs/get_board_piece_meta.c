/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_piece_meta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:10:52 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 12:10:55 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_board_metadata(t_board *board, char *line)
{
	board->l = get_x(line);
	board->h = get_y(line);
	board->raw = (char **)ft_memalloc(sizeof(char *) * (board->l + 1));
	board->raw[board->l] = 0;
	board->count_b = 0;
}

void	get_board_raw(t_board *board, char *line)
{
	board->raw[board->count_b] = ft_strdup(line + 4);
	board->count_b++;
}

void	get_piece_metadata(t_piece *piece, char *line)
{
	piece->l = get_x(line);
	piece->h = get_y(line);
	piece->raw = (char **)ft_memalloc(sizeof(char *) * (piece->l + 1));
	piece->raw[piece->l] = NULL;
	piece->count_p = 0;
}

int		get_piece_raw(t_piece *piece, char *line)
{
	if (!piece->raw)
		piece->raw = (char **)ft_memalloc(sizeof(char *) * (piece->l + 1));
	piece->raw[piece->count_p] = ft_strdup(line);
	piece->count_p++;
	if (piece->count_p == piece->l)
	{
		piece->count_p = 0;
		return (1);
	}
	return (0);
}
