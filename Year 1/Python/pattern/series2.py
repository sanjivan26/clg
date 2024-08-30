n=int(input("Enter value for n"))
for l in range(-1*n,n):
    i=abs(l)
    a=1
    if i==0 or i==(-1):
        continue
    for k in range(n-i):
        print(" ",end="")
    for j in range(1,i+1):
        print(a,end=" ")
        a+=1
    print("\n")