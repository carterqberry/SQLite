def trace(f):
    def wrapper(*args1, **args2):
        print f.__name__,'with',args1,args2
        return f(*args1, **args2)
    return wrapper

@trace
def foo(parm):
    print parm

@trace
def bar(parm1, parm2):
    print parm1, parm2

foo(1)
bar(2,3)
foo(parm=4)
bar(5,parm2=6)

def announce(f):
    def wrapper(*args1, **args2):
        print 'Calling',
        return f(*args1, **args2)
    return wrapper

@announce
@trace
def foo2(parm):
    print parm

@announce
@trace
def bar2(parm1, parm2):
    print parm1, parm2

foo2(1)
bar2(2,3)
foo2(parm=4)
bar2(5,parm2=6)

