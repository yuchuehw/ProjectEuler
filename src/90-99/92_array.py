answer = 0
K = 10_000_001

seen = [0]*K

seen[1] = 1
seen[89] = 89

for i in range(1,10_000_001):
    l = [i]
    while seen[l[-1]] != 1:
        l.append(sum(int(j)**2 for j in str(l[-1])))
        if seen[l[-1]] == 89:
            for i in l:seen[i]=89
            answer += 1
            break
    else:
        for i in l:seen[i]=1

print(answer)
