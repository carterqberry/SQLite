class Singleton(object):
    __singletons = {}
    def __new__(cls, *args, **kwds):
        if not cls.__singletons.has_key(cls):
            cls.__singletons[cls] = object.__new__(cls)
        return cls.__singletons[cls]

class Foo(Singleton):
    def __init__(self, x):
        self.x = x

print Foo(10) is Foo(20)

