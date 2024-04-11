from functools import cache

@cache
def is_89_chain(n):
    if n==1:
        return False
    elif n==89:
        return True
    else:
        return is_89_chain(sum(int(_)**2 for _ in str(n)))

answer = 0

for n in range(1,10_000_001):
    answer += is_89_chain(n)

print(answer)
