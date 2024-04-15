from functools import cache

def count_permutation(m):
    @cache
    def aux(n, max_num):
        print(n, max_num)
        if max_num < 1:
            return 0
        if n <= 1:
            return 1
        if n < max_num:
            return aux(n, n)
        return aux(n - max_num, max_num) + aux(n, max_num-1)
    
    return aux(m,m-1)

print(count_permutation(5))
