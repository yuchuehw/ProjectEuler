ones = ["","one","two","three","four","five","six","seven","eight","nine"]
teens = ["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
tens = ["","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

answer = 0

for i in range(1,1000):
    ten,one = divmod(i,10)
    hundred,ten = divmod(ten,10)
    if hundred:
        answer += len(ones[hundred])
        answer += len("hundred")
        if ten or one:
            answer += len("and")
    if ten == 1:
        answer+= len(teens[one])
        continue
    answer += len(tens[ten])
    answer += len(ones[one])
    
answer += len("onethousand")
print(answer)
