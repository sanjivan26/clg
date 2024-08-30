n=int(input("Enter rows"))

for i in range(n+1):
#iterrates row no
    for k in range(1,n-i+1):
        print(" ",end="")
    for j in range(i+1):
       
       #iterrates clmn no
        if j==0 or j==i:
            a=1
            print(a,end=" ")   
        else: 
            a=int(a*(i-j+1)/j)           
            print(a,end=" ")
    print("\n")
