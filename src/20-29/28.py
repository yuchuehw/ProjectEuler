import numpy as np
SIZE = 1001
assert SIZE%2
g=[[0]*SIZE for i in range(SIZE)]

p = (SIZE//2,)*2

i = iter(range(1,SIZE**2+1))

g[p[0]][p[0]] =next(i)
m = 1
n = 1
counter = 0
for dy,dx in ((0,1),(1,0),(0,-1),(-1,0))*((SIZE-1)//2):
    for _ in range(n):
        p=(p[0]+dy,p[1]+dx)
        g[p[0]][p[1]] = next(i)
    m,n=(m-1,n)if m else(1,n+1)
    counter += 1

g = np.array(g)
print(sum(np.diag(g[:,::-1])+np.diag(g))-1+SIZE**2)
