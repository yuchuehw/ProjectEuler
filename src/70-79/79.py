log = 319,680,180,690,129,620,762,689,762,318,368,710,720,710,629,168,160,689,716,731,736,729,316,729,729,710,769,290,719,680,318,389,162,289,162,718,729,319,790,680,890,362,319,760,316,729,380,319,728,716

d = {i:set() for i in range(10)}
seen = []

for i in log:
    a,b,c = [int(_) for _ in str(i)]
    d[a].add(b)
    d[a].add(c)
    d[b].add(b)
    seen += [a,b,c]

for k in list(d.keys()):
    if k not in seen:
        del d[k]

print("".join([str(i) for _,i in sorted(zip(list(d.values()),list(d.keys())),reverse=True)]))
