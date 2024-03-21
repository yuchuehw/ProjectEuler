K = 2000000
s={0,1}
print(sum({i for i in range(K)}-{i for i in range(K)if i in s or[s.add(j)for j in range(i*i,K,i)]==1}))
