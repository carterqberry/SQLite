"""
    >>> f()
    one
    two
"""

def f():
    print 'one'
    print 'two'

import doctest
doctest.testmod()
