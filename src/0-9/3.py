C = 600851475143
c = C
for i in range(2,int(C**0.5)+1):
    if c%i==0 and i%2 and all(i%j for j in range(3,int(i**0.5)+1,2)):
        c//=i
    if(c==1):
        print(i)
        break
