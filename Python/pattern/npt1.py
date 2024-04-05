n=int(input("Enter rows"))
a=1
for i in range(1,n+1):
    for j in range(i):
        print(a," ",end="")
        a+=1
    print("\n")
