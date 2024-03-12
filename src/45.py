K = 100000

Pentagonal = {n*(3*n-1)//2 for n in range(1,K)}
Hexagonal = {n*(2*n-1) for n in range(1,K)}

Pen_Hex_intersection = Pentagonal.intersection(Hexagonal)

for tirangle_number in ((n*(n+1))//2 for n in range(1,K)):
    if tirangle_number in Pen_Hex_intersection:
        print(tirangle_number)
