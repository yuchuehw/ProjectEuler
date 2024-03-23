STOP=1000
max_=(-1,-1)
for j in range(1,STOP):
	i=1%j
	l=[0]*j
	while l[i]==0:
		l[i]=1
		i*=10
		i=i%j if i>=j else i
	max_=max(max_,(sum(l),j))
print(max_[1])
