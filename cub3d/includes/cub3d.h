/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:16:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/14 19:28:05 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WHITE		"\033[0m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define BLUE		"\033[1;34m"
# define CYAN		"\033[1;36m"
# define RED		"\033[1;31m"
# define PURPLE		"\033[0;35m"

/*-------- libft --------*/
# include "../libft/includes/libft.h"

/*-------- printf --------*/
# include "../libft/includes/pt_printf.h"

/*-------- get_next_line --------*/
# include "../libft/includes/get_next_line.h"

/*write, read, close, access, pipe, dup, dup2, execve and fork */
# include <unistd.h>

/*-------- printf, perror --------*/
# include <stdio.h>

/*-------- malloc, free and exit --------*/
# include <stdlib.h>

/*-------- open and unlink --------*/
# include <fcntl.h>

/*-------- sin and cos --------*/
# include <math.h>

/*-------- mlx --------*/
# include "../mlx/mlx.h"

/*-------- Header Files made --------*/
# include "structs.h"
# include "math.h"
# include "parsing.h"
# include "player.h"
# include "rendering.h"

/*-------- cub_utils.c --------*/
void	free_double_array(char **arr);
int		return_error(char *str, t_map *map, t_game *game);

/*-------- cub_init.c --------*/
void	cub_window_init(t_window **win);

#endif