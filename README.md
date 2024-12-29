# Brute-force 3x3x3x3 sudoku solver
* Finds all possible solutions

See Makefile also

## Primary result is that sudoku intial problem in bena.sud is under-constrained and has twenty-three valid solutions:
* Source image:  ![](https://github.com/drbitboy/brute-sudoku/raw/master/IMG_20241222_193425.jpg)
```
Input:
  74...5.68
  1....8...
  ......2.4
  ...5..47.
  .5.792.8.
  .17..3...
  2.3......
  ...2....9
  57.3...42


Solution:
  742935168
  136428597
  985176234
  629581473
  354792681
  817643925
  293814756
  468257319
  571369842


Solution:
  742935168 (duplicate)
  136428597 (duplicate)
  985176234 (duplicate)
  629581473 (duplicate)
  354792681 (duplicate)
  817643925 (duplicate)
  293854716
  468217359
  571369842 (duplicate)


Solution:
  742935168 (duplicate)
  136428597 (duplicate)
  985671234
  829516473
  354792681 (duplicate)
  617843925
  293184756
  468257319 (duplicate)
  571369842 (duplicate)

Solution:
  ...
  [20 more solutions]
```

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

