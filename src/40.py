from functools import *
MAX = 6

s = "".join((str(i) for i in range(10**MAX)))
print(reduce(lambda x,y:x*y,[int(s[10**i]) for i in range(MAX)]))
