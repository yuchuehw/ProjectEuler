def minimize_smallest(money:tuple,options:tuple,found:set):
    for i, option in enumerate(options):
        if i==0:
            continue
        if money[0] >= option:
            copy_ = list(money)
            copy_[0] -= option
            copy_[i]+=1
            new_money = (*copy_,)
            if new_money not in found:
                found.add(new_money)
                minimize_smallest(new_money,options,found)

START = (200,)+(0,)*7
OPTIONS = (1,2,5,10,20,50,100,200)
found = {START}
minimize_smallest(START,OPTIONS,found)
print(len(found))
