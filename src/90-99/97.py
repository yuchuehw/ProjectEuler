import math
# find the last K_decimal digit of A * 2**B +1
A = 28433
B = 7830457
K_DECI = 10

# let's do it in binary first.
K_BIN = int(math.log2(10**K_DECI))+1

binary_equivlent = [int(i) for i in bin(A)[2:]] + [0]*(B-1) + [1]

mod_value = 10**(K_DECI)

a = 0

for i,v in enumerate(reversed(binary_equivlent)):
    if v:
        a += ((2**i)%mod_value)
print(a%mod_value)
