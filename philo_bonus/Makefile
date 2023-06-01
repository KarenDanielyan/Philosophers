NAME		=	philo_bonus

INCLUDE		=	./include

BUILD		=	./build

SRC			=	./src

DEP			=	$(patsubst %.h, $(INCLUDE)/%.h,\
				defines_bonus.h \
				philo_bonus.h) Makefile

SRCS		=	$(patsubst %.c, $(SRC)/%.c,\
				utils_bonus.c utils_2_bonus.c \
				parse_bonus.c parse_2_bonus.c \
				init_bonus.c philo_bonus.c \
				launch_bonus.c main_bonus.c)

OBJS		=	$(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g

LFLAGS		=	-lpthread

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
