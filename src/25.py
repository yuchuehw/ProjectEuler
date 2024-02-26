k=1000
n=i=j=1
while len(str(i))<k:
    i,j=j,i+j
    n+=1
print(n)
