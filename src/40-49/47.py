K = 1_000_000
WINDOW = 4
TARGET = 4

prime = [True]*1_000_000
prime[0]=prime[1]=False

for i in range(2,K):
    if not prime[i]:
        continue
    for j in range(i*i,K,i):
        prime[j] = False

prime_num = [i for i,v in enumerate(prime)if v]

for i in range(K):
    if any(prime[i:i+WINDOW]):
        continue
    for j in range(i,i+WINDOW):
        c=0
        for p in prime_num:
            if j==1:
                break
            c+=1 if j%p==0 else 0
            while j%p==0:
                j//=p
        if c != TARGET:
            break
    else:
        print(i)
        break
