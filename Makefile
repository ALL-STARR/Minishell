# -----------------------------------Makefile------------------------------------
NAME	= minishell

# -----------------------------------Sources-------------------------------------

HEADER	= /includes/shell.h 

SHELL_SRCS 	= shell.c  \
				env.c\
				token_utils.c\
				token_utils_1.c\
				token.c\



SHELL_SRC	= ${SHELL_SRCS}

ALL_SRC		= ${SHELL_SRC} 

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

FT_FOLDER = ./libft

FT = ${FT_FOLDER}/libft.a

CC		= gcc -g #-fsanitize=address

FLAGS	= -Wall -Wextra -Werror

READ_FLAGS = -L/Users/$(shell whoami)/.brew/opt/readline/lib -I/Users/$(shell whoami)/.brew/opt/readline/include -lreadline

LIB		= ar -rc

RM		= rm -f

MAKE_FT = make -s -C ${FT_FOLDER}

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes ./libft/includes

# -----------------------------------Rules------------------------------------------

all: ${NAME}

$(NAME): $(OBJS) ${FT}
	$(CC) $(FLAGS) -o $(NAME)  $(OBJS) ${FT} ${READ_FLAGS}

${FT}: 
		${MAKE_FT}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${MAKE_FT} fclean

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re