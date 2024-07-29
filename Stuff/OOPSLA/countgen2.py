def countgen2(n):
   """An bounded count generator"""   # A doc string
   count = 0
   while count < n:
      count += 1
      yield count
g = countgen2(5)
for x in g: print x


