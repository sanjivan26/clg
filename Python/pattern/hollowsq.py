n=5
for i in range(-(int(n/2)),(int(n/2)+1)):
    for j in range(1,n+1):
        if (j==1+abs(i) or n-j==1+abs(i)):
            print("  ",end="")
        else:
            print(j," ",end="")   
    print("\n")        