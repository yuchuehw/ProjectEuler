from itertools import permutations
KTH_TERM = 1_000_000
p = permutations(range(10),10) # this create a generator object which is efficient and performant
for x in range(KTH_TERM-1):next(p) # ignore the first 999,999 terms.
print("".join([str(c) for c in next(p)])) # print the 1,000,000 term.
