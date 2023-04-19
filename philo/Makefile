NAME		=	philo

INCLUDE		=	./include

BUILD		=	./build

SRC			=	./src

DEP			=	

SRCS		=	

OBJS		=	$(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-g3 -Wall -Wextra -Werror -fsanitize=address

LFLAGS		=	

IFLAGS		=	-I./include

$(BUILD)/%.o: $(SRC)/%.c $(DEP)
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
