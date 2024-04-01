def is_lychrel(n, max_iterations=50):
    for _ in range(max_iterations):
        n += int(str(n)[::-1])
        if str(n) == str(n)[::-1]:
            return False
    return True

print(len([i for i in range(10_001) if is_lychrel(i)]))
