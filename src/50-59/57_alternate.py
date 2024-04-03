from math import log10
answer = 0
numerator=1
denominator=2

for i in range(1000):
    numerator+=2*denominator
    numerator,denominator = denominator,numerator
    n = numerator+denominator
    d = denominator
    answer += int(log10(n))-int(log10(d))

print(answer)
