# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 13:15:51 by amenesca          #+#    #+#              #
#    Updated: 2022/07/21 14:33:14 by amenesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

SRCS    = path.c get_cmd.c pipex.c children.c out_error.c
OBJS    = $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

RM        = rm -f

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):    $(OBJS)
			make -C ./libft
			cc $(SRCS) ./libft/libft.a -o pipex

all:		$(NAME)

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME) pipex

re:			fclean all

.PHONY: all clean fclean re
