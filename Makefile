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
				  
CHECKER_NAME	= checker
CHECKER_DIR		= checker_bonus
CHECKER_SRCS	= $(wildcard $(CHECKER_DIR)/$(SRCS_DIR)/*.c)
CHECKER_FLAG 	= -I$(CHECKER_DIR)/$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes
CHECKER_INCLUDE	= $(wildcard $(CHECKER_DIR)/$(INCLUDES_DIR)/*.h) $(LIBFT_DIR)/libft.h \
				   $(FT_PRINTF_DIR)/includes/ft_printf.h

OBJS_DIR_BONUS	= objs_bonus
OBJS_BONUS		= $(patsubst $(CHECKER_DIR)/$(SRCS_DIR)/%.c, $(OBJS_DIR_BONUS)/%.o, $(CHECKER_SRCS))

bonus : $(CHECKER_NAME)

$(CHECKER_NAME) : $(OBJS_BONUS)
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)
	@echo $(CYAN) " - Making printf..." $(RESET)
	@$(MAKE) $(FT_PRINTF_DIR)
	@echo $(YELLOW) " - Made printf!" $(RESET)
	@echo $(GREEN) " - Compiling $(CHECKER_NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(CHECKER_NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR_BONUS)/%.o : $(CHECKER_DIR)/$(SRCS_DIR)/%.c $(CHECKER_INCLUDE) | $(OBJS_DIR_BONUS)
	@$(CC) $(CFLAGS) $(CHECKER_FLAG) -c $< -o $@

$(OBJS_DIR_BONUS) :
	@$(MKDIR) $(OBJS_DIR_BONUS)

LIBFT_DIR	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
LINKER 		+= -lft -L $(LIBFT_DIR)

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

clean_bonus :
	@$(RM) $(OBJS_DIR_BONUS)
	@echo $(RED) " - Bonus Part Cleaned!" $(RESET)

fclean_bonus : clean_bonus
	@$(RM) $(CHECKER_NAME)
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(FT_PRINTF_DIR) fclean
	@echo $(RED) " - Bonus Part Full Cleaned!" $(RESET)

re_bonus : fclean_bonus bonus

fclean_all : fclean fclean_bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus fclean_all