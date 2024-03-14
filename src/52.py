MULT = 6
for x in range(1,1_000_000):
    target = set(str(x))
    for multiplier in range(2,MULT):
        if set(str(x*multiplier)) != target:
            break
    else:
        print(x)
        break
