/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:39:32 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/24 20:21:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_return_error(char *str, t_map *map, t_game *game)
{
	cub_free_segments(&game);
	cub_free_map(&game);
	ft_free(&game->player);
	return_error(str, map, game);
}
