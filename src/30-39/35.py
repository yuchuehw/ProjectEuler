LIMIT = 1_000_000
primes={str(i)for i in range(2,LIMIT)if all(i%j for j in range(2,int(i**0.5)+1))}
print(len([prime for prime in primes if all(rot in primes for rot in[prime[i:]+prime[:i]for i in range(len(prime))])]))
