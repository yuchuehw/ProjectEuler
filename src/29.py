A_MIN = 2
A_MAX = 69
B_MIN = 2
B_MAX = 71
print(len({i**j for i in range(A_MIN,A_MAX+1)for j in range(B_MIN,B_MAX+1)}))
