NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -MMD -MP

RM = rm -rf
AR = ar rcs

SRCS := $(shell find src -type f -name "*.c")

OBJS := $(SRCS:src/%.c=objects/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

objects/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) objects

fclean:clean
	@$(RM) $(NAME)

re: fclean all

-Include (OBJS:.o=.d)

# ---------------- TESTS ---------------- #
TEST = tests/main.c
TEST_BIN = test

test: $(NAME)
	bash tests/3tester.sh
# --------------------------------------- #

.PHONY: all clean fclean re