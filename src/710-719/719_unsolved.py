MAX = 1e4

def split_str(s, t):
    if s:
        yield from split_str(s[1:], t + [s[0]])
        if t:
            yield from split_str(s[1:], t[:-1] + [t[-1] + s[0]])
    else:
        yield t

answer = 0
i=0

while i*i<=MAX:
    n=i*i
    for j in split_str(str(n),[]):
        if len(j) < 2:
            continue
        if sum(int(_)for _ in j) == i:
            answer += n
            break
    i+=1

print(answer)
