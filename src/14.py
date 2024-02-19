from functools import cache

LIMIT = int(1e6)


@cache
def collatz(n):
    if n == 1:
        return 1
    return 1 + (collatz(3 * n + 1) if n % 2 else collatz(n // 2))


max_pair = max(((collatz(x), x) for x in range(LIMIT // 2, LIMIT)))
print(max_pair[1])
