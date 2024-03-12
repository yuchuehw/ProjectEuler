K = 10000
primes = [i for i in range(2,K) if all(i%j for j in range(2,int(i**0.5)+1))]
odd_composite = [i for i in range(3,K,2) if any(i%j==0 for j in range(2,int(i**0.5)+1))]
for i in odd_composite:
    flag = True
    for p in primes:
        if i-p<=0:
            break
        j = ((i-p)//2)**0.5
        if j == int(j):
            flag = False
    if flag:
        print(i)
        # break
