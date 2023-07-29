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
		@echo "\n🧞$(B_GREEN) Libft's genie is ready to grant your wishes $(C_END)🧞"

all:	${NAME}

.objs/%.o:	%.c
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} -c $< -o $@ ${INC}
		@printf "$(C_PINK)🪔 Rubbing the magic lamp... %-50s \r" $@

${OBJFLDR}:
		@mkdir -p ${OBJFLDR}
		@echo "$(B_BLUE)libft: .obj/ folder created$(C_END)"

clean:
		@${DEL} ${OBJFLDR}
		@echo "$(C_YELLOW)libft: Binary files deleted$(C_END)"

fclean: clean
		@${DEL} ${NAME}
		@echo "$(C_YELLOW)libft: Object files & folders deleted$(C_END)"
		@echo "$(B_YELLOW)🧹 libft Cleaned the mess 🧹$(C_END)"

re:		fclean all

gmk:
		@if [ -d make ];then echo ok;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SOURCES += /' > make/sources.mk
		@find -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk

.PHONY: all clean fclean re%
