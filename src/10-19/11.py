import q11in, numpy, operator, functools


def max_group_of_n(list_: list, n: int):
    max_ = -1
    for i in range(len(list_) - n):
        max_ = max(max_, functools.reduce(operator.mul, list_[i : i + n], 1))
    return max_


GROUP_SIZE = 4
grid = numpy.array(
    [[int(n) for n in l.split(" ")] for l in q11in.grid_string.split("\n")]
)
max_ = -1

for x in range(len(grid)):
    max_ = max(max_, max_group_of_n(grid[x], GROUP_SIZE))

for x in range(len(grid[0])):
    max_ = max(max_, max_group_of_n(grid[:, x], GROUP_SIZE))

for x in range(-len(grid) + 1, len(grid[0])):
    max_ = max(max_, max_group_of_n(grid.diagonal(x), GROUP_SIZE))
    max_ = max(max_, max_group_of_n(grid[:,::-1].diagonal(x), GROUP_SIZE))

print(max_)  # 70600674
