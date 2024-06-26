# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 22:02:45 by lgaume            #+#    #+#              #
#    Updated: 2024/06/05 08:11:40 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
NAME_BONUS	 = so_long_bonus

CC 		= gcc -g
FLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f

LIBFT 			= ./libft/libft.a
INC 			= inc/
INC_BONUS 		= inc_bonus/
SRC_PATH 		= src/
OBJ_PATH 		= obj/
SRC_BONUS_PATH	= bonus/
OBJ_BONUS_PATH	= obj_bonus/

GREEN 	= \033[1;32m
BLUE 	= \033[1;34m
YELLOW 	= \033[1;33m
CYAN 	= \033[1;36m
MAGENTA = \033[1;35m
RESET 	= \033[0m

SRC 	= so_long
SRC 	+= utils/res utils/points utils/frees utils/utils
SRC 	+= init_map/init_map init_map/get_map init_map/check_map init_map/set_map init_map/pathfinding
SRC 	+= game/img game/moves game/start_game
SRCS 	= $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC)))
OBJ 	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

SRC_BONUS 	= so_long
SRC_BONUS	+= utils/res utils/points utils/frees utils/utils
SRC_BONUS	+= game/img game/moves game/start_game game/text game/victory game/lose
SRC_BONUS	+= anim/anim anim/set_player anim/anim_moves anim/set_item anim/anim_item
SRC_BONUS 	+= init_map/init_map init_map/get_map init_map/check_map init_map/set_map init_map/pathfinding
SRCS_BONUS 	= $(addprefix $(SRC_BONUS_PATH), $(addsuffix .c, $(SRC_BONUS)))
OBJ_BONUS 	= $(patsubst $(SRC_BONUS_PATH)%.c,$(OBJ_BONUS_PATH)%.o,$(SRCS_BONUS))

all:					$(NAME)

$(LIBFT) :
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"

$(NAME): 				$(OBJ)
						@make -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"
						@$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
						@echo "$(GREEN)[✓] so_long compiled$(RESET)"

$(OBJ_PATH)%.o: 		$(SRC_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

bonus:					$(OBJ_BONUS)
						@make -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"
						@$(CC) $(FLAGS) -fsanitize=address -g -I $(INC_BONUS) $(OBJ_BONUS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
						@echo "$(GREEN)[✓] so_long_bonus compiled$(RESET)"

$(OBJ_BONUS_PATH)%.o: 	$(SRC_BONUS_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC_BONUS) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"
						@make clean -C ./mlx
						@echo "$(YELLOW)Cleaned MLX$(RESET)"
						@$(RM) $(OBJ)
						@echo "$(YELLOW)Cleaned so_long$(RESET)"

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

bonus_clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"
						@make clean -C ./mlx
						@echo "$(YELLOW)Cleaned MLX$(RESET)"
						@$(RM) $(OBJ_BONUS)
						@echo "$(YELLOW)Cleaned so_long_bonus$(RESET)"

bonus_fclean:			bonus_clean
						@$(RM) $(NAME_BONUS)

bonus_re:				bonus_fclean bonus

libft:					$(LIBFT)

mlx:
						@make -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"

norm:
						@echo "$(MAGENTA)\nNorm of inc :"
						@norminette inc/
						@norminette inc_bonus/
						@echo "$(CYAN)\nNorm of src :"
						@norminette src/
						@norminette bonus/

.PHONY:					all clean fclean re mlx mlx_clean libft libft_clean make_all clean_all norm norm_libft bonus bonus_fclean bonus_clean bonus_re bonus_clean_all bonus_make_all
