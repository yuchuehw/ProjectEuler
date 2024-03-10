from itertools import permutations

answer = 0
for i in permutations([str(i) for i in range(10)]):
    if i[0] == "0":
        continue
    k = iter([2,3,5,7,11,13,17,19])
    flag = True
    for j in range(1,8):
        if not int("".join(i[j:j+3])) % next(k)==0:
            flag = False
            break
    if flag:
        answer+=int("".join(i))
        
print(answer)
