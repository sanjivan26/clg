for i in input():
    if i in "vwxyzVWXYZ":
        print(chr(ord(i)-21),end="")
    elif i ==" ":
        print(" ",end="")
    else:
        print(chr(ord(i)+5),end="")