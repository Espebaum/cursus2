NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit
MLXDIR		= ./mlx

SRCS = main.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	@echo "$(YELLOW) *** Generating object files ... *** $(DEFAULT)"
	@$(CC) $(CFLAGS) $< -c

$(NAME) : $(OBJS)
	@make all -C $(MLXDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(MLX) $(OBJS`)
	@echo "$(GREEN) *** [$(NAME)] Linking Success *** $(DEFAULT)"

all : $(NAME)

clean : 
	@echo "$(RED) *** Deleting objects ... *** $(DEFAULT)"
	@rm -rf $(OBJS)

fclean : clean
	@echo "$(RED) *** Deleting executable ... *** $(DEFAULT)"
	@rm -rf $(NAME)

re : fclean
	@make all
	@echo "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEFAULT)"

.PHONY = all clean fclean re

# ---------------------------------------------------------------------------- #
# 								Define the colors								#
# ---------------------------------------------------------------------------- #

GRAY		=	\033[1;30m
RED 		=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
MAGENTA		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
DEFAULT 	= 	\033[0m
