# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:08:34 by tgibier           #+#    #+#              #
#    Updated: 2023/07/19 15:35:39 by tgibier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Das Progamm
NAME				=	minishell
NAME_BONUS			=	bonus

# Compiler
CC					=	cc	
CFLAGS				=	-g3 -Wall -Werror -Wextra
LDFLAGS				=	-L $(LIBFT_PATH) -lft
	
# Libft	
LIBFT_PATH			=	libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(LIBFT_PATH)$(LIBFT_NAME)

HEAD				=	-I ./includes/ \
						-I ./libft/

DEPS				=	${OBJS:.o=.d}

# Sources
SRCS_PATH			=	srcs
SRCS_NAMES			=	main.c \
						clean_exit.c \
						get_path.c \
						lexer.c \
						lst_functions.c \
						get_next_line.c \
						get_next_line_utils.c 
						
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))
SRCS_BONUS_PATH		=	srcs/bonus
BONUS_NAMES			=	bonus.c
BONUS				=	$(addprefix $(SRCS_BONUS_PATH)/, $(BONUS_NAMES))

# Objects
OBJS_PATH			=	objs
OBJS_NAMES			=	$(SRCS_NAMES:.c=.o)
OBJS_BONUS_NAMES	=	$(BONUS_NAMES:.c=.o)
OBJS				=	$(addprefix $(OBJS_PATH)/,$(OBJS_NAMES))
OBJS_BONUS			=	$(addprefix $(OBJS_PATH)/,$(OBJS_BONUS_NAMES))

# -fsanitize=address

MAKEFLAGS			=	--no-print-directory

all	:	$(NAME) $(LIBFT)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
	
$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(LIBFT):
		@echo "Crafting Libft"
		@make -sC $(LIBFT_PATH)

$(NAME)	: $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LDFLAGS)
	@echo "\033[34;5mMINISHELL ready, WOOP WOOP\033[0m"

bonus	:	all $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(OBJS_PATH)/%.o: $(SRCS_BONUS_PATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

clean	:
	@echo "Cleaning the mess"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)

fclean	:	clean
	@echo "byyye minishit"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus