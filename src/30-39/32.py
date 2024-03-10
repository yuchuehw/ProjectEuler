from itertools import combinations
TARGET = set("123456789")
ans=set()

for i,j in combinations((i for i in range(10000)if len(str(i))==len(set(str(i)))),2):
    S = str(i*j)+str(i)+str(j)
    if len(S) == len(TARGET) and set(S) == TARGET:
        print(i,j)
        ans.add(i*j)
print(sum(ans))
