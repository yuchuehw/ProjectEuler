# Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
# 1,2,3,5,8,13,21,34,55,89,...
# By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
s,i,j=0,1,2 
while i<4e6:
    s+=0 if i%2 else i
    i,j=j,i+j
print(s) # 4613732