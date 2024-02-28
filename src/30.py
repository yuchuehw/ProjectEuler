answer = 0
for i in range(2,1000000):
    answer+=[0,i][sum(int(j)**5 for j in str(i)) == i]
print(answer)
