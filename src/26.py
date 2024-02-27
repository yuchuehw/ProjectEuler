STOP=1000
max_=(-1,0)
for j in range(1,STOP):
	i =1;i,J=divmod(i,j);l=[0];L=[str(i)];i=J
	if i:l+=[0];L+=["."]
	while i:
		i*=10
		if i in l:L.insert(l.index(i),"(");i=0
		elif i>=j:l+=[i];i,J=divmod(i,j);L+=[str(i)];i=J
		else:l+=[i];L+=['0']
	max_=max(max_,(len(L)-L.index("("),j))if"("in L else max_
print(max_[1])
