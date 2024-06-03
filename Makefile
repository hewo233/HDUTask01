# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall -g

# 定义源文件和目标文件
SRC_DIR = src
TARGET = cafe
SRCS = $(SRC_DIR)/cafe.c
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译源文件生成目标文件
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 清理生成的文件
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

.PHONY: all clean
