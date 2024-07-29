class Counted(object):
    __count = 0
    def __init__(self):
        Counted.__count += 1
    @staticmethod
    def getCount():     # Note no "self"
        return Counted.__count

print Counted._Counted__count
print Counted.__count

