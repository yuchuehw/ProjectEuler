N = 10_000
l = [1]*N
s = 0
for i in range(N):
    j = l[i] = sum([1]+[j for j in range(2,i) if i%j==0])
    if j<i and l[j] == i:
        s+=i+j
print(s)
