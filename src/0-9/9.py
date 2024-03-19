print([a*b*((a*a+b*b)**0.5)for a in range(1,1000) for b in range(1,1000) if ((a*a+b*b)**0.5) == int(((a*a+b*b)**0.5)) and ((a*a+b*b)**0.5)+a+b==1000][0])
