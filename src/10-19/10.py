K = 2000000

is_prime = [True]*(K + 1);
is_prime[0] = is_prime[1] = False

for i,v in enumerate(is_prime):
    if not v:
        continue
    for j in range(i*i,K+1,i):
        is_prime[j]=False

print(sum(i for i,v in enumerate(is_prime)if v))
