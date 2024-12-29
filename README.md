# Brute-force 3x3x3x3 sudoku solver

See Makefile

## Build:
```make```

## Test:
```make test```

## Usage:
```.sud < bena.sud```

## Source file format:
```
74...5.68
1....8...
......2.4
...5..47.
.5.792.86
.17..3...
2.3......
...2....9
57.3...42

where
- digits 1-9 are entry squares with known values
- all other characters, other than whitespace, are entry squares with unknown values
- whitespace (including line terminators) are ignored
```

