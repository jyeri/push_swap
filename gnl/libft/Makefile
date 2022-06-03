# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 17:32:08 by jrummuka          #+#    #+#              #
#    Updated: 2021/11/03 17:33:41 by jrummuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strcat.c ft_strcmp.c\
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_strcpy.c \
					ft_memcpy.c  ft_strchr.c ft_bzero.c ft_strncat.c ft_strstr.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_strncpy.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c ft_memset.c ft_memalloc.c \
					ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
					ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
					ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
					ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c \
					ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lastoflist.c ft_listreverse.c ft_listsize.c ft_lstaddback.c\
					ft_nlen.c ft_freearr.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus