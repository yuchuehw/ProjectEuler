K = 5000
l=[n*(3*n-1)//2 for n in range(1,K)]
s = set(l)

answer = float('inf')
for m in range(K-2,-1,-1):
    for n in range(m-1):
        l_n = l[n]
        l_m = l[m]
        if l_m-l_n in s and l_m+l_n in s:
            answer = min(answer,l_m-l_n)
print(answer)
