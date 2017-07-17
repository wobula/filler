/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:46:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 13:09:41 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_board
{
	int			player;
	char		player_symbol;
	char		opp_symbol;
	int			l;
	int			h;
	int			pos_x;
	int			pos_y;
	char		**raw;
	int			count_b;
	int			move_x;
	int			move_y;
	int			high_value;
	int			mode;
	int			y;
	int			player_s;
	int			bread;
	int			touch;
	int			value;
}				t_board;

typedef struct	s_piece
{
	int			l;
	int			h;
	int			pos_x;
	int			pos_y;
	int			count_p;
	char		**raw;
}				t_piece;

void			make_heat_map(t_board *board);
void			find_safe_spot(t_board *board, t_piece *piece);
int				check_start(char *str, char *start);
int				get_size(char *line);
void			get_player(t_board *board, char *line);
int				get_x(char *line);
int				get_y(char *line);
void			get_board_metadata(t_board *board, char *line);
void			get_board_raw(t_board *board, char *line);
void			get_piece_metadata(t_piece *piece, char *line);
int				get_piece_raw(t_piece *piece, char *line);
void			value(t_board *board, char value, int offset);
void			fill_trail(t_board *board, char c);
void			free_board_piece(t_board *board, t_piece *piece);
void			free_remains(t_board *board, t_piece *piece);

#endif
