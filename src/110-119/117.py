from functools import cache
def find_pattern():
    @cache
    def dfs(target,path):
        if target < 0:
            return set()
        if target == 0:
            return {path}
        return dfs(target-1,path+(1,))|dfs(target-2,path+(2,))|dfs(target-3,path+(3,))|dfs(target-4,path+(4,))
    
    for i in range(20):
        print(len(dfs(i,())))
def main():
    l = [1,1,2,4,8]
    while len(l) <51:
        l.append(sum(l[-4:]))
    print(l[-1])

main()
