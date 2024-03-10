l = "A","ABILITY","ABLE","ABOUT","ABOVE","ABSENCE","ABSOLUTELY","ACADEMIC",...
t = [0.5*i*(i+1)for i in range(1,50)]
m = [sum(ord(c)-ord("A")+1 for c in i) in t for i in l]
print(sum(m))
