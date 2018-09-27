#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 22:38:46 by osavytsk          #+#    #+#              #
#    Updated: 2018/07/26 22:38:46 by osavytsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	osavytsk.filler
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -Rf
LIB		=	./libft/libft.a
LIBSRC	=	./libft/
HEADER	=	./includes/
OBJDIR	=	./obj/
SRCDIR	=	./src/
SRC		=	can_put.c \
			filler.c \
			get_actual_map.c \
			calc_way.c \
			another_functions.c

SRCS	=	$(addprefix $(SRCDIR), $(SRC))
OBJS	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAG) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C $(LIBSRC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)filler.h
	@mkdir -p $(OBJDIR)
	$(CC) -o $@ $(FLAG) -c $< -I $(HEADER)

clean:
	$(RM) $(OBJS)
	make -C $(LIBSRC) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBSRC) fclean

re: fclean all
	make -C $(LIBSRC) re

.PHONY: all clean fclean re
