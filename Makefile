NAME = cub3D
CC = cc
FLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address,leak
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
	srcs/exec/movements.c\
	srcs/exec/mouse.c\
	srcs/exec/raycasting_calculations.c\
	srcs/exec/raycasting.c

OBJS = ${SRCS:.c=.o}

all: install $(NAME)

$(NAME): $(OBJS)
	@echo "🔨 Building cub3D..."
	@$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "✅ cub3D build finished!"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

mlx_linux:
	@if [ ! -d "mlx_linux" ]; then \
		echo "📥 Cloning MinilibX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux > /dev/null 2>&1; \
	fi
	@echo "⚙️  Creating MinilibX..."
	@make -C mlx_linux/ > /dev/null
	@echo "✅ MinilibX ready!"

install: mlx_linux

clean:
	@echo "🧹 Cleaning objects..."
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean > /dev/null; \
	fi
	@echo "✅ Clean done!"

fclean: clean
	@echo "🗑️ Removing binary and MinilibX..."
	@$(RM) $(NAME)
	@$(RM) mlx_linux
	@echo "✅ Full clean done!"

re: fclean all

.PHONY: all fclean clean re install mlx_linux
