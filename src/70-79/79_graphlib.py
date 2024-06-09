import graphlib
log = 319,680,180,690,129,620,762,689,762,318,368,710,720,710,629,168,160,689,716,731,736,729,316,729,729,710,769,290,719,680,318,389,162,289,162,718,729,319,790,680,890,362,319,760,316,729,380,319,728,716

G = {_:set() for _ in range(10)}

for i in log:
    a,b,c = [int(_) for _ in str(i)]
    G[c].add(a)
    G[c].add(b)
    G[b].add(a)
    G[a].add(None)

print("".join(str(_) for _ in list(graphlib.TopologicalSorter({k:v for k,v in G.items() if v}).static_order())[1:]))
