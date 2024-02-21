import math
TARGET = 100
print(sum([int(c) for c in str(math.factorial(TARGET))]))


####### ALTERNATIVE #######
# from functools import cache
# TARGET = 100
# @cache
# def factorial(i):
#     if i ==0:return 1
#     return i*factorial(i-1)

# print(sum([int(c) for c in str(factorial(TARGET))]))
