# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = srcs/

SRCS =	main.c \

SRCS +=	utils/utils.c \
		utils/utils2.c \
		utils/utils3.c \
		utils/utils_linked_list.c \
		utils/ft_split.c

SRCS +=	parsing/parsing.c \
		parsing/check_items.c \
		parsing/check_texture.c \
		parsing/handle_map.c \
		parsing/duplicate_map.c \
		parsing/check_map_closed.c

SRCS := ${addprefix ${SRCS_DIR}, ${SRCS}}

# /* ~~~~~~~ OBJECT & DEPENDANCE ~~~~~~~ */

OBJS_DIR	= objs/

OBJS		= $(SRCS:.c=.o)

OBJS		:= $(addprefix $(OBJS_DIR), $(OBJS))

DEP = ${OBJS_SRC:.o=.d} ${OBJS_UTILS:.o=.d} ${OBJS_PARSING:.o=.d}

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -MMD

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = cub
RM = rm -rf
MKDIR = mkdir -p

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) ${OBJS} -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

exec:	${NAME}
	./${NAME} t.cub

val:	${NAME}
	valgrind ./${NAME} t.cub

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS_DIR}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re

$(OBJS_DIR)%.o	: %.c
				@${MKDIR} $(@D)
	        	${CC} ${CFLAGS} -c $< -o $@

-include ${DEP}