# A Small Animal Kingdom
class Animal(object):
    def __init__(self, name):
        self.name = name
    def whoAmI(self):
        return self.name

a = Animal('Rocky Raccoon')
print a.whoAmI()

class Dog(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)
    def speak(self):
        print "Bark!"

class Antelope(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)
    def speak(self):
        print "<silent>"

class Basselope(Dog, Antelope):
    def __init__(self, name):
        Animal.__init__(self, name)
#        super(Basselope, self).__init__(name)  # alternative

class Foo:
    data = 'bar'
    def __init__(self,data):
        self.data = data
    def display(self):
        print self.data, Foo.data

foo = Foo('baz')
foo.display()

dog = Dog("Fido")
print dog.whoAmI(),':',
dog.speak()

ant = Antelope("Arnie")
print ant.whoAmI(),':',
ant.speak()

bl = Basselope("Rosebud")
print bl.whoAmI(),':',
bl.speak()


class StaticStuff(object) :
    foo = 1
    @staticmethod
    def bar () :
        return StaticStuff.foo

x = StaticStuff()
print x.foo
print StaticStuff.bar()

class Klass(object) :
    @classmethod
    def cmethod(cls, x):
        print cls.__name__, "got", x

Klass.cmethod(1)
k = Klass()
k.cmethod(2)

class Shape(object):
    __count = 0	# A shared value for Shape classes with no current objects
  	
    @classmethod
    def __incr(cls):
        cls.__count += 1         # Create/update class attribute
      
    @classmethod
    def showCount(cls):
        print 'Class %s has count: %s' % \
          (cls.__name__, cls.__count)
        
    def __init__(self):		# A constructor
        self.__incr()

class Point(Shape): pass	# An empty subclass of Shape
class Line(Shape): pass		# Ditto

p1 = Point()
p2 = Point()
p3 = Point()
Point.showCount()
Line.showCount()
x = Line()
Line.showCount()

class Controlled(object):
    def __init__ (self, x, y):
        self.__x = x
        self.__y = y
    __z = 'zee'
    def display(self):
        print 'x:',self.__x,'y:',self.__y, \
              'z:',Controlled.__z

c = Controlled('ecks', 'why')
c.display()
print dir(c)
#c.__x
print c._Controlled__x

class HasProp(object):
    def setProp (self, p):
        print 'setProp trace'
        self.__prop = p
    def getProp (self):
        print 'getProp trace'
        return self.__prop
    prop = property(getProp, setProp)

x = HasProp()
x.prop = 'theProperty'
print x.prop

muffy = Dog('Muffy')
op = Dog.whoAmI
print op
print op(muffy) # same as muffy.whoAmI()

sheba = Dog('Sheba')
op = sheba.whoAmI
print op
print op()      # same as sheba.whoAmI()

def eat (self, food):
    print self.whoAmI(),'eating',food

Dog.eat = eat   # Add new method to Dog!
muffy.eat('trash')
Dog.eat(muffy, 'bones')

dogs = [muffy, sheba]
food = ['melon', 'bones']
for i in range(2):
    dogs[i].eat(food[i])

pairs = zip(dogs, food)
print pairs
for pair in pairs:
    eat(*pair)

map(muffy.eat, food)
map(Dog.speak,dogs)

class Number(object):
    def __init__(self, num):
        float(num)  # correctness test
        self.__num = num
    def __add__(self, num):
        if (isinstance(num, Number)):
            return Number(self.__num + num.__num)
        return Number(self.__num + float(num))
    def __str__(self):
        return '%g' % self.__num
    def __neg__(self):
        return Number(-self.__num)
    __radd__ = __add__

x = Number(1.2)
y = Number(3.4)
print x,y,-x
print x + y
print x + 2
print 2 + x

class Stuff(object):
    def __init__(self):
        self.__data = []
    def add(self, x):
        self.__data.append(x)
    def __getitem__(self, i):
        return self.__data[i]
    def __setitem__(self, i, x):
        self.__data[i] = x
    def display(self):
        for item in self.__data:
            print item,
        print
    def __len__(self):
        return len(self.__data)

s = Stuff()
s.add(2)
s.add('three')
s.add(4.0)
s.display()
for i in range(len(s)):
    print s[i],
print
s[1] = 'one'
s.display()

for x in s:
    print x,
print
print 'one' in s
print map(None, s)
print list(s)
print tuple(s)

for i,n in enumerate(['a','b','c','d']):
    print i,n

class MoreStuff(object):
    def __init__(self):
        self.__data = []
    def add(self, x):
        self.__data.append(x)
    def __iter__(self):
        self.__pos = 0
        return self
    def next(self):
        if self.__pos == len(self.__data):
            raise StopIteration
        val = self.__data[self.__pos]
        self.__pos += 1
        return val
    def display(self):
        for item in self.__data:
            print item,
        print

s = MoreStuff()
s.add(2)
s.add('three')
s.add(4.0)
s.display()
for x in s:
    print x,
print

class MyMetaClass(type):
    def __str__(cls): return 'Class ' + cls.__name__

class C(object):
    __metaclass__ = MyMetaClass

x = C()
print type(x)

class Getters(type):
    def __new__(cls, name, bases, d):
        for var in d.get('__slots__'):
            def getter(self, v=var):
                return getattr(self, v)
            d['get' + var] = getter
        return type.__new__(cls, name, bases, d)

class G(object):
    def __init__(self, f, b):
        self.foo = f
        self.bar = b
    __metaclass__ = Getters
    __slots__ = ['foo', 'bar']

g = G(1,2)
print g.getfoo(), g.getbar()
print G
print type(G)
print dir(G)

muffy = Dog('Muffy')
sheba = Dog('Sheba')
def boof():
    print 'boof!'
muffy.boof = boof
print muffy.boof
muffy.boof()
#sheba.boof()

m = Line.showCount
print m
m()

class Singleton(object):
    __singletons = {}
    def __new__(cls, *args, **kwds):
        if not Singleton.__singletons.has_key(cls):
            Singleton.__singletons[cls] = object.__new__(cls)
        return Singleton.__singletons[cls]

class Foo(Singleton):
    def __init__(self, x):
        self.x = x

a = Foo(10)
print a.x
b = Foo(20)
print b.x
print a.x

