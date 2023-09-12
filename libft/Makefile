#################### INCLUDE ####################

-include make/includes.mk
-include make/sources.mk
-include make/colors.mk

INCPATH		:=	inc/
INC			:=	-I $(INCPATH)

################# FOLDER PATHS ##################

OBJFLDR		:=	.objs/

#################### SOURCES ####################

OBJS		:=	$(SOURCES:.c=.o)
OBJS		:=	$(addprefix $(OBJFLDR), $(OBJS))

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -g

MAKELIB		:=	ar -rcs

DEL			:=	rm -rf

NAME		:=	libft.a

####################  RULES  ####################

${NAME}: ${OBJFLDR} ${OBJS} $(INCLUDES)
		@${MAKELIB} ${NAME} ${OBJS}
		@ranlib ${NAME}
		@echo "\n🧞$(_FOREST_GREEN)$(_BOLD) Libft's genie is ready too grant you wishes $(_END)🧞"

all:	${NAME}

.objs/%.o:	%.c
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} -c $< -o $@ ${INC}
		@printf "$(_FOREST_GREEN)🪔 Rubbing the magic lamp... %-50s \r" $@

${OBJFLDR}:
		@mkdir -p ${OBJFLDR}
		@echo "$(_EMMERALD)libft: .obj/ folder created$(_END)"

clean:
		@${DEL} ${OBJFLDR}
		@echo "$(_AQUAMARINE)libft: Binary files deleted$(_END)"

fclean: clean
		@${DEL} ${NAME}
		@echo "$(_AQUAMARINE)libft: Object files & folders deleted$(_END)"
		@echo "$(_AQUAMARINE)$(_BOLD)🧹 libft Cleaned the mess 🧹$(_END)"

re:		fclean all

gmk:
		@if [ -d make ];then echo ok;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SOURCES += /' > make/sources.mk
		@find -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk

.PHONY: all clean fclean re%
