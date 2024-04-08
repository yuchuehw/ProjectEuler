print(len([1 for x in range(1,100) for y in range(1,100) if len(str(x**y))==y]))
