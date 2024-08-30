n=int(input("Enter a value for n"))
for i in range(-1*(n-1),n):
    for j in range(abs(i)):
        print("  ",end="")
    for k in range(n-abs(i)):
        print(n-abs(i)," ",end=("")) 
    print("\n")       
