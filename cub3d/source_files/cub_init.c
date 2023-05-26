/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:05:07 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/26 23:44:18 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_prep_image(t_window **win)
{
	(*win)->addr->i_p = mlx_new_image((*win)->mlx, (*win)->window_w,
			(*win)->window_h);
	(*win)->addr->ad = mlx_get_data_addr((*win)->addr->i_p,
			&((*win)->addr->pix_bi), &((*win)->addr->line_by),
			&((*win)->addr->endian));
}

void	cub_draw(t_game *game)
{
	game->m_zoom = 12 * game->m_mag;
	game->m_xset = 2;
	game->m_yset = 2;
	cub_draw_ui(game);
}

void	cub_window_init(t_window **win)
{
	(*win)->mlx = mlx_init();
	(*win)->window_w = 1260;
	(*win)->window_h = 1260;
	(*win)->window = mlx_new_window((*win)->mlx, (*win)->window_w,
			(*win)->window_h, "Cub3D Clear To Fly");
	(*win)->addr = malloc(sizeof(t_addr));
}

void	cub_init(t_game *game)
{
	cub_window_init(&(game->win));
	cub_draw(game);
}
