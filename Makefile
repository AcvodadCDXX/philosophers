# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

# Source files
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/simulation.c $(SRC_DIR)/philosopher.c \
       $(SRC_DIR)/monitor.c $(SRC_DIR)/utils.c $(SRC_DIR)/cleanup.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
NAME = philo

# Default rule: compile everything
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create object directory if not existing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean all compiled files
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all
