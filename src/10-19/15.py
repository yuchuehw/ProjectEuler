from functools import cache
WIDTH = 20
HEIGHT = 20

@cache
def lattice_path(x,y,width,height):
    if x==width and y==height:
        return 1
    if x >width or y>height:
        return 0
    return lattice_path(x+1,y,width,height)+lattice_path(x,y+1,width,height)


print(lattice_path(0,0,WIDTH,HEIGHT)) # 137846528820
