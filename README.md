# Brute-force 3x3x3x3 sudoku solver
* Finds all possible solutions

See Makefile also

## Primary result is that sudoku intial problem in bena.sud is under-constrained and has seven valid solutions:
* Source image:  ![](https://github.com/drbitboy/brute-sudoku/raw/master/IMG_20241222_193425.jpg)
```
Input:
  74...5.68
  1....8...
  ......2.4
  ...5..47.
  .5.792.86
  .17..3...
  2.3......
  ...2....9
  57.3...42


Solution:
  749125368
  126438597
  835967214
  982516473
  354792186
  617843925
  293674851
  468251739
  571389642


Solution:
  749125368 (duplicate)
  126438597 (duplicate)
  835976214
  982561473
  354792186 (duplicate)
  617843925 (duplicate)
  293684751
  461257839
  578319642


Solution:
  749125368 (duplicate)
  132468597
  865937214
  928516473
  354792186 (duplicate)
  617843925 (duplicate)
  293674851 (duplicate)
  486251739
  571389642 (duplicate)


Solution:
  749125368 (duplicate)
  132648597
  865937214 (duplicate)
  928516473 (duplicate)
  354792186 (duplicate)
  617483925
  293874651
  486251739 (duplicate)
  571369842


Solution:
  749125368 (duplicate)
  132648597 (duplicate)
  865937214 (duplicate)
  928561473
  354792186 (duplicate)
  617483925 (duplicate)
  293874651 (duplicate)
  481256739
  576319842


Solution:
  749125368 (duplicate)
  162438597
  835967214 (duplicate)
  928516473 (duplicate)
  354792186 (duplicate)
  617843925 (duplicate)
  293674851 (duplicate)
  486251739 (duplicate)
  571389642 (duplicate)


Solution:
  749125368 (duplicate)
  162438597 (duplicate)
  835976214 (duplicate)
  928561473 (duplicate)
  354792186 (duplicate)
  617843925 (duplicate)
  293684751 (duplicate)
  481257639
  576319842 (duplicate)

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

