POWER=5
print(sum(i for i in range(2,1000000)if i==sum([int(d)**POWER for d in str(i)])))
