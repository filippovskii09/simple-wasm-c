CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
TARGET = ./build/main

.PHONY: run clean wasm

run: src/main.c
	mkdir -p ./build
	$(CC) $(CFLAGS) src/main.c -o $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)

wasm:
	emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' src/main.c -o ./www/main.js
