import math
print(sum(i for i in range(3,100000) if sum(math.factorial(int(d))for d in str(i))==i))
