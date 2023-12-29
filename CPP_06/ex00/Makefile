NAME	= Scalar
CPP		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

HEAD		= -I/*.hpp
SRC_DIR		= ./
BUILD_DIR	= build/

SRCS	= $(shell find . -name '*.cpp')
TMP		= $(subst $(SRC_DIR), $(BUILD_DIR), $(SRCS))
OBJS 	= $(patsubst %.cpp,%.o,$(TMP))

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $(BUILD_DIR))
	$(CPP) $(FLAGS) $(HEAD) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re