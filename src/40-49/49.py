D = 4
U = int(10**D)
L = int(10**(D-1))-1

prime = [0]*U
prime[0] = prime[1] = 1

for i,v in enumerate(prime):
    if v:
        continue
    for j in range(i*i,U,i):
        prime[j] = 1

l = [i for i,v in enumerate(prime) if not v and i>L]
s = {i for i in l}


for i in l:
    for j in l:
        if j<=i or set(str(i)) != set(str(j)):
            continue
        
        diff = j-i
        k = j
        flag = True
        
        while k<U:
            k+=diff
            if set(str(i)) != set(str(k)) or k not in s:
                flag=False
                break
            else:
                print(i,j,k)
        # print(i,j)
