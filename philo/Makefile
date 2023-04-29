NAME		=	philo

INCLUDE		=	./include

BUILD		=	./build

SRC			=	./src

DEP			=	$(patsubst %.h, $(INCLUDE)/%.h,\
				defines.h \
				philo.h) Makefile

SRCS		=	$(patsubst %.c, $(SRC)/%.c,\
				utils.c utils_2.c \
				parse.c parse_2.c \
				init.c philo.c \
				launch.c main.c)

OBJS		=	$(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address

LFLAGS		=	

IFLAGS		=	-I./include

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m

$(BUILD)/%.o: $(SRC)/%.c $(DEP)
				@echo "${YELLOW}Compiling $<.${RESET}"
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all:		$(NAME)

$(BUILD):
				@mkdir -p $(BUILD)

$(NAME):	$(BUILD) $(OBJS)
				@echo	"Building ..."
				@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)
				@echo	"Build Successfull."

clean:
				@echo "Cleaning Build..."
				@$(RM) $(BUILD)
				@echo "Done."

fclean:		clean
				@echo "Cleaning Everyting..."
				@$(RM) $(NAME)
				@$(RM) $(BONUS)
				@echo "Done."

re:			fclean $(NAME)

.PHONY:		all clean fclean re
