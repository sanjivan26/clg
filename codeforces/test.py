def bincheck(x):
    for i in x:
        if i not in [0,1]:
            return 0
    return 1
print(bincheck(list(11)))