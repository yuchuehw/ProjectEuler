max_=-1

for i in range(10000):
    s = ""
    for j in range(1,10):
        prev = s
        s+=str(i*j)
        if "0" in s or len(set(s)) != len(s):
            if j > 2 and len(prev)==9:
                max_ = max(max_,int(prev))        
            break

print(max_)
