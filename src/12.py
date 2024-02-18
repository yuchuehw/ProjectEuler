TARGET = 500
class P():
    p = [2]
    i = 1
    def primes(self,limit=0):
        while P.p[-1]<=limit:
            P.i+=2
            if all(P.i%j for j in range(2,P.i)):
                P.p.append(P.i)
        return P.p
i = j = 0
while 1:
    j += 1;i += j;num = i;count = 1
    for p in P().primes(num**0.5):
        exponent = 0
        while num % p == 0:
            exponent += 1
            num //= p
        count *= exponent + 1
    if count > TARGET:
        print(i) # 76576500
        break
