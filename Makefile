# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 22:02:45 by lgaume            #+#    #+#              #
#    Updated: 2024/01/10 13:19:45 by lgaume           ###   ########.fr        #
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
CYAN 	=	\033[1;36m
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
SRC_BONUS	+= game/img game/moves game/start_game
SRC_BONUS 	+= init_map/init_map init_map/get_map init_map/check_map init_map/set_map init_map/pathfinding
SRCS_BONUS 	= $(addprefix $(SRC_BONUS_PATH), $(addsuffix .c, $(SRC_BONUS)))
OBJ_BONUS 	= $(patsubst $(SRC_BONUS_PATH)%.c,$(OBJ_BONUS_PATH)%.o,$(SRCS_BONUS))

all:					$(NAME)

make_all:
						@make mlx && make libft && make

clean_all:
						@make mlx_clean && make libft_clean && make fclean

bonus_make_all:
						@make mlx && make libft && make bonus

bonus_clean_all:
						@make mlx_clean && make libft_clean && make bonus_fclean

$(LIBFT) :
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"

$(NAME): 				$(OBJ)
						@$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
						@echo "$(GREEN)[✓] so_long compiled$(RESET)"

$(OBJ_PATH)%.o: 		$(SRC_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

bonus:					$(OBJ_BONUS)
						@$(CC) $(FLAGS) -I $(INC_BONUS) $(OBJ_BONUS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
						@echo "$(GREEN)[✓] so_long_bonus compiled$(RESET)"

$(OBJ_BONUS_PATH)%.o: 	$(SRC_BONUS_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC_BONUS) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

clean:
						@$(RM) $(OBJ)
						@echo "$(YELLOW)Cleaned so_long $(RESET)"

fclean:					clean
						@$(RM) $(NAME)
						@echo "$(YELLOW)Cleaned so_long $(RESET)"

re:						fclean all

bonus_clean:
						@$(RM) $(OBJ_BONUS)
						@echo "$(YELLOW)Cleaned so_long_bonus $(RESET)"

bonus_fclean:			bonus_clean
						@$(RM) $(NAME_BONUS)
						@echo "$(YELLOW)Cleaned so_long_bonus $(RESET)"

bonus_re:				bonus_fclean bonus

libft:					$(LIBFT)

libft_clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"

mlx:
						@make -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"

mlx_clean:
						@make clean -C ./mlx
						@echo "$(YELLOW)Cleaned MLX$(RESET)"

norm:
						@echo "$(MAGENTA)\nNorm of inc :"
						@python3 -m norminette inc/
						@python3 -m norminette inc_bonus/
						@echo "$(CYAN)\nNorm of src :"
						@python3 -m norminette src/
						@python3 -m norminette bonus/

norm_libft:
						@echo "$(CYAN)\nNorm of Libft"
						@python3 -m norminette libft/

.PHONY:					all clean fclean re mlx mlx_clean libft libft_clean make_all clean_all norm norm_libft bonus bonus_fclean bonus_clean bonus_re bonus_clean_all bonus_make_all