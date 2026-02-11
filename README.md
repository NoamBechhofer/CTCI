# CTCI

Cracking the Coding Interview - Solutions in C

## Project Structure

```
CTCI/
├── lib/                    # Reusable code
├── XX/YY/                  # Chapter XX, Problem YY
│   ├── problem.h
│   ├── problem.c
│   └── main.c
├── 00/00/                  # Sample problem for testing the build system
├── Makefile                # Top-level Makefile
└── README.md
```

## Building

The project uses a top-level Makefile that compiles all `.c` and `.h` files in the repository.

### Prerequisites
- Linux runtime
- GCC compiler
- Make

### Build Commands

```bash
# Build all problems
make all

# Clean build artifacts
make clean

# Build and run all problems
make run

# Show help
make help
```

## Adding New Problems

To add a new problem:

1. Create a directory: `mkdir -p XX/YY` (where XX is chapter, YY is problem number)
2. Add your files:
   - `problem.h` - Problem interface
   - `problem.c` - Problem implementation
   - `main.c` - Test cases and main function
3. Run `make all` to build
4. Run `make run` to test

The Makefile will automatically discover and build your new problem.

## Library

The `lib/` directory contains reusable data structures and algorithms that can be used across problems. Include them with:

```c
#include "linkedlist.h"  // Example library
```
