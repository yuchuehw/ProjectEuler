K = 10_001
print([i for i in range(1_000_000) if i%2 and all(i%j for j in range(3,int(i**0.5)+1,2))][K-1])
