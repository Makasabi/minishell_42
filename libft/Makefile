# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:38:29 by tgibier           #+#    #+#              #
#    Updated: 2023/07/16 15:49:51 by tgibier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -g3 -Wall -Werror -Wextra

CC			= cc

AR			= ar rcs

HEAD		=	-I ./includes/

SRCS_PATH	=	srcs/

SRCS_NAMES	= ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c \
	ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c \
	ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c \
	ft_tolower.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_strrchr.c ft_substr.c ft_toupper.c ft_strtrim.c ft_printf.c \
	ft_strchr.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	ft_putbase.c ft_putchar.c ft_putstr.c ft_putp.c
	# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	# ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
	

SRCS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))

OBJS_PATH	=	objs
OBJS_NAMES	=	$(SRCS_NAMES:.c=.o)
OBJS		=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

all: $(NAME)

$(OBJS_PATH)/%.o	: $(SRCS_PATH)/%.c 
		@mkdir -p $(OBJS_PATH)
		@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
	
$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "Libft ready, WOOP WOOP"

clean: 
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@echo "Cleaned the mess (￣ー￣)ゞ"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
