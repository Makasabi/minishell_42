# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrony <mrony@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:08:34 by tgibier           #+#    #+#              #
#    Updated: 2023/09/28 17:49:02 by mrony            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include mk/includes.mk
-include mk/sources.mk
-include mk/colors.mk


# Das Progamm
NAME				=	minishell
NAME_BONUS			=	bonus

# Compiler
CC					=	cc
CFLAGS				=	-g3 -Wall -Werror -Wextra 

#-fsanitize=address
LDFLAGS				=	-L $(LIBFT_PATH) -lft

# Libft
LIBFT_PATH			=	libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(LIBFT_PATH)$(LIBFT_NAME)

HEAD				=	-I ./inc -I ./libft/inc

DEPS				=	${OBJS:.o=.d}

# Sources
SRCS_PATH			=	srcs/

# Objects
OBJS_PATH			=	.objs/
OBJS_NAMES			=	$(SRCS:.c=.o)
OBJS				=	$(addprefix $(OBJS_PATH)/,$(OBJS_NAMES))

# -fsanitize=address

MAKEFLAGS			=	--no-print-directory

all	:	$(NAME)

$(OBJS_PATH)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)
	@printf "$(_FOREST_GREEN)🛸 Preparing for landing... %-50s \r" $@

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo "$(_EMMERALD)Minishell: .obj/ folder created$(_END)"

$(LIBFT):
	@echo "$(_GOLD)Summoning libft's genie$(_END)"
	@make -sC $(LIBFT_PATH)

$(NAME)	: $(LIBFT) $(OBJS_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LDFLAGS) -lreadline
	@echo "\n$(_FOREST_GREEN)$(_BOLD)👾 MINISHELL landed and ready, WOOP WOOP 👾$(_END)"

clean	:
	@echo "$(_AQUAMARINE)Minishell: Cleaning the mess$(_END)"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@make clean -C libft

fclean	:	clean
	@echo "$(_AQUAMARINE)$(_BOLD)🚀 Minishel leaving: byyye minishit 🚀$(_END)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C libft

re:	fclean all

gmk:
		@if [ -d mk ];then echo ok;else mkdir mk;fi
		@find -path './src/*' -name '*.c' | sed 's/^/SRCS += /' > mk/sources.mk
		@find -path './inc/*' -name '*.h' | sed 's/^/INCLUDES += /' > mk/includes.mk

-include $(DEPS)

.PHONY:	all clean fclean re bonus