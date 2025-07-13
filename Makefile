NAME = cub3D
CC = cc
FLAGS = -g3 -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm  #-fsanitize=address,leak
RM = rm -rf

SRCS = main.c\
	utils.c\
	libft.c\
	free.c\
	init.c\
	parsing/parsing.c\
	parsing/getline.c

OBJS = ${SRCS:.c=.o}

all: install $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 
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