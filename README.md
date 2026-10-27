*This activity has been created as part of the 42 curriculum by mhaddad.*

# Skyscrapers (Rush 02)

## Description

This project is a solver for the 42 School Rush 02 **Skyscrapers** puzzle. It fills a fixed 4 x 4 grid with the building heights `1`, `2`, `3`, and `4`.

Every solution must follow three rules:

1. Every row contains each height exactly once.
2. Every column contains each height exactly once.
3. Each outside clue tells how many buildings can be seen from that side.

A building is visible when it is taller than every building before it in that direction. For example, looking at `2 1 4 3`, the buildings with heights `2` and `4` are visible, so the clue is `2`.

The 16 clues surround the grid like this:

```text
		   top:  1 2 3 4

	   left  ->   4 1 2 3   <-  right
			    2 3 4 1
			    3 4 1 2
			    4 1 2 3

		bottom:  1 2 3 4
```

The command-line argument stores the clues in four groups of four:

```text
top, bottom, left, right
```

Within each group, clues are read left to right for the top and bottom, and top to bottom for the left and right.

## Instructions

### Requirements

- A C compiler named `cc`
- `make`

From this directory, build the executable with:

```sh
make
```

This creates an executable named `skyscrapers`. The compiler is run with `-Wall -Wextra -Werror`.

Run it with one quoted argument containing 16 clues. Each clue must be a digit from `1` to `4`:

```sh
./skyscrapers "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

If the puzzle has a solution, the program prints the completed grid:

```text
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

The program prints `Error` when it does not receive 16 usable clues or when no solution can be found.

### Makefile rules

| Command | Purpose |
| --- | --- |
| `make` or `make all` | Build the solver |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the executable |
| `make re` | Clean and build again |

To compile without the Makefile:

```sh
cc -Wall -Wextra -Werror *.c -o skyscrapers
```

## Algorithm and Technical Choices

### 1. Backtracking

`solve.c` visits the grid from left to right and top to bottom. For each empty cell, it tries heights `1` through `4`. If a choice leads to a dead end, the solver clears that cell and tries the next height. This process is called recursive **backtracking**.

### 2. Row and column constraints

`validate.c` rejects a height if it already appears in the same row or column. This keeps every row and column free of duplicates while the solution is being built.

### 3. Visibility (field of view)

Once the grid is filled, `clues.c` checks visibility from all four sides. `fov.c` scans a row or column and counts each new tallest building.

### 4. Full-grid validation

The solver checks all visibility clues only after every cell is filled. `print_grid.c` prints the first complete grid that satisfies every clue.

Visibility clues are checked only after the grid is full. The solver therefore does not try to reject a partial grid using clues, and it stops after the first solution rather than checking whether the solution is unique.

## Project Structure

```text
Makefile         Build, clean, and rebuild commands
README.md        Project documentation
clues.c          Check all row and column clues
fov.c            Count visible buildings from one direction
main.c           Parse input and start the solver
print_grid.c     Print the completed grid
skyscrapers.h    Shared declarations and clue structure
solve.c          Recursive backtracking algorithm
validate.c       Check row and column uniqueness
```

## Known Limitations

- The grid size is fixed at 4 x 4.
- The input parser looks for the first 16 characters in the range `1`–`4`; separators are not strictly validated.
- Extra text after those 16 digits is ignored.
- Visibility clues are not used for pruning while the grid is being built, which can make the search slower than necessary.
- Only the first valid solution is printed.

## Resources

- 42 School Rush 02 (Skyscrapers) project instructions
- C manual pages and compiler documentation
- General references on recursion, backtracking, and constraint-satisfaction problems

## AI Usage

AI assistance was used to prepare and verify the portfolio documentation and build instructions. The original C implementation was preserved unchanged.
