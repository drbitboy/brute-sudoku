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
  742935168 (duplicate)
  165428397
  938167254
  629581473 (duplicate)
  354792681 (duplicate)
  817643925 (duplicate)
  293854716 (duplicate)
  481276539
  576319842


Solution:
  742935168 (duplicate)
  165428397 (duplicate)
  938167254 (duplicate)
  629581473 (duplicate)
  354792681 (duplicate)
  817643925 (duplicate)
  293874516
  481256739
  576319842 (duplicate)


Solution:
  742935168 (duplicate)
  165428397 (duplicate)
  938176254
  629581473 (duplicate)
  354792681 (duplicate)
  817643925 (duplicate)
  293854716 (duplicate)
  481267539
  576319842 (duplicate)


Solution:
  742935168 (duplicate)
  165428397 (duplicate)
  938176254 (duplicate)
  629581473 (duplicate)
  354792681 (duplicate)
  817643925 (duplicate)
  293854716 (duplicate)
  486217539
  571369842 (duplicate)


Solution:
  742935168 (duplicate)
  165428793
  938167254 (duplicate)
  329581476
  654792381
  817643925 (duplicate)
  293854617
  481276539 (duplicate)
  576319842 (duplicate)


Solution:
  742935168 (duplicate)
  165428793 (duplicate)
  938176254 (duplicate)
  329581476 (duplicate)
  456792381
  817643925 (duplicate)
  293854617 (duplicate)
  684217539
  571369842 (duplicate)


Solution:
  742935168 (duplicate)
  165428793 (duplicate)
  938176254 (duplicate)
  329581476 (duplicate)
  654792381 (duplicate)
  817643925 (duplicate)
  293854617 (duplicate)
  481267539 (duplicate)
  576319842 (duplicate)


Solution:
  742935168 (duplicate)
  165428793 (duplicate)
  938176254 (duplicate)
  329581476 (duplicate)
  654792381 (duplicate)
  817643925 (duplicate)
  293854617 (duplicate)
  486217539 (duplicate)
  571369842 (duplicate)


Solution:
  742935168 (duplicate)
  165428793 (duplicate)
  938176254 (duplicate)
  329581476 (duplicate)
  654792381 (duplicate)
  817643925 (duplicate)
  293864517
  481257639
  576319842 (duplicate)


Solution:
  742935168 (duplicate)
  169428537
  835671294
  928516473
  354792681 (duplicate)
  617843925 (duplicate)
  293184756 (duplicate)
  486257319
  571369842 (duplicate)


Solution:
  749125368
  126438597
  385976214
  932581476
  654792183
  817643925 (duplicate)
  293864751
  461257839
  578319642


Solution:
  749125368 (duplicate)
  126438597 (duplicate)
  835967214
  982516473
  354792186
  617843925 (duplicate)
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
  461257839 (duplicate)
  578319642 (duplicate)


Solution:
  749125368 (duplicate)
  132468597
  865937214
  928516473 (duplicate)
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
  571369842 (duplicate)


Solution:
  749125368 (duplicate)
  132648597 (duplicate)
  865937214 (duplicate)
  928516473 (duplicate)
  354792681 (duplicate)
  617483925 (duplicate)
  293874156
  486251739 (duplicate)
  571369842 (duplicate)


Solution:
  749125368 (duplicate)
  132648597 (duplicate)
  865937214 (duplicate)
  928561473
  354792186 (duplicate)
  617483925 (duplicate)
  293874651 (duplicate)
  481256739 (duplicate)
  576319842 (duplicate)


Solution:
  749125368 (duplicate)
  132648597 (duplicate)
  865937214 (duplicate)
  928561473 (duplicate)
  354792681 (duplicate)
  617483925 (duplicate)
  293874156 (duplicate)
  481256739 (duplicate)
  576319842 (duplicate)


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
  481257639 (duplicate)
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

