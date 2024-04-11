# find (A * 2**B +1) mod K
A = 28433
B = 7830457
K = 10**10

print(sum(2**(j+B)%K for j,v in enumerate(int(i)for i in bin(A)[:1:-1])if v)%K+1)
