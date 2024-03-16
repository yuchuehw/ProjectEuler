print([i for i in range(100_000) if all(i%j for j in range(3,int(i**0.5)+1,2))][10001])
