def left(x):
    if(x==1):
        return 1
    else:
        return (left(x//2)*10+x%2)
print(left(int(input())))    