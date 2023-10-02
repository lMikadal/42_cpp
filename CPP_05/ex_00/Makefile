NAME	= Bureaucrat
CPP		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

HEAD		= -I./Bureaucrat.hpp
BUILD_DIR	= ./build/
SRC_DIR		= ./

SRCS	= $(wildcard *.cpp)
OBJS 	= $(patsubst %.cpp,$(BUILD_DIR)%.o,$(SRCS))

$(BUILD_DIR)/%.o: $(SRCS)%.cpp $(HEAD)
	mkdir -p $(BUILD_DIR)
	$(CPP) $(HEAD) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(BUILD_DIR)/$(SRCS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re