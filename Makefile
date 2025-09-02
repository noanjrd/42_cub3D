NAME = cub3D
CC = cc
FLAGS = -g3   #-fsanitize=address,leak
RM = rm -rf

SRCS = srcs/main.c\
	srcs/utils/utils.c\
	srcs/utils/player_utils.c\
	srcs/utils/utils2.c\
	srcs/utils/libft.c\
	srcs/utils/free.c\
	srcs/utils/init.c\
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
	srcs/exec/manage_window.c\
	srcs/exec/ray_casting.c\
	srcs/exec/ray_casting2.c

OBJS = ${SRCS:.c=.o}

all: install $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME) 
	make clean

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

mlx_linux:
	if [ ! -d "mlx_linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux > /dev/null 2>&1; \
	fi
	make -C mlx_linux/ > /dev/null

install: mlx_linux

clean:
	$(RM) $(OBJS)
	if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean > /dev/null; \
	fi

fclean: clean
	$(RM) $(NAME)
	$(RM) mlx_linux

re: fclean all

.PHONY: all fclean clean re install mlx_linux