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
    if not any(prime[i:i+WINDOW]):
        for j in range(i,i+WINDOW):
            c = 0
            n=j
            for p in prime_num:
                if n%p==0:
                    c+=1
                while n%p==0:
                    n//=p
                if n==1:
                    break
            if c != TARGET:
                break
        else:
            print(i)
            break
        
