import multiprocessing
A_RANGE=range(-1000,1001)
B_RANGE=range(-1000,1001)

def max_n(n,a,b):
    x=n**2 + a * n + b
    if x<2 or x%2<1 or any(x%i==0 for i in range(3, int(x**0.5)+1, 2)):
        return 0
    return 1+max_n(n+1,a,b)

def find_a_b(args):
    a, b_range = args
    return max((max_n(0,a,b),a,b)for b in b_range)
    
if __name__ == '__main__':
    with multiprocessing.Pool() as pool:
        results = pool.map_async(find_a_b, [(a, B_RANGE) for a in A_RANGE])
        _, i, j = max(results.get())
        print(i*j)
