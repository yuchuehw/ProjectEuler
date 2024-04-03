import fractions
answer = 0
i = fractions.Fraction(1,2)
for x in range(1000):
    i = fractions.Fraction(1,i+2)
    n = i + 1
    answer += 1 if len(str(n.numerator))>len(str(n.denominator))else 0
print(answer)
