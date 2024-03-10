from itertools import permutations
K = 9
print("".join([p for j in range(1,K+1) for p in permutations((str(i) for i in range(1,j+1)),j)if all(int("".join(p))%k for k in range(2,int(int("".join(p))**0.5)))][-1]))
