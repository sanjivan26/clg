x=int(input("Enter the numbers"))
y=int(input())
for i in range(y,0,-1):
    if x%i==0 and y%i==0:
        print("The gcd is ",i)
        break
    