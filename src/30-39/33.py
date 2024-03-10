import math
ns = 1
ds = 1

for n in range(10,100):
    for d in range(10,100):
        if n//d:
            continue
        if n%10==0 and d%10==0:
            continue
        if r:=set(str(n)).intersection(set(str(d))):
            r=r.pop()
            ans1 = n/d
            n2 = int(str(n).replace(r,"",1))
            d2 = int(str(d).replace(r,"",1))
            if d2>0 and n/d==n2/d2:
                print("found:",n,"/",d)
                ns*=n
                ds*=d

ns,ds = ns//math.gcd(ns,ds) ,ds//math.gcd(ns,ds)
print("prod:",ns,"/",ds)
