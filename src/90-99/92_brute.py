answer = 0
for n in range(1,10_000_001):
    i = n
    while i not in (1,89):
        i = sum(int(j)**2 for j in str(i))
        if i == 89:
            answer += 1
print(answer)
