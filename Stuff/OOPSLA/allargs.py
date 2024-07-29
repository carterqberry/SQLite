# allargs.py

def f(*args, **kwargs):
    for arg in args:
        print(arg)
    for key in kwargs:
        print(key, '=', kwargs[key])

f(1,2,t=3,f=4)

# Output:
1
2
t = 3
f = 4

