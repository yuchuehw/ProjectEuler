import math
print(sum([int(c) for c in str(math.factorial(100))]))
# from functools import cache

# @cache
# def factorial(i):
#     if i ==0:return 1
#     return i*factorial(i-1)

# print(sum([int(c) for c in str(factorial(100))]))
