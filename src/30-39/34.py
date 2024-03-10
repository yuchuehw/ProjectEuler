import math
print(sum(i for i in range(3,50000) if sum(math.factorial(int(d))for d in str(i))==i))
