# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 01:55:27 by tponark           #+#    #+#              #
#    Updated: 2022/09/11 06:50:59 by tponark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c  ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_OBJS = $(BONUS:.c=.o) 

all: $(NAME)

%o: %c
	@echo "\033[93mCompiling $< to $@...\033[0m"
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS)
	@echo "\033[92mMaking .a from all the .o files...\033[0m"
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "\033[91mCleaning objects...\033[0m"
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "\033[91mCleaning library...\033[0m"
	@rm -f $(NAME)
	@rm -f libft.so a.out

bonus: $(OBJS) $(BONUS_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

so:
	gcc -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re so
