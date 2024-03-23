DIGIT_TO_KEEP = 11

def multiply_numbers(a: list, b: list, c: list, digit: int) -> None:
    """
    Multiply two numbers represented as lists 'a' and 'b' and store the result in list 'c', disregarding all digits beyond the 'digit' limit.
    """
    for i1, v1 in enumerate(a):
        carry = 0
        for i2, v2 in enumerate(b):
            if i1 + i2 >= digit:
                continue
            carry, c[i1 + i2] = divmod(v1 * v2 + carry + c[i1 + i2], 10)
        if i1 + i2 + 1 < digit and carry:
            c[i1 + i2 + 1] = carry
        
def add_numbers(a: list, b: list, digit: int) -> None:
    """
    Add two numbers represented as lists 'a' and 'b', disregarding all digits beyond the 'digit' limit.
    """
    carry = 0
    for i in range(digit):
        carry, b[i] = divmod(b[i] + a[i] + carry, 10)
    

result = [0] * DIGIT_TO_KEEP

for i in range(1, 1001):
    n = i
    a = [0] * DIGIT_TO_KEEP
    b = [0] * DIGIT_TO_KEEP
    c = [0] * DIGIT_TO_KEEP
    for j in range(4):
        a[j] = b[j] = c[j] = n % 10
        n //= 10
    for j in range(i - 1):
        a = c
        c = [0] * DIGIT_TO_KEEP
        multiply_numbers(a, b, c, DIGIT_TO_KEEP)
    add_numbers(c, result, DIGIT_TO_KEEP)

print(*result[-2::-1], sep="")
