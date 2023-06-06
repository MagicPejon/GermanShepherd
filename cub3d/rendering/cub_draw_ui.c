/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:01:03 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/05 12:51:12 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_draw_outline(t_game *game, t_bress bress)
{
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
}

void	cub_draw_cursor(t_game *game, t_player *player)
{
	int		i;
	t_bress	bress;

	i = 0;
	if (game->map->segment[game->start]->player_found)
	{
		game->color = 0x00FF0000;
		bress.x = player->x_m_grid * game->m_mag;
		bress.y = player->y_m_grid * game->m_mag;
		my_mlx_pixel_put(game, bress.x, bress.y);
		cub_draw_outline(game, bress);
	}
}

void	cub_turn_transparent(t_game *game, int width, int height, int *start)
{
	int	x;
	int	y;

	x = start[0];
	y = 0;
	game->color = 0xFF000000;
	while (y <= height)
	{
		if (y < start[1])
			x = start[0];
		else
			x = 0;
		while (x <= width)
		{
			my_mlx_pixel_put(game, x, y);
			x++;
		}
		y++;
	}
}

void	cub_draw_ui(t_game *game)
{
	int	start[2];

	cub_draw_m_background(game, game->win);
	start[0] = 0;
	start[1] = 0;
	cub_prep_image(&(game->win));
	cub_turn_transparent(game, game->win->window_w, game->win->window_h, start);
	cub_draw_grid(game, game->map->segment[game->start]->grid);
	cub_print_m_info(game);
	cub_draw_cursor(game, game->player);
	cub_place_image(&(game->win));
}
