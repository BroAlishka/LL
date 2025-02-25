CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -O3

SRCS = llo.cpp pi_calculator.cpp test_long_number.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_EXEC = test_long_number
PI_EXEC = pi_calculator

all: test pi

$(TEST_EXEC): llo.o test_long_number.o
	$(CC) $(CFLAGS) -o $@ $^ -lgtest -lgtest_main -pthread

$(PI_EXEC): llo.o pi_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXEC)
	@echo "Запуск тестов..."
	./$(TEST_EXEC)

pi: $(PI_EXEC)
	@echo "Вычисление числа Пи..."
	./$(PI_EXEC)
clean:
	rm -f $(OBJS) $(TEST_EXEC) $(PI_EXEC)

.PHONY: all test pi clean