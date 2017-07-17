/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:46:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/07/16 17:24:13 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_game_info(t_board *board, t_piece *piece)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (check_start(line, "$$$") && ft_strstr(line, "./filler"))
			get_player(board, line);
		if (check_start(line, "Plateau"))
			get_board_metadata(board, line);
		if (check_start(line, "Piece"))
			get_piece_metadata(piece, line);
		if ((line[0] == '*' || line[0] == '.'))
		{
			if (get_piece_raw(piece, line))
				return (1);
		}
		if (isdigit(line[0]))
			get_board_raw(board, line);
		ft_strdel(&line);
	}
	return (0);
}

int		analyze(t_board *board, t_piece *piece)
{
	int		x;

	x = -1;
	make_heat_map(board);
	find_safe_spot(board, piece);
	if (board->mode == 1)
	{
		while (piece->raw[++x])
			fprintf(stderr, "piece:[%d] %s\n", x, piece->raw[x]);
		x = -1;
		while (board->raw[++x])
			fprintf(stderr, "[%d]%s\n", x, board->raw[x]);
	}
	if (board->high_value > 0)
		return (1);
	return (0);
}

void	init_structs(t_board **board, t_piece **piece)
{
	*board = (t_board *)ft_memalloc(sizeof(t_board));
	*piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	(*board)->player_symbol = '-';
	(*piece)->raw = NULL;
	(*piece)->pos_x = -1;
	(*piece)->pos_y = -1;
	(*board)->raw = NULL;
	(*board)->pos_x = -1;
	(*board)->pos_y = -1;
	(*board)->move_x = -42;
	(*board)->move_y = -42;
	(*board)->high_value = 0;
	(*board)->mode = 1;
}

int		main(void)
{
	t_board	*board;
	t_piece *piece;

	init_structs(&board, &piece);
	while (get_game_info(board, piece))
	{
		if (analyze(board, piece))
		{
			ft_putnbr(board->move_x);
			ft_putchar(' ');
			ft_putnbr(board->move_y);
			ft_putchar('\n');
			board->high_value = 0;
			free_board_piece(board, piece);
		}
		else
			ft_putstr("0 0\n");
	}
	free_remains(board, piece);
	return (0);
}
