# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 10:55:58 by amalbrei          #+#    #+#              #
#    Updated: 2023/05/14 19:29:17 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

D				=	\033[0m
R				=	\033[1;31m
G				=	\033[1;32m
Y				=	\033[1;33m
P				=	\033[0;35m
C				=	\033[1;36m

NAME			=	cub3D
SUB_LIB			=	libft/libft.a
OBJ_DIR			=	object_files
MATH_DIR		=	math
PLAYER_DIR		=	player
RENDERING_DIR	=	rendering
PARSING_DIR		=	parsing
MAIN_DIR		=	source_files
MLX_DIR			=	-Imlx
INC_DIR 		=	-Iincludes -Ilibft/includes
LIB				=	ar	-rcs
LIBFT			=	-Llibft -lft
MLX				=	-Lmlx -lmlx
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g -Ofast
CUB3D_FLAGS 	=	-framework OpenGL -framework AppKit
RM				=	rm	-rf

MATH_SRC 		=	

PLAYER_SRC		=

RENDERING_SRC	=

PARSING_SRC		=	make_map.c	map_validation.c	parsing.c	\
					textures_and_colors.c

MAIN_SRC 		=	main.c	cub_utils.c	cub_init.c

SRC				=	$(MATH_SRC) $(PLAYER_SRC) $(RENDERING_SRC) $(PARSING_SRC)\
					$(MAIN_SRC)

OBJ				= 	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: mlx $(SUB_LIB) $(NAME)  

mlx:
	@$(MAKE) all -C mlx

$(SUB_LIB):
	@printf "$(C)==========================\n"
	@printf "$(C)==========================\n"
	@printf "LIBFT COMPILATION START\n"
	@printf "$(C)==========================\n\n\n\n$(D)"
	@$(MAKE) libft.a -C libft
	@$(MAKE) bonus -C libft
	@$(MAKE) printf -C libft
	@$(MAKE) gnl -C libft
	@printf "$(C)==========================\n"
	@printf "LIBFT COMPILATION FINISHED\n"
	@printf "$(C)==========================\n"
	@printf "$(C)==========================\n\n$(D)"

$(OBJ_DIR)/%.o: $(MATH_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR)  -c $< -o $@

$(OBJ_DIR)/%.o: $(PLAYER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(RENDERING_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSING_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LIBFT) $(MLX) $(CUB3D_FLAGS) -o $(NAME)
# @echo "$(PEJON)"
	@printf "$(C)\n==========================\n"
	@printf "$(C) CUB3D COMPILED\n"
	@printf "$(C)==========================\n$(D)"

chirp:
	

norm:
	@norminette | grep Error

valgrind: all
	@printf "$(P)Checking with valgrind...\n$(D)"
	@valgrind \
	--leak-check=full \
	--trace-children=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	./cub3D

list:
	@$(MAKE) list -C libft

clean:
	@$(MAKE) clean -C mlx
	@$(MAKE) clean -C libft
	@$(RM) $(OBJ_DIR)
	@printf "$(R)CLEANING CUB.O FILES\n$(D)"

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)
	@printf "$(R)CLEANING CUB3D PROGRAM\n$(D)"

re: fclean all

.PHONY: all mlx $(SUB_LIB) norm chirp valgrind list clean fclean re