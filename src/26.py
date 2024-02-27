max_num=-1
max_ = -1
for j in range(1,1000):
	i =1;i,J=divmod(i,j);l=[0];L=[str(i)];i=J
	if i:l+=[0];L+=["."]
	while i:
		i*=10
		if i in l:L.insert(l.index(i),"(");i=0
		elif i>=j:l+=[i];i,J=divmod(i,j);L+=[str(i)];i=J
		else:l+=[i];L+=['0']
	if "(" in L:
	    if max_<len(L)-L.index("("):
	        max_=len(L)-L.index("(")
	        max_num=j
print(max_num)
