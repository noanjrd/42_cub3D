NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address,leak
RM		= rm -rf

SRCS = srcs/main.c \
	srcs/utils/utils.c \
	srcs/utils/player_utils.c \
	srcs/utils/utils2.c \
	srcs/utils/libft.c \
	srcs/utils/ft_split.c \
	srcs/utils/free.c \
	srcs/utils/init.c \
	srcs/parsing/parsing.c \
	srcs/parsing/map.c \
	srcs/parsing/map2.c \
	srcs/parsing/map3.c \
	srcs/parsing/map_closed.c \
	srcs/parsing/info_before_map.c \
	srcs/parsing/info_before_map2.c \
	srcs/parsing/map_error.c \
	srcs/parsing/getline.c \
	srcs/parsing/getline2.c \
	srcs/parsing/colors.c \
	srcs/exec/exec.c \
	srcs/exec/manage_window.c \
	srcs/exec/ray_casting.c \
	srcs/exec/ray_casting2.c \
	srcs/exec/ray_casting3.c \
	srcs/exec/ft_free.c \
	srcs/exec/draw_columns.c \
	srcs/exec/manage_key.c

OBJS	= $(SRCS:.c=.o)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RED		= \033[1;31m
CYAN	= \033[1;36m
RESET	= \033[0m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: header install $(NAME)

header:
	@echo "$(CYAN)"
	@echo "  🚀 Compiling $(NAME) ..."
	@echo "--------------------------------------$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)✔ Build complete !$(RESET)"

%.o: %.c
	@printf "$(YELLOW)Compiling: %-40s$(RESET)\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

mlx_linux:
	@if [ ! -d "mlx_linux" ]; then \
		echo "$(CYAN)→ Installing mlx_linux ...$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux > /dev/null 2>&1; \
	fi
	@make -C mlx_linux/ > /dev/null

install: mlx_linux

clean:
	@$(RM) $(OBJS)
	@if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean > /dev/null; \
	fi
	@echo "$(RED)✘ Objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) mlx_linux
	@echo "$(RED)✘ Full clean$(RESET)"

re: fclean all

.PHONY: all fclean clean re install mlx_linux header
