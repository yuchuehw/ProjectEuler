K = 1_000_000
p = [True]*(K+1)
p[0]=p[1]=False
for i in range(K):
    if p[i]:
        for j in range(i*2,K,i):
            p[j] = False

primes_s = {i for i,v in enumerate(p) if v}
primes_l = [_ for _,__ in enumerate(p) if __]

answer = -1
min_ = 0
len_=len(primes_s)

for i in range(len_):
    for j in range(i+min_,len_):
        k=sum(primes_l[i:j])
        if k>=K:
            break
        if k in primes_s:
            print(min_,i,j,k)
            min_ = j-i
            answer = k
print(answer)
