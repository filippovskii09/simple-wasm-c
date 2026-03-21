CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
TARGET = ./build/main

.PHONY: run clean wasm

run-strong: src/main.c
	mkdir -p ./build
	$(CC) $(CFLAGS) src/main.c src/cJSON.c -Iinclude -o $(TARGET)
	$(TARGET)

run: src/main.c
	mkdir -p ./build
	$(CC) src/main.c src/cJSON.c -Iinclude -o $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)

wasm:
	emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' src/main.c src/cJSON.c -Iinclude -o ./www/main.js

lint:
	/opt/homebrew/opt/llvm/bin/clang-tidy src/main.c -- -Iinclude -isysroot $(shell xcrun --show-sdk-path)
