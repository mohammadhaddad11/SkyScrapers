*This activity has been created as part of the 42 curriculum by mhaddad.*

# Skyscrapers (Rush 01)

## Description

Skyscrapers is a **4 × 4 logic puzzle solver** written in C for the 42 School Rush 01 exercise. The goal is to fill a grid with building heights from **1 to 4**, so that:

- Each row contains every height exactly once.
- Each column contains every height exactly once.
- The number of visible buildings from each side matches its clue.

A taller building hides any shorter building behind it. For example, looking along `2 1 4 3`, only the buildings of heights `2` and `4` are visible, so the clue is `2`.

The solver uses **recursive backtracking**. It places one number at a time, rejects duplicate heights in the same row or column, and checks all visibility clues after filling the grid. If a complete grid fails, it backtracks and tries another combination.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make` (for the provided Makefile)

### Compilation

From the repository root:

```sh
make
```

This builds an executable called `skyscrapers` with `-Wall -Wextra -Werror`.

To compile directly, without Make:

```sh
cc -Wall -Wextra -Werror ex00/*.c -o skyscrapers
```

### Execution

Provide **one quoted command-line argument** containing 16 clues (values from `1` through `4`), in this order:

1. Four clues from the **top**, left to right.
2. Four clues from the **bottom**, left to right.
3. Four clues from the **left**, top to bottom.
4. Four clues from the **right**, top to bottom.

Example:

```sh
./skyscrapers "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Output:

```text
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

For an invalid number of parsed clues or a puzzle with no solution, the program prints `Error`.

### Makefile rules

| Command | Description |
| --- | --- |
| `make` / `make all` | Compile the solver |
| `make clean` | Delete object files |
| `make fclean` | Delete object files and the executable |
| `make re` | Rebuild from scratch |

## Algorithm and Technical Choices

### 1. Backtracking

The function `solve()` explores the grid in row-major order. For each empty cell, it tries values `1` to `4`. When a value is valid for the current row and column, recursion moves to the next cell. If a branch cannot produce a solution, the cell is reset to `0` and the next candidate is tried.

### 2. Row and column constraints

`is_valid()` prevents placing a height already present in the same row or column. This prunes many invalid partial grids before a full solution is constructed.

### 3. Visibility (field of view)

`fov()` scans four heights from one direction, tracking the tallest height seen so far. Every new maximum represents another visible building. `check_row()`, `check_column()`, and `clue()` compare these counts to the 16 input clues.

### 4. Full-grid validation

Visibility clues are checked **only when the complete grid is filled**. The current solver does not use partial visibility clues for pruning, and it stops after finding the **first valid solution**; it does not check whether the puzzle has a unique solution.

## Project Structure

```text
skyscrapers/
├── ex00/
│   ├── clues.c         # Check clues around the completed grid
│   ├── fov.c           # Count buildings visible from a direction
│   ├── main.c          # Parse clues and run the solver
│   ├── print_grid.c    # Print the solved grid
│   ├── skyscrapers.h   # Shared declarations and clue structure
│   ├── solve.c         # Recursive backtracking solver
│   └── validate.c      # Row/column uniqueness checks
├── Makefile
└── README.md
```

## Known Limitations

- The solver is fixed to a **4 × 4** grid.
- The input parser extracts the first 16 characters in the range `1`–`4` rather than strictly validating separators or rejecting trailing text. It should not be treated as a strict format validator.
- Visibility constraints are not used to reject partial boards, which may lead to extra search work.
- The program outputs only one solution, even when multiple solutions exist.

## Resources

- 42 School Rush 01 (Skyscrapers) project instructions
- C manual pages and compiler documentation
- General references on recursion, backtracking, and constraint-satisfaction problems

## AI Usage

AI assistance was used to prepare and verify the **portfolio documentation and build instructions**. The original C implementation from the supplied project archive was preserved unchanged.
