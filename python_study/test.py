import itertools

a = [1,1,1,2,3,4]

b = list(set(itertools.permutations(a)))
b = list(map(list,b))
print(b)