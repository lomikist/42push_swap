TARGET			= push_swap
CHECKER			= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address
OS				= $(shell uname)
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR)

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h)

SRCS_DIR		= src/
SRC_FILES		= main.c \
				  operations.c \
				  ft_atoi.c \
				  sort.c \
				  utils.c
CHECKER_SRC_FILES	= checker.c \
					  get_next_line.c

#LIBFT
LIBFT_DIR	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
LINKER 		+= -lft -L $(LIBFT_DIR)

# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))
CHECKER_OBJ_FILES	= $(CHECKER_SRC_FILES:.c=.o)
CHECKER_OBJS		= $(addprefix $(OBJS_DIR), $(CHECKER_OBJ_FILES))

all : $(LIBFT) $(OBJS_DIR) $(TARGET) $(CHECKER)

$(LIBFT) :
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(TARGET) : $(OBJS)
	@echo $(GREEN) " - Compiling $(TARGET)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(TARGET)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(CHECKER) : $(CHECKER_OBJS)
	@echo $(GREEN) " - Compiling $(CHECKER)..." $(RESET)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LINKER) -o $(CHECKER)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(TARGET) $(CHECKER)
	@$(MAKE) $(LIBFT_DIR) fclean

re: fclean all
