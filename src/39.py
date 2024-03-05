K = 1000
l=[0]*K
for i in range(1,int(K//2)+1):
    for j in range(1,int(K//2)+1):
        k=(i**2+j**2)**0.5
        if k==int(k) and i+j+k<K:
            l[int(i+j+k)]+=1
print(l.index(max(l)))
