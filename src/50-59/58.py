RUN = 10000
TARGET  = 0.1

i = 1
m = 1
n = 1

prime_count = 0
total_count = 0

answer = -1

def isprime(n):
    return n>1 and all(n%i for i in range(2,int(n**0.5)+1))

x = -1
while True:
    x+=1
    for y in range(4):
        i=i+n
        total_count += 1
        if y == 0:
            prime_count += 1 if isprime(i-1) else 0
            # print(prime_count/total_count,x)
            if prime_count and prime_count/total_count<TARGET:
                print(x*2+1)
                exit()
                
        else:
            prime_count += 1 if isprime(i) else 0
        
        m,n=(m-1,n)if m else(1,n+1)
