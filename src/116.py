# pattern finder
def find_pattern():
    l = [set() for _ in range(15)]
    for i in range(100000):
        for j in range(15):
            s = bin(i)[2:].zfill(j)
            if len(s)<15:
                l[len(s)].add(s)
            
    # print(l)
            
    
    for i,row in enumerate(l):
        total = 0
        for j in row:
            
            if j.count("1") and j.count("1")%2==0 and j.count("11")*2 == j.count("1"):
                # print(j)
                total += 1
        print("#",i, total)
        
    for i,row in enumerate(l):
        total = 0
        for j in row:
            
            if j.count("1") and j.count("1")%3==0 and j.count("111")*3 == j.count("1"):
                # print(j)
                total += 1
        print("#",i, total)
    
    for i,row in enumerate(l):
        total = 0
        for j in row:
            
            if j.count("1") and j.count("1")%4==0 and j.count("1111")*4 == j.count("1"):
                # print(j)
                total += 1
        print("#",i, total)

# v1
def version1():
    l1 = [0,0,1,2]
    l2 = [0,0,0,1,2,3]
    l3 = [0,0,0,0,1,2,3,4]
    
    for x in range(50):
        a,b = l1[-2],l1[-1]
        l1.append(a+b+1)
        a,b,c = l2[-3],l2[-2],l2[-1]
        l2.append(a+c+1)
        a,b,c,d = l3[-4],l3[-3],l3[-2],l3[-1]
        l3.append(a+d+1)
    
    print(l1[50]+l2[50]+l3[50])
    
    
# v2
def generalized(brick_length,total_length):
    mem = list(range(1,brick_length+1))
    for x in range(total_length-brick_length*2+1):
        mem = mem[1:]+[mem[0]+mem[-1]+1]
    return mem[-1]

def version2():
    print(generalized(2,50)+generalized(3,50)+generalized(4,50))

version2()
