N=10_000
l=[sum(j for j in range(1,i)if i%j==0)for i in range(N)]
print(sum(v for i,v in enumerate(l)if i!=v<N and l[v]==i))
