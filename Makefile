NAME = cub3D
CC = cc
FLAGS = -g3  -Wall -Wextra -Werror #-fsanitize=address,leak
RM = rm -rf

SRCS = srcs/main.c\
	srcs/utils/utils.c\
	srcs/utils/utils2.c\
	srcs/utils/libft.c\
	srcs/utils/free.c\
	srcs/utils/init.c\
	srcs/utils/init2.c\
	srcs/parsing/parsing.c\
	srcs/parsing/map.c\
	srcs/parsing/map2.c\
	srcs/parsing/map3.c\
	srcs/parsing/map_closed.c\
	srcs/parsing/info_before_map.c\
	srcs/parsing/info_before_map2.c\
	srcs/parsing/map_error.c\
	srcs/parsing/getline.c\
	srcs/parsing/getline2.c\
	srcs/parsing/colors.c\
	srcs/exec/exec.c\
	srcs/exec/keyboard.c\
	srcs/exec/mouse.c\
	srcs/exec/raycasting_calculations.c\
	srcs/exec/raycasting.c

SRCS_BONUS = bonus/srcs/main_bonus.c \
	bonus/srcs/utils/utils_bonus.c \
	bonus/srcs/utils/utils2_bonus.c \
	bonus/srcs/utils/libft_bonus.c \
	bonus/srcs/utils/free_bonus.c \
	bonus/srcs/utils/init_bonus.c \
	bonus/srcs/utils/init2_bonus.c \
	bonus/srcs/parsing/parsing_bonus.c \
	bonus/srcs/parsing/map_bonus.c \
	bonus/srcs/parsing/map2_bonus.c \
	bonus/srcs/parsing/map3_bonus.c \
	bonus/srcs/parsing/map_closed_bonus.c \
	bonus/srcs/parsing/info_before_map_bonus.c \
	bonus/srcs/parsing/info_before_map2_bonus.c \
	bonus/srcs/parsing/map_error_bonus.c \
	bonus/srcs/parsing/getline_bonus.c \
	bonus/srcs/parsing/getline2_bonus.c \
	bonus/srcs/parsing/colors_bonus.c \
	bonus/srcs/exec/exec_bonus.c \
	bonus/srcs/exec/keyboard_bonus.c \
	bonus/srcs/exec/mouse_bonus.c \
	bonus/srcs/exec/raycasting_calculations_bonus.c \
	bonus/srcs/exec/raycasting_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all:install $(NAME)


$(NAME):  $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME) 

bonus: install  $(OBJS_BONUS) 
	@$(CC) $(FLAGS) $(OBJS_BONUS)  -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME) 


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

mlx_linux:
	@if [ ! -d "mlx_linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux > /dev/null 2>&1; \
	fi
	@make -C mlx_linux/ > /dev/null

install: mlx_linux

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean > /dev/null; \
	fi

fclean: clean
	$(RM) $(NAME)
	$(RM) mlx_linux

re: fclean all

.PHONY: all fclean clean re install mlx_linux bonus 