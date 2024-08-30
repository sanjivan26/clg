n=int(input("Enter value for n"))
for l in range(-1*n,n+1):
    if l==0 or l==(-1):
        continue
    i=abs(l)
    a=1    
    for k in range(n-i):
        print(" ",end="")
    for j in range(1,i+1):
        print(a,end=" ")
        a+=1
    print("\n")