K = 1001

assert K%2

i = 1
m = 1
n = 1

answer = K*K

for x in range((K-1)//2):
    for y in range(4):
        i=i+n
        if y == 0:
            answer += i-1
        else:
            answer += i
        
        m,n=(m-1,n)if m else(1,n+1)

print(answer)
