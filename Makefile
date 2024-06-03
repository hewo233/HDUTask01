# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall -g

# 定义源文件和目标文件
SRC_DIR = src
TARGET = cafe
SRCS = $(SRC_DIR)/cafe.c

# 默认目标
all: $(TARGET)

# 链接并编译源文件生成可执行文件
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# 清理生成的文件
clean:
	rm -f $(TARGET)

.PHONY: all clean
