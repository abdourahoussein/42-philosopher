# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 00:33:39 by abhousse          #+#    #+#              #
#    Updated: 2022/11/15 03:38:13 by abhousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  analyse.c main.c time.c print.c

OBJ = $(SRC:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

CC = gcc


NAME = philo
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) -o $@
	
%.o: %.c philo.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all