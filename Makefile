CC = clang
C_FLAGS_DEBUG = -g -O0 -Wall -Wextra -Iinclude
C_FLAGS_RELEASE = -02 -DNDEBUG -Wall -Wextra -Iinclude
LIBRARY_LINKING = -lraylib -lGL -lm -lpthread -ldl -lrt -lwayland-client

SRC = src/main.c src/padle.c src/ball.c

TARGET = Pong_ping

default:
	$(CC) $(SRC) $(C_FLAGS_DEBUG) -o $(TARGET) \
		$(LIBRARY_LINKING)
debug:
	$(CC) $(SRC) $(C_FLAGS_DEBUG) -o $(TARGET) \
		$(LIBRARY_LINKING)
release:
	$(CC) $(SRC) $(C_FLAGS_RELEASE) -o $(TARGET) \
		$(LIBRARY_LINKING)
clear:
	rm $(TARGET)

