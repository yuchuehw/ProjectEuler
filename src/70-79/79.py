log = 319,680,180,690,129,620,762,689,762,318,368,710,720,710,629,168,160,689,716,731,736,729,316,729,729,710,769,290,719,680,318,389,162,289,162,718,729,319,790,680,890,362,319,760,316,729,380,319,728,716

d = [[0]*10 for i in range(10)]

seen = [0]*10

for i in log:
    a,b,c = [int(_) for _ in str(i)]
    d[a][b] = 1
    d[a][c] = 1
    d[b][c] = 1
    seen[a] = 1
    seen[b] = 1
    seen[c] = 1

d_most = [(sum(v),i) for i,v in enumerate(d)]

d_most.sort(reverse=True)

for i,v in d_most:
    if seen[v]:
        print(v,end="")
