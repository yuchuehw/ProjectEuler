LIMIT=28123
s={i for i in range(LIMIT)if i<sum(j for j in range(1,i)if i%j==0)}
print(sum(i for i in range(LIMIT)if any(j for j in s if i-j in s)==0))
