# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =	main.c \

OBJS_SRC = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~ UTILS ~~~~~~ */
UTILS_DIR = ./srcs/utils/
UTILS =	utils.c \
		utils2.c \
		utils_linked_list.c \
		ft_split.c

OBJS_UTILS = ${addprefix ${UTILS_DIR}, ${UTILS:.c=.o}}


# /* ~~~~~~ PARSING ~~~~~~ */
PARSING_DIR = ./srcs/parsing/
PARSING =	parsing.c \
			check_items.c
OBJS_PARSING = ${addprefix ${PARSING_DIR}, ${PARSING:.c=.o}}

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
IFLAGS:= -I ./includes

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = cub
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}

$(NAME): $(OBJS_SRC) $(OBJS_PARSING) $(OBJS_UTILS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS)  $(OBJS_PARSING) $(OBJS_SRC)  $(OBJS_UTILS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

exec:	${NAME}
	./${NAME} t.cub

val:	${NAME}
	valgrind ./${NAME} t.cub

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} $(OBJS_SRC) $(OBJS_PARSING) $(OBJS_UTILS) ${NAME}
		@${RM} -r ${OBJ_DIR}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} $(OBJS_SRC) $(OBJS_PARSING) $(OBJS_UTILS) ${NAME}

re: 	fclean all

.PHONY: all clean fclean re