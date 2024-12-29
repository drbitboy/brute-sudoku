"""
Count unique solutions in solutions_bena.txt
"""

if "__main__" == __name__:
  theset = set()
  with open('solutions_bena.txt') as fin:
    expected = 0
    for lyne in fin:
      if not lyne.strip():
        assert not expected
        continue
      token = lyne.strip().split()[0]
      if expected:
        assert 9==len(token)
        solution = solution + (token,)
        expected -= 1
        if not expected:
          theset.add(solution)
      else:
        if 'Solution:' == token:
          solution = tuple()
          expected = 9
  print(len(theset))
