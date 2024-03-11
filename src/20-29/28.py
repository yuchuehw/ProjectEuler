import numpy as np
SIZE = 1001
assert SIZE%2
g=[[0]*SIZE for i in range(SIZE)]

p = (SIZE//2,)*2

i = 0

g[p[0]][p[0]] = (i:=i+1)
m = 1
n = 1
for dy,dx in ((0,1),(1,0),(0,-1),(-1,0))*((SIZE-1)//2):
    for _ in range(n):
        p=(p[0]+dy,p[1]+dx)
        g[p[0]][p[1]] = (i:=i+1)
    m,n=(m-1,n)if m else(1,n+1)

i = SIZE*SIZE+1
for j in range(SIZE-1,-1,-1):
    g[0][j] = (i:=i-1)

g = np.array(g)
print(g)
print(sum(np.diag(g[:,::-1])+np.diag(g))-g[SIZE//2][SIZE//2])
