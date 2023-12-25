# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 22:02:45 by lgaume            #+#    #+#              #
#    Updated: 2023/12/23 22:02:49 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft/libft.a
INC = inc/
SRC_PATH = src/
OBJ_PATH = obj/

GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
CYAN =	\033[1;36m
MAGENTA = \033[1;35m
RESET = \033[0m

SRC = so_long
SRC += utils/res utils/points utils/frees
SRC += init_map/init_map init_map/get_map init_map/check_map init_map/set_map init_map/pathfinding
SRC += game/img game/moves game/start_game
SRCS 	= $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC)))
OBJ 	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

all:					$(NAME)

make_all:
						@make mlx && make libft && make

clean_all:				clean
						@make mlx_clean && make libft_clean && make fclean

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

clean:
						@$(RM) $(OBJ)
						@make clean -C ./libft

fclean:					clean
						@$(RM) $(NAME)
						@echo "$(YELLOW)Cleaned so_long $(RESET)"

re:						fclean all

libft:					$(LIBFT)

libft_clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"

mlx:
						@make -s -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"

mlx_clean:
						@make clean -C ./mlx
						@echo "$(YELLOW)Cleaned MLX$(RESET)"

norm:
						@echo "$(MAGENTA)\nNorm of inc :"
						@python3 -m norminette inc/
						@echo "$(CYAN)\nNorm of src :"
						@python3 -m norminette src/

norm_libft:
						@echo "$(CYAN)\nNorm of Libft"
						@python3 -m norminette libft/

.PHONY:					all clean fclean re mlx mlx_clean libft libft_clean make_all clean_all norm norm_libft