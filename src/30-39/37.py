l = [2]
p = set(" 2")

i = 3
while len(l) < 15:
    if all(i%j for j in range(2, int(i**0.5) + 1)):
        n = str(i)
        p.add(n)
        if all(n[:j] in p and n[j:] in p for j in range(1, len(n))):
            l.append(n)
            print(l)
    i += 2

print(sum(int(i) for i in l)-2-3-5-7)
