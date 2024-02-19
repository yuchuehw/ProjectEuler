LIMIT = int(1e6)

def collatz(n, cache={}):# cache act as a static variable here.
    if n == 1:
        return 1
    if n not in cache:
        cache[n] = 1 + (collatz(3 * n + 1)if n % 2 else collatz(n // 2))
    return cache[n]

max_pair = max(((collatz(x), x) for x in range(LIMIT // 2, LIMIT)))
print(max_pair[1])

