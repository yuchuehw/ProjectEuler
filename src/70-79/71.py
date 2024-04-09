from fractions import *
print(sorted({Fraction(d*3//7,d)for d in range(1,1000001)})[-2])
