''' helloworld.py:

    Hello World for Python. Illustrates doctest.

    >>> hello()
    Hello, world!
'''

def hello():
    print "Hello, world!"

import doctest
doctest.testmod()


