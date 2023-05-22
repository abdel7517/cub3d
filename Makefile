# /* ~~~~~~ NAME ~~~~~~ */

NAME = cub3D

# /* ~~~~~~~ Colors ~~~~~~~ */

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

# /* ~~~~~~ SOURCES ~~~~~~ */

SRCS_DIR = srcs/

SRCS =	main.c

SRCS +=	parsing/check_file.c \
		parsing/check_items.c \
		parsing/check_map_closed.c \
		parsing/check_texture.c \
		parsing/duplicate_map.c \
		parsing/handle_map.c \
		parsing/parsing.c \

SRCS +=	utils/data.c \
		utils/ft_split.c \
		utils/utils.c \
		utils/utils2.c \
		utils/utils3.c

SRCS += casting/window.c

SRCS := ${addprefix ${SRCS_DIR}, ${SRCS}}

# /* ~~~~~~~ OBJECTS & DEPENDANCES ~~~~~~~ */

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJS_DIR), $(OBJS))
DEP = ${OBJS_SRC:.o=.d} ${OBJS_UTILS:.o=.d} ${OBJS_PARSING:.o=.d}

# /* ~~~~~~~ LIBS ~~~~~~~ */

LIB_DIR = ./libs/
DIR_MINILIBX = ./srcs/minilibx-linux/
LIB_MINILIBX = ./libs/libmlx.a ./libs/libmlx_Linux.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -MMD
MINILIBX_FLAGS = -lXext -lX11 -lm -lz

# /* ~~~~~~~ COMMANDS ~~~~~~~ */

RM = rm -rf
MKDIR = mkdir -p
CP = cp

# /* ~~~~~~~ RULES ~~~~~~~ */

all:	${NAME}

$(NAME): $(OBJS) ${LIB_MINILIBX}
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) ${OBJS} ${LIB_MINILIBX} -o $(NAME) ${MINILIBX_FLAGS} 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

${LIB_MINILIBX}:
	@${MKDIR} ${LIB_DIR}
	@echo $(CYAN) " - Compiling minilibx" $(RED)
	@make -C ${DIR_MINILIBX}
	@${CP} ${DIR_MINILIBX}libmlx.a ${LIB_DIR}
	@${CP} ${DIR_MINILIBX}libmlx_Linux.a ${LIB_DIR}
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

run:	${NAME}
	./${NAME} ./maps/t.cub

val:	${NAME}
	valgrind ./${NAME} ./maps/t.cub

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@make clean -C ${DIR_MINILIBX}
		@${RM} ${OBJS_DIR} ${LIB_DIR}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re

$(OBJS_DIR)%.o	: %.c
				@${MKDIR} $(@D)
	        	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

-include ${DEP}