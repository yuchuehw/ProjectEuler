import math

# Function to check if two numbers share a common digit
def share_common_digit(num1, num2):
    num1_digits = set(str(num1))
    num2_digits = set(str(num2))
    return bool(num1_digits.intersection(num2_digits))

# Function to simplify fractions
def simplify_fraction(numerator, denominator):
    gcd = math.gcd(numerator, denominator)
    return numerator // gcd, denominator // gcd

# Initialize numerator and denominator product
numerator_product = 1
denominator_product = 1

# Iterate through possible fractions
for numerator in range(10, 100):
    for denominator in range(numerator + 1, 100):  # Start denominator from numerator + 1
        if numerator % 10 == 0 and denominator % 10 == 0:
            continue  # Skip fractions where both numerator and denominator end in 0
        if numerator / denominator >= 1:
            continue  # Skip fractions where numerator is greater than or equal to denominator

        if share_common_digit(numerator, denominator):
            # Remove common digits
            numerator_digits = [digit for digit in str(numerator) if digit not in str(denominator)]
            denominator_digits = [digit for digit in str(denominator) if digit not in str(numerator)]

            if len(numerator_digits) == 0 or len(denominator_digits) == 0:
                continue
            # Convert back to integer
            new_numerator = int(''.join(numerator_digits))
            new_denominator = int(''.join(denominator_digits))

            # Check if the simplified fraction is equal to the original fraction
            if new_denominator != 0 and new_numerator / new_denominator == numerator / denominator:
                print("found:", numerator, "/", denominator)
                numerator_product *= numerator
                denominator_product *= denominator

# Simplify the final product
numerator_product, denominator_product = simplify_fraction(numerator_product, denominator_product)
print("prod:", numerator_product, "/", denominator_product)
