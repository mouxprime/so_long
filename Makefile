# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mianni <mianni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:43:29 by mianni            #+#    #+#              #
#    Updated: 2024/10/14 21:06:49 by mianni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INCLUDES = minishell.h

SRC_DIR = ./minishell_utils

SRC = $(SRC_DIR)/minishell.c \
		$(SRC_DIR)/tokenisation.c \
		

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -I. # Options de compilation
LDFLAGS = -L/usr/local/opt/readline/lib -L$(LIBFT_PATH) # Dossiers de bibliothèques
LIBS = -lreadline -lft # Bibliothèques à lier
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
	
all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

libft_clean:
	$(MAKE) clean -C ./libft
	
libft_fclean:
	$(MAKE) fclean -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $@

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean: libft_clean
	rm -f $(OBJ)

fclean: libft_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIBFT libft_clean libft_fclean

