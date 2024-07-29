"scope.py"
a = 1
n = 1

def f(n):
    print 'In f, a =', a, 'and n =', n, vars()

f(10)
print vars()

