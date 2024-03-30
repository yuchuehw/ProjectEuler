l = [[1],[1,1],[1,2,1]]
for i in range(3,101):
    l.append([1]+[l[i-1][j]+l[i-1][j+1] for j in range(i-1)]+[1])
print(sum(sum(n > 1_000_000 for n in row) for row in l))
