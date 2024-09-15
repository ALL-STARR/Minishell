# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:30:52 by thomvan-          #+#    #+#              #
#    Updated: 2023/11/14 02:21:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_isalpha.c\
	ft_itoa.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c

SRCS_BONUS	= ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c
	
OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

includes= libft.h

RM 		= rm -f

NAME	= libft.a

CC		= gcc

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

FLAGS	= -Wall -Werror -Wextra

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS} ${includes}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	${OBJS_BONUS} ${OBJS}
		ar rc ${NAME} ${OBJS} ${OBJS_BONUS} ${includes}

.PHONY:	all clean fclean re