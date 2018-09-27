#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 22:38:46 by osavytsk          #+#    #+#              #
#    Updated: 2018/05/30 13:28:20 by osavytsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -Rf
HEADER	=	./includes/
OBJDIR	=	./obj/
SRCDIR	=	./src/
SRC		=	ft_atoi.c		ft_itoa.c		ft_memmove.c	ft_putstr.c \
			ft_strdel.c		ft_strlen.c		ft_strnew.c		ft_tolower.c \
			ft_bzero.c		ft_memalloc.c	ft_memset.c		ft_putstr_fd.c \
			ft_strdup.c		ft_strmap.c		ft_strnstr.c	ft_toupper.c \
			ft_isalnum.c	ft_memccpy.c	ft_putchar.c	ft_strcat.c \
			ft_strequ.c		ft_strmapi.c	ft_strrchr.c	ft_isalpha.c \
			ft_memchr.c		ft_putchar_fd.c	ft_strchr.c		ft_striter.c \
			ft_strncat.c	ft_strsplit.c	ft_isascii.c	ft_memcmp.c \
			ft_putendl.c	ft_strclr.c		ft_striteri.c	ft_strncmp.c \
			ft_strstr.c		ft_isdigit.c	ft_memcpy.c		ft_putendl_fd.c \
			ft_strcmp.c		ft_strjoin.c	ft_strncpy.c	ft_strsub.c \
			ft_isprint.c	ft_memdel.c		ft_putnbr.c		ft_strcpy.c \
			ft_strlcat.c	ft_strnequ.c	ft_strtrim.c	ft_putnbr_fd.c \
			ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c \
			ft_lstiter.c	ft_lstmap.c		ft_strrev.c		ft_power.c \
			ft_islower.c	ft_isupper.c	ft_isspace.c	get_next_line.c \
			ft_printf.c		take_type.c		pars.c			low_s.c \
		    up_s.c			low_p.c			low_d.c			up_d.c \
		    low_i.c			low_o.c			up_o.c 			low_c.c\
		    low_u.c			up_u.c			low_x.c			up_x.c \
		    up_c.c			percent.c		int_util.c		str_util.c \
		    tab_util.c 		uint_util.c		wstr_util.c		undef.c 	\

SRCS	=	$(addprefix $(SRCDIR), $(SRC))
OBJS	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)libft.h
	$(CC) -o $@ $(FLAG) -c $< -I $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
