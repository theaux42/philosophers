# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 12:05:29 by tbabou            #+#    #+#              #
#    Updated: 2024/08/23 12:11:08 by tbabou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

COMPILER = cc
FLAGS = -Wall -Wextra -Werror

MAIN = philosophers.c
SRC = utils.c

SRC_DIR = $(addprefix src/, $(SRCS))
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(COMPILER) $(FLAGS) $(MAIN) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
