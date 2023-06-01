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

CFLAGS		=	-Wall -Wextra -Werror #-g -fsanitize=thread

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
				@echo	"${GREEN}Building philo...${RESET}"
				@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)
				@echo	"${GREEN}Build Successfull.${RESET}"

clean:
				@echo "${YELLOW}Cleaning Build...${RESET}"
				@$(RM) $(BUILD)
				@echo "${YELLOW}Done.${RESET}"

fclean:
				@echo "${RED}Cleaning Everyting...${RESET}"
				@$(RM) $(BUILD)
				@$(RM) $(NAME)
				@echo "${RED}Done.${RESET}"

re:			fclean $(NAME)

.PHONY:		all clean fclean re
