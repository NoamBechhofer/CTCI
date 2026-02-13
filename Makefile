# Makefile for CTCI codebase
# Assumes Linux runtime with gcc

CC = gcc
CFLAGS = -Wall \
         -Walloca \
         -Warray-bounds \
         -Wcast-align \
         -Wconversion \
         -Wduplicated-branches \
         -Wduplicated-cond \
         -Werror \
         -Wextra \
         -Wfloat-equal \
         -Wformat-security \
         -Wformat=2 \
         -Wfree-nonheap-object \
         -Wlogical-op \
         -Wmaybe-uninitialized \
         -Wmissing-declarations \
         -Wmissing-prototypes \
         -Wnull-dereference \
         -Wold-style-definition \
         -Wpedantic \
         -Wrestrict \
         -Wredundant-decls \
         -Wshadow \
         -Wsign-conversion \
         -Wstack-protector \
         -Wstrict-prototypes \
         -Wstringop-overflow \
         -Wstringop-truncation \
         -Wswitch-enum \
         -Wswitch-default \
         -Wtrampolines \
         -Wundef \
         -Wuninitialized \
         -Wvla \
         -Wwrite-strings \
         -std=c17 -O2 -g \

LDFLAGS = -lm

# Directories
LIB_DIR = lib
BUILD_DIR = build

# Find all .c files in the repository
LIB_SOURCES = $(wildcard $(LIB_DIR)/*.c)
PROBLEM_SOURCES = $(shell find . -path ./$(LIB_DIR) -prune -o -name '*.c' -print)

# Generate object files
LIB_OBJECTS = $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/$(LIB_DIR)/%.o,$(LIB_SOURCES))

# Find all directories with main.c files (these are executables)
PROBLEM_DIRS = $(patsubst ./%,%,$(dir $(shell find . -path ./$(LIB_DIR) -prune -o -name 'main.c' -print)))
EXECUTABLES = $(patsubst %/,$(BUILD_DIR)/%/problem,$(PROBLEM_DIRS))

# Default target
.PHONY: all
all: $(BUILD_DIR) $(LIB_OBJECTS) $(EXECUTABLES)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(LIB_DIR)

# Compile library object files
$(BUILD_DIR)/$(LIB_DIR)/%.o: $(LIB_DIR)/%.c $(LIB_DIR)/%.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

# Build executables for each problem
$(BUILD_DIR)/%/problem: %/*.c $(LIB_OBJECTS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(dir $<) $^ -o $@ $(LDFLAGS)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Run all executables or a specific one
# Usage: make run          - Run all problems
#        make run 01/01    - Run chapter 01, problem 01
.PHONY: run
run: all
	@# Check if we have arguments to determine chapter/problem
	@if [ -n "$(filter-out run,$(MAKECMDGOALS))" ]; then \
		PROBLEM_PATH="$(filter-out run,$(MAKECMDGOALS))"; \
		EXE="$(BUILD_DIR)/$$PROBLEM_PATH/problem"; \
		if [ -f "$$EXE" ]; then \
			echo "Running $$PROBLEM_PATH..."; \
			echo "\n=== Running $$EXE ==="; \
			$$EXE || exit 1; \
		else \
			echo "Error: Problem $$PROBLEM_PATH not found ($$EXE does not exist)"; \
			exit 1; \
		fi; \
	else \
		echo "Running all problems..."; \
		for exe in $(EXECUTABLES); do \
			echo "\n=== Running $$exe ==="; \
			$$exe || exit 1; \
		done; \
	fi

# Prevent make from treating arguments as targets
%:
	@:

# Help target
.PHONY: help
help:
	@echo "CTCI Makefile"
	@echo "============="
	@echo ""
	@echo "Targets:"
	@echo "  all         - Build all libraries and problem executables (default)"
	@echo "  clean       - Remove all build artifacts"
	@echo "  run         - Build and run all problem executables"
	@echo "  run XX/YY   - Build and run specific problem (chapter XX, problem YY)"
	@echo "  help        - Show this help message"
	@echo ""
