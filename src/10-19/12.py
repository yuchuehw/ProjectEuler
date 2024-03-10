TARGET = 500
def primes(limit=0,p=[2,3]): # p act as a static variable here.
    i = p[-1]
    while p[-1]<=limit:
        i+=2
        if all(i%j for j in range(2,i)):
            p.append(i)
    return p
i = j = 0
while 1:
    j += 1;i += j;num = i;count = 1
    for p in primes(num**0.5):
        exponent = 0
        while num % p == 0:
            exponent += 1
            num //= p
        count *= exponent + 1
    if count > TARGET:
        print(i) # 76576500
        break
