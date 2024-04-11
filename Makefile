NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

LIBFT_DIR		= libft
LIBFT_FLAGS		= -lft -L $(LIBFT_DIR)

INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) -I$(LIBFT_DIR) 
INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) $(LIBFT_DIR)/libft.h 

SRCS_DIR		= src
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CHECKER_NAME	= checker
CHECKER_DIR		= checker_bonus
CHECKER_SRCS	= $(wildcard $(CHECKER_DIR)/$(SRCS_DIR)/*.c)
CHECKER_FLAG 	= -I$(CHECKER_DIR)/$(INCLUDES_DIR) -I$(LIBFT_DIR) 
CHECKER_INCLUDE	= $(wildcard $(CHECKER_DIR)/$(INCLUDES_DIR)/*.h) $(LIBFT_DIR)/libft.h 

OBJS_DIR_BONUS	= objs_bonus
OBJS_BONUS		= $(patsubst $(CHECKER_DIR)/$(SRCS_DIR)/%.c, $(OBJS_DIR_BONUS)/%.o, $(CHECKER_SRCS))

MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)
	@echo $(GREEN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS)  -o $(NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(RED) " - Main Part Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) " - Main Part Full Cleaned!" $(RESET)

re: fclean all

bonus : $(CHECKER_NAME)

$(CHECKER_NAME) : $(OBJS_BONUS)
	@echo $(GREEN) " - Compiling $(CHECKER_NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(CHECKER_NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR_BONUS)/%.o : $(CHECKER_DIR)/$(SRCS_DIR)/%.c $(CHECKER_INCLUDE) | $(OBJS_DIR_BONUS)
	@$(CC) $(CFLAGS) $(CHECKER_FLAG) -c $< -o $@

$(OBJS_DIR_BONUS) :
	@$(MKDIR) $(OBJS_DIR_BONUS)

clean_bonus :
	@$(RM) $(OBJS_DIR_BONUS)
	@echo $(RED) " - Bonus Part Cleaned!" $(RESET)

fclean_bonus : clean_bonus
	@$(RM) $(CHECKER_NAME)
	@echo $(RED) " - Bonus Part Full Cleaned!" $(RESET)

re_bonus : fclean_bonus bonus

fclean_all : fclean fclean_bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus fclean_all