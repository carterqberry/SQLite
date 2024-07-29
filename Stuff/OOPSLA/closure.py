def f(n):
    def g(x):
        print vars()
        return x+n
    print g(1)  # 6     {'x': 1, 'n': 5}
    n = 10
    print g(1)  # 11    {'x': 1, 'n': 10}
    return g

h = f(5)
print h(1)      # 11    {'x': 1, 'n': 10}

